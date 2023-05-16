#include "Point.h"
#include <cmath>
#include <iostream>
using namespace std;

Point::Point(void)
{
}

void Point::set_x(int x)
{
	this->x = x;
}

int Point::get_x()
{
	return x;
}

void Point::set_y(int y)
{
	this->y = y;
}

int Point::get_y()
{
	return y;
}

// function to return distance between two points
double Point::distance(Point p)
{
	return sqrt(pow(x - p.x, 2.0) + pow(y - p.y, 2.0));
}

void Point::printPoint()   // to print the point
{
	cout << "(" << x << "," << y << ")" << " ";
}

Point::~Point(void)   // distructor
{
}
