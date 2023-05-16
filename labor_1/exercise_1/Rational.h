#pragma once
class Rational
{
	int mechane;
	int mone;
public:
	Rational(int x=0, int y=0);
	void  print();
	void setmechane(int y);
	void setmone(int x);
	int getmechane();
	int getmone();
	void reduction();
	bool equal(Rational &);
};
