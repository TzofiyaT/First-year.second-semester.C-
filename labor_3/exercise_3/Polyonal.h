#pragma once
#include "Point.h"

class Polyonal
{
	int kodkod_nam;
	Point* kodkod;
public:
	void set_kodkod(Point);
	void set_kodkod_nam(int);
	Point get_kodkod(int);
	int get_kodkod_nam();
	Polyonal(int);
	Polyonal(const Polyonal&Temp);
	~Polyonal(void);
};