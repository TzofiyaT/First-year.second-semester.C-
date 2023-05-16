#pragma once
class Polygon
{
	int numSides;
	int* sides;
public:
	int get_numSides();
	void set_numSides(int);
	void set_Sides(int, int);
	Polygon(const Polygon&temp);
	Polygon(int);
	void print_sides();
	~Polygon(void);
	int Scope();
	bool operator==(Polygon &a);
};
