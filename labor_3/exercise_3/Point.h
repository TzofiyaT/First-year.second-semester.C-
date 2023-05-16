#pragma once
class Point
{
	int x;     // x cordinate of the point
	int y;     // y cordinate of the point
public:
	void set_x(int);
	int get_x();
	void set_y(int);
	int get_y();
	void printPoint();
	double distance(Point);
	Point(void);
	~Point(void);
};