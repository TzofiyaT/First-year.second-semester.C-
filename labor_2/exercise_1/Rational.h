#pragma once
class Rational
{
private:
	int d;
	int n;
public:
	Rational();
	Rational(int x, int y);
	void set_d(int);
	int get_d();
	void set_n(int);
	int get_n();
	void help(int, int);
	bool equal(float a, float b, float c, float d);
	void print();
	Rational operator++(int);
	Rational operator--(int);
	Rational operator--();
	Rational operator+(Rational &a);
	Rational operator-(Rational &a);
	Rational operator/(Rational &a);
	bool operator>(Rational &a);
	bool operator>=(Rational &a);
	bool operator<(Rational &a);
	bool operator!=(Rational &a);

	~Rational();
};

