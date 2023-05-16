#include "Polyonal.h"
#include <iostream>
using namespace std;

Polyonal::Polyonal(int n)  // n is the number of kodkodim that user wont
{
	this->kodkod_nam = 0;
	//cout<<"c=tor on\n";
	this->kodkod = new Point[n];   //creayte array for the kodkodim
}

Polyonal::Polyonal(const Polyonal&Temp)    //copy c-tor    
{
	this->kodkod_nam = Temp.kodkod_nam;
	for (int i = 0; i<kodkod_nam; i++)
	{
		kodkod[i] = Temp.kodkod[i];
	}
}

void Polyonal::set_kodkod_nam(int n)
{
	this->kodkod_nam = n;
}

int Polyonal::get_kodkod_nam()   // important to know the num of kodkodim to clculate the Scope of Polygonal
{
	return kodkod_nam;
}

void Polyonal::set_kodkod(Point A)    // to enter point to the kodkodim array
{
	kodkod[kodkod_nam] = A;
	kodkod_nam++;                     // update the num of kodkodim
}

Point Polyonal::get_kodkod(int i)    // get kodkodim for clculate the distance between them
{
	return kodkod[i];
}

Polyonal::~Polyonal(void)
{
}