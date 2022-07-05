#include <iostream>

using namespace std;

class Stock {
private:
	string name;
	int shares;
	float share_val;
	double total_val;
	void set_total() { total_val = shares * share_val; }

public:
	Stock(string, int, float);
	~Stock();
	void buy(int, float);
	void sell(int, float);
	void update(float);
	void show();
    Stock &topval(Stock&);
};

int main() {
    Stock s[4] = {
        Stock("A", 10, 1000),
        Stock("B", 20, 1200),
        Stock("C", 30, 1300),
        Stock("D", 25, 1100)
    };

    Stock *first = &s[0];
	for (int i = 1; i < 4; i++)
		first = &first->topval(s[i]);

	first->show();

    /*
	Stock s1("A", 10, 1000);
    Stock s2("B", 20, 1200);

	s1.show();
    s2.show();

    printf("주가가 더 큰 것은?\n");
    s1.topval(s2).show();
    */

	// s1.buy(10, 1200);
	// s1.show();
	// s1.sell(5, 800);
	// s1.show();

	return 0;
}

Stock::Stock(string co, int n, float pr) {
	name = co;
	shares = n;
	share_val = pr;
	set_total();
}

Stock::~Stock() {
	printf("%s 클래스가 소멸되었습니다.\n", name.c_str());
}

void Stock::buy(int n, float pr) {
	shares += n;
	share_val = pr;
	set_total();
}

void Stock::sell(int n, float pr) {
	shares -= n;
	share_val = pr;
	set_total();
}

void Stock::update(float pr) {
	share_val = pr;
	set_total();
}

void Stock::show() {
	printf("회사 명 : %s\n", name.c_str());
	printf("주식 수 : %d\n", shares);
	printf("주가 : %.1f\n", share_val);
	printf("주식 총 가치 : %.1lf\n\n", total_val);
}

Stock &Stock::topval(Stock& s) {
	if (s.share_val > share_val)
		return s;
	else return *this;
}