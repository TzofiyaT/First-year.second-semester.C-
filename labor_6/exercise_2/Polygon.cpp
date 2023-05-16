#include "Polygon.h"
#include <iostream>
using namespace std;

Polygon::Polygon(int numSides)
{
	this->numSides = numSides;
	sides = new int[numSides];    
	if (numSides>4)
	{
		cout << "enter sides for polygon:\n";
		int value;
		for (int i = 0; i < numSides; i++)
		{
			cin >> value;              
			sides[i] = value;
		}
	}
}

Polygon::Polygon(const Polygon&Temp)        
{
	this->numSides = Temp.numSides;
	for (int i = 0; i < numSides; i++)
	{
		sides[i] = Temp.sides[i];
	}
}

int Polygon::get_numSides()
{
	return numSides;
}

void Polygon::set_numSides(int a)
{
	this->numSides = a;
}

void Polygon::set_Sides(int value, int index)  
{
	sides[index] = value;
}

void Polygon::print_sides()    
{
	cout << "the side are: ";
	for (int i = 0; i < numSides; i++)
	{
		cout << sides[i] << " ";
	}
	cout << endl;
}

int Polygon::Scope()          
{
	int sum_sides = 0;
	for (int i = 0; i < numSides; i++)
	{
		sum_sides += sides[i];
	}
	return sum_sides;
}

bool Polygon::operator==(Polygon& a)
{
	if (numSides != a.numSides)
		return false;
	return(this->Scope() == a.Scope());           
}

Polygon::~Polygon(void)
{
	if (sides)
	{
		delete[]sides;
	}
}