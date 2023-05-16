#include "Rational.h"
#include <iostream>

using namespace std;
Rational::Rational(int x = 1, int y = 1)
{
	if (y != 0)
	{
		this->d = x; this->n = y;
	}
	if (y == 0)
	{
		this->d = x; this->n = 1;
	}
}

Rational::Rational()
{
	d = 1; n = 1;
}

void Rational::set_d(int c) { d = c; }
int Rational::get_d() { return d; }
void Rational::set_n(int c) { n = c; }
int Rational::get_n() { return n; }

Rational::~Rational()
{
}


bool Rational::equal(float a, float b, float c, float d)
{
	if (a / c == b / d)             // if its the same number (mone/mone = mechane/mechane).
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Rational::help(int x, int y)
{
	if (x*y>0 || x>0)    // minimize pozitive rational number (and allso negative only in case: mechane negative) 
	{
		int i = 1;
		while (i <= x)
		{
			if (x%i == 0)  // if the mone divided in this num (i)......
			{
				if (y%i == 0)    // so chack..  if the mechane allso divided in this num (i)   so we can minimize the nember.
				{
					x /= i; y /= i;     // so  minimize the nember by dividing in this (i).
				}
			}
			i++;
		}
		d = x; n = y;    // now update the valuse of tje numbers in the class.  
	}
	if (x<0)        // minimize negative rational number  only in case: mone negative)
	{
		int i = -1;
		while (i >= x)
		{
			if (x%i == 0)  // if the mone divided in this num (i)......
			{
				if (y%i == 0)    // so chack..  if the mechane allso divided in this num (i)   so we can minimize the nember.
				{
					x /= i; y /= i;     // so  minimize the nember by dividing in this (i).
				}
			}
			i--;
		}
		d = x; n = y;    // now update the valuse of tje numbers in the class.  
	}
}

Rational Rational::operator+(Rational &a)
{
	int d2 = d * a.get_n() + n*a.get_d();
	int n2 = n*a.get_n();

	Rational Temp(d2, n2);
	return Temp;
}

Rational Rational::operator-(Rational &a)
{
	int d2 = d * a.get_n() - n*a.get_d();
	int n2 = n*a.get_n();

	Rational Temp(d2, n2);
	return Temp;
}

Rational Rational::operator/(Rational &a)
{
	int d2 = d * a.get_n();
	int n2 = n*a.get_d();
	Rational Temp(d2, n2);
	return Temp;
}

bool Rational::operator>(Rational &a)
{
	if (d*n>0 && a.get_d()*a.get_n()>0)      // if the tow rationwl numbers are positive: (mone(a)*mechane(a)>0 and mone(b)*mechane(b)>0)
	{
		if (d*a.get_n()>n*a.get_d())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (d*n<0 && a.get_d()*a.get_n()<0)       // if the tow rationwl numbers are negative (mone*moen<0 and mechane*mechane<0)
	{
		if (d*a.get_n()>n*a.get_d())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (d*n>0 && a.get_d()*a.get_n()<0)
	{
		return true;
	}
	if (d*n<0 && a.get_d()*a.get_n()>0)
	{
		return false;
	}

}

bool Rational::operator>=(Rational &a)
{
	if (d*a.get_n() == n*a.get_d())      // if the tow rationwl numbers are equal:(mone(a)*mechane(b)=mone(b)*mechane(a))
	{
		return true;
	}
	if (d*n>0 && a.get_d()*a.get_n()>0)      // if the tow rationwl numbers are positive: (mone(a)*mechane(a)>0 and mone(b)*mechane(b)>0)
	{
		if (d*a.get_n()>n*a.get_d())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (d*n<0 && a.get_d()*a.get_n()<0)       // if the tow rationwl numbers are negative (mone*moen<0 and mechane*mechane<0)
	{
		if (d*a.get_n()>n*a.get_d())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (d*n>0 && a.get_d()*a.get_n()<0)
	{
		return true;
	}
	if (d*n<0 && a.get_d()*a.get_n()>0)
	{
		return false;
	}
}

bool Rational::operator<(Rational &a)
{
	if (d*n>0 && a.get_d()*a.get_n()>0)      // if the tow rationwl numbers are positive (mone*moen>0 and mechane*mechane>0)
	{
		if (d*a.get_n()<n*a.get_d())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (d*n<0 && a.get_d()*a.get_n()<0)       // if the tow rationwl numbers are negative (mone*moen<0 and mechane*mechane<0)
	{
		if (d*a.get_n()<n*a.get_d())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (d*n>0 && a.get_d()*a.get_n()<0)
	{
		return false;
	}
	if (d*n<0 && a.get_d()*a.get_n()>0)
	{
		return true;
	}
}

bool Rational::operator!=(Rational &a)
{
	if (d*a.get_n() != n*a.get_d())             // if its the same number (mone/mone = mechane/mechane).
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Rational::print()
{
	help(d, n);
	if (d == n*-1)
	{
		cout << -1;
	}
	if (d == n)
	{
		cout << 1;
	}
	else
	{
		if (d != 0 && n != 1 && n != -1)   // if mone diffrent from 0 and mechane diffrent from 1
		{
			cout << d << "/" << n;
		}
		else
		{
			if (d == 0 || n == 1)
			{
				cout << d;
			}
			if (n == -1)
			{
				cout << d*-1;
			}
		}
	}
}

Rational Rational::operator++(int x)
{
	Rational Temp(d, n);
	d = d + n;   
	return Temp;
}

Rational Rational::operator--(int x)
{
	Rational Temp(d, n);
	d = d - n;
	return Temp;
}

Rational Rational::operator--()
{
	d = d - n;
	return *this;
}
