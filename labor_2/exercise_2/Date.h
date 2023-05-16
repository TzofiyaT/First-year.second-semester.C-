#pragma once
class Date
{
	int day;
	int month;
	int year;
public:
	Date(int d = 1, int m = 1, int y = 1970);  //c-tor
	Date(const Date&temp);  //copy c-tor
	void setDate(int, int, int);
	int get_day();
	int get_month();
	int get_year();
	void print();
	Date operator++();     // ++x;   fref
	Date operator++(int);  // x++;   after
	void operator+=(int);
	bool operator==(Date &a);
	bool operator>(Date &a);
	bool operator<(Date &a);
	~Date(void);
};