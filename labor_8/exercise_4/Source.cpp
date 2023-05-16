#include <string>
#include <iostream>
#include "SearchTree.h"
#include "Student.h"
using namespace std;
int main()
{
	SearchTree<Student> T1;
	char x;
	Student y;
	cout << "enter a-e:\n";
	cin >> x;
	while (x != 'e')
	{
		switch (x)
		{
		case 'a':cout << "enter a student ";
			cin >> y;
			T1.add(y);
			break;
		case 'b': cout << "enter a student ";
			cin >> y;
			T1.remove(y);
			break;
		case 'c':
			cout << "enter a student ";
			cin >> y;
			if (T1.search(y))
				cout << "exist" << endl;
			else
				cout << "not exist" << endl;
			break;
		case 'd': T1.inOrder();
			break;
		case 'e':break;
		default:
			cout << "error" << endl;
			break;
		}
		cout << "enter a-e:\n";
		cin >> x;
	}
	return 0;
}
