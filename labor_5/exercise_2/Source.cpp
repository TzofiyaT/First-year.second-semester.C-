#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List lst;
	int choice, val;
	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-2\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);
			break;
		case 2:cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (char * msg)
			{
				cout << msg << endl;
			}
			break;
		default:cout << "ERROR\n";
		}
		cout << lst << endl;
		cout << "choose 0-2\n";
		cin >> choice;
	}
	return 0;
}

//enter the list values
//2 4 6 8  10 10
//choose 0-2
//1
//enter a value to insert
//1
//1 2 4 6 8 10
//choose 0-2
//2
//enter a value to remove
//2
//1 4 6 8 10
//choose 0-2
//1
//enter a value to insert
//0
//0 1 4 6 8 10
//choose 0-2
//2
//enter a value to remove
//10
//0 1 4 6 8
//choose 0-2
