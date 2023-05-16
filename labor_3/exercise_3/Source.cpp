#include "Point.h"
#include "Polyonal.h"
#include <iostream>
using namespace std;

int main()
{
	int x, y;
	Point A;               //creayte Point
	int n;                 // the nym of the kodkodim
	cin >> n;
	Polyonal R(n);      // creayte the Polygonal (metsula) with the num of kodkodim (n)
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;                // get point from user
		A.set_x(x); A.set_y(y);    // enter point cordinates to class point
		R.set_kodkod(A);            // insert the points to the kodkodim array
	}
	int sum = 0;
	for (int i = 0; i < R.get_kodkod_nam(); i++)
	{
		if (i == R.get_kodkod_nam() - 1)                             // the distance between the last piont to the first point ....
		{
			sum += R.get_kodkod(0).distance(R.get_kodkod(i));      // ... R.get_kodkod(i) is the last point and R.get_kodkod(0) is the first point
		}
		else
		{
			sum += R.get_kodkod(i + 1).distance(R.get_kodkod(i));    //   add the distance between all points to the sum
		}
	}
	cout << sum << endl;    // print the result
							//system ("pause");
	return 0;
}

//4
//2 1 5 8 6 4 2 5
//19
