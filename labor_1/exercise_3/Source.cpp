#include "point.h"
#include <iostream>
using namespace std;
const int pi = 3.14;
int main()
{
	point A;
	point B;
	point C;
	int valueX = 0;
	int valueY = 0;
	int valueR = 0;
	int yesA = 0;
	int yesB = 0;
	int yesC = 0;
	int x;
	int y;
	int stop = 1;
	cout << "enter the center point and radius of 3 circles" << endl;
	cin >> valueX;
	cin >> valueY;
	cin >> valueR;
	A.setcenterX(valueX);
    A.setcenterY(valueY);
	A.setR(valueR);
	cin >> valueX;
	cin >> valueY;
	cin >> valueR;
	B.setcenterX(valueX);
	B.setcenterY(valueY);
	B.setR(valueR);
	cin >> valueX;
	cin >> valueY;
	cin >> valueR;
	C.setcenterX(valueX);
	C.setcenterY(valueY);
	C.setR(valueR);
	cout << "area A:" << A.area() << " B:" << B.area() << " C:" << C.area() << endl;
	cout << "hekef A:" << A.scope() << " B:" << B.scope() << " C:" << C.scope() << endl;
	while (stop!=0)
	{
		cin >> x;
		cin >> y;
		if (x==0 && y==0)
		{
			stop = 0;
			break;
		}
		if (A.check(x, y) != 1)
			yesA++;
		if (B.check(x, y) != 1)
			yesB++;
		if (C.check(x, y) != 1)
			yesC++;
	}
	cout << "num of points in circle  A:" << yesA << " B:" << yesB << " C:" << yesC << endl;
}

