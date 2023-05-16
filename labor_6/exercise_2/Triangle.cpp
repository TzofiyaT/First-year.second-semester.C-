#include "Triangle.h"

Triangle::Triangle(int a, int b, int c) :Polygon(3)  // use base class constructor
{
	this->set_Sides(a, 0);
	this->set_Sides(b, 1);
	this->set_Sides(c, 2);
}

Triangle::~Triangle(void)
{
}
