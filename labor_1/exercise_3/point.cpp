#include "point.h"
#include <iostream>
#include <cmath>
const double pi = 3.14;
point::point(int r, int a, int b)
{
	centerX = a;
	centerY = b;
	R = r;
}
void point::setcenterX(int num)
{
	centerX = num;
}
void point::setcenterY(int num)
{
	centerY = num;
}
void point::setR(int num)
{
	R = num;
}
int point::getcenterX()
{
	return centerX;
}
int point::getcenterY()
{
	return centerY;
}
int point::getR()
{
	return R;
}
float point::area()
{
	return pi*R*R;
}
float point::scope()
{
	return 2 * pi*R;
}
int point::check(int x, int y)
{
	float Xpow = pow((centerX - x), 2);
	float Ypow = pow((centerY - y), 2);
	if (sqrt(Xpow + Ypow) < R)
		return -1;
	else if (sqrt(Xpow + Ypow) > R)
		return 1;
	else if (sqrt(Xpow + Ypow) == R)
		return 0;
}