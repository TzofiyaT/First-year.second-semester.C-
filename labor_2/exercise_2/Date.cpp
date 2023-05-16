#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int d, int m, int y) : day(d), month(m), year(y)   //c-tor
{
	if (d<1 || d>30)
	{
		cout << "Error day\n"; day = 1;
	}
	if (m<1 || m>12)
	{
		cout << "Error month\n"; month = 1;
	}
	if (y<1970 || m>2099)
	{
		cout << "Error year\n"; year = 1970;
	}
}

Date::Date(const Date&Temp)        //copy c-tor
{
	this->day = Temp.day;
	this->month = Temp.month;
	this->year = Temp.year;
}

int Date::get_day()
{
	return day;
}

int Date::get_month()
{
	return month;
}

int Date::get_year()
{
	return year;
}

void Date::setDate(int d, int m, int y)
{
	if (d<1 || d>30 || m<1 || m>12 || y<1970 || m>2099)
	{

	}
	else
	{
		day = d;  month = m;  year = y;
	}

}

void Date::print()
{
	cout << day << "/" << month << "/" << year << endl;
}

Date Date::operator++(int x)
{
	Date Temp(day, month, year);
	if (day == 30)
	{
		if (month == 12)
		{
			day = 1; month = 1; year++;
		}
		else
		{
			day = 1; month++;
		}
	}
	else
	{
		day++;
	}
	return Temp;
}

Date Date::operator++()
{
	if (day == 30)
	{
		if (month == 12)
		{
			day = 1; month = 1; year++;
		}
		else
		{
			day = 1; month++;
		}
	}
	else
	{
		day++;
	}
	return *this;
}

void Date::operator+=(int days)
{
	if (day + days>30)
	{
		if (((month - 1) * 30 + day + days) / 360>0)
		{
			year += (month * 30 + day + days) / 360;
		}
		if ((month + (day + days) / 30)>12)
		{
			if ((day + days) / 30<12)
			{
				month = month + ((day + days) / 30) - 12;
			}
			else
			{
				month = ((day + days) / 30) / 12;
			}
		}
		else
		{
			month++;
		}
		day = (day + days) % 30;
	}
	else
	{
		day += days;
	}
}

bool Date::operator==(Date &a)
{
	if (day == a.get_day() && month == a.get_month() && year == a.get_year())
	{
		return true;
	}
	return false;
}

bool Date::operator>(Date &a)
{
	if (year>a.get_year())
	{
		return true;
	}
	if (year<a.get_year())
	{
		return false;
	}
	if (year == a.get_year())
	{
		if (month>a.get_month())
		{
			return true;
		}
		if (month<a.get_month())
		{
			return false;
		}
		if (month == a.get_month())
		{
			if (day>a.get_day())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Date::operator<(Date &a)
{
	a.print(); cout << endl;
	if (year<a.get_year())
	{
		return true;
	}
	return false;
}

//Date Date::operator>(Date days)
//{
//
//
//}

Date::~Date(void)
{
}