#include <iostream>
using namespace std;
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"

int main()
{
	cout << "enter number of sides for polygon 1:\n";
	int side_1;
	cin >> side_1;
	Polygon Metsula_1(side_1);          
	if (side_1 == 3 || side_1 == 4)           
	{
		if (side_1 == 3)                 
		{
			cout << "enter sides for polygon:\n";
			int a, b, c;
			cin >> a >> b >> c;
			Triangle Mshulash_1(a, b, c);       
			cout << "enter number of sides for polygon 2:\n";
			int size_2;
			cin >> size_2;
			if (size_2 == side_1)              
			{
				int a, b, c;
				cout << "enter sides for polygon:\n";
				cin >> a >> b >> c;
				Triangle Mshulash_2(a, b, c);      
				if (Mshulash_2 == Mshulash_1)      
				{
					cout << "equal\n";
				}
				else
				{
					cout << "not equal\n";
				}
			}
			else
			{
				cout << "not equal\n";
			}
		}
		if (side_1 == 4)                                  
		{
			cout << "enter sides for polygon:\n";
			int a, b;
			cin >> a >> b;             
			Rectangle Malben_1(a, b);    
			cout << "enter number of sides for polygon 2:\n";
			int size_2;
			cin >> size_2;
			if (size_2 == side_1)          
			{
				int a, b;
				cout << "enter sides for polygon:\n";
				cin >> a >> b;
				Rectangle Malben_2(a, b);  
				if (Malben_2 == Malben_1)   
				{
					cout << "equal\n";
				}
				else
				{
					cout << "not equal\n";
				}
			}
			else
			{
				cout << "not equal\n";
			}
		}
	}
	else   
	{
		cout << "enter number of sides for polygon 2:\n";
		int size_2;
		cin >> size_2;
		Polygon Metsula_2(size_2);   
		if (Metsula_2 == Metsula_1)    
		{
			cout << "equal\n";
		}
		else
		{
			cout << "not equal\n";
		}
	}
	return 0;
}

//enter number of sides for polygon 1:
//4
//enter sides for polygon:
//33 22
//enter number of sides for polygon 2:
//4
//enter sides for polygon:
//33 66
//not equal

//enter number of sides for polygon 1:
//6
//enter sides for polygon:
//1 2 3 4 5 6
//enter number of sides for polygon 2:
//6
//enter sides for polygon:
//1 2 3 4 5 6
//equal
