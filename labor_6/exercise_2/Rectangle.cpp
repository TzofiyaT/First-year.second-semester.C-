#include "Rectangle.h"

Rectangle::Rectangle(int a, int b) :Polygon(4)
{
	this->set_Sides(a, 0);
	this->set_Sides(b, 1);
	this->set_Sides(a, 2);
	this->set_Sides(b, 3);
}

Rectangle::~Rectangle(void)
{
}
