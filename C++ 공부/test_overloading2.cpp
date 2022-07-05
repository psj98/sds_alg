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
  void addHours(int);
  void addMins(int);
  int getHours();
  int getMins();
  void show();
  Time operator+(Time&);
};

int main() {
  Time t1(3, 20);
  Time t2(1, 45);

  t1.show();
  t2.show();

  Time total;
  
	total = t1.operator+(t2);
	total.show();
  
  return 0;
}

Time::Time(){
  hours = mins = 0;
}

Time::Time(int h, int m){
  hours = h;
  mins = m;
}

Time::~Time(){}

void Time::addHours(int h){
  hours += h;
}

void Time::addMins(int m){
  mins += m;
  hours += mins / 60;
  mins %= 60;
}

int Time::getHours(){
  return hours;
}

int Time::getMins(){
  return mins;
}

void Time::show(){
  printf("hh:mm - %d:%d\n", hours, mins);
}

Time Time::operator+(Time& t){
  Time sum;

  sum.mins = mins + t.mins;
	sum.hours = hours + t.hours;
	sum.hours += sum.mins / 60;
	sum.mins %= 60;

	return sum;
}