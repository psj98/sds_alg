#include <iostream>

using namespace std;

class Time {
private:
	int hours;
	int mins;

public:
	Time();
	Time(int, int);
	~Time();
	Time operator+(Time&);
	void addHours(int);
	void addMins(int);
	void show();
};

int main() {
	Time day1(1, 40);
	Time day2(2, 30);
	
	day1.show();
	day2.show();

	Time total;
	total = day1.operator+(day2);
	total.show();

	return 0;
}

Time::Time() {
	hours = mins = 0;
}

Time::Time(int h, int m) {
	hours = h;
	mins = m;
}

void Time::addHours(int h) {
	hours += h;
};

void Time::addMins(int m) {
	mins += m;
	hours += mins / 60;
	mins %= 60;
};

Time Time::operator+(Time& t) {
	Time sum;

	sum.mins = mins + t.mins;
	sum.hours = hours + t.hours;
	sum.hours += sum.mins / 60;
	sum.mins %= 60;

	return sum;
};

void Time::show() {
	printf("½Ã°£:ºÐ - %d:%d\n", hours, mins);
}

Time::~Time() {}