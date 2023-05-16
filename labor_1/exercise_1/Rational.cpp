#include "Rational.h"
#include <iostream>
using namespace std;


Rational::Rational(int x, int y)
{
	mone = x;
	if (y != 0)
		mechane = y;
	else
		mechane = 1;
}

void Rational::setmechane(int y)
{
	//int num;
	//cin >> num;
	mechane = y;
}

void Rational::setmone(int x)
{
//	int num;
//	cin >> num;
	mone = x;
}

int Rational::getmechane()
{
	return mechane;
}

int Rational::getmone()
{
	return mone;
}

void Rational::print()
{
	cout << mone << "/" << mechane<<" ";
}

void Rational::reduction()
{
	bool mone1 = false;
	bool mechane1 = false;
	if (mechane < 0)
	{
		mechane *= -1;
		mechane1 = true;
	}
	if (mone < 0)
	{
		mone *= -1;
		mone1 = true;
	}
	int numMax=0;
	if (mone < mechane)
		numMax = mone;
	else
		numMax = mechane;
	for (int i = numMax; i >1; i--)
	{
		if ((mone%i == 0) && (mechane%i == 0))
		{
			mone /= i;
			mechane /= i;
			i++;
		}
	}
	if (mechane1 == true)
		mechane *= -1;
	if (mone1 == true)
		mone *= -1;
}

bool Rational::equal(Rational & g)
{
		g.reduction();
		reduction();
		if (g.mone == mone && g.mechane == mechane)
			return true;
		else
			return false;
}