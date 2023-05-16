#include "SearchTree.h"
#include "Tree.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	SearchTree<int> T1;
	cout << "enter 10 numbers\n";
	int x, y;
	for (int i = 0; i<10; i++)
	{
		cin >> x;
		T1.add(x);
	}
	cout << "inorder: ";
	T1.inOrder();
	cout << "\nenter 0-6:\n";
	cin >> x;
	while (x != 0)
	{
		switch (x)
		{
		case 1: cout << "# of leaves: " << T1.leaves() << endl;
			break;
		case 2: cout << "height of tree: " << T1.height() << endl;
			break;
		case 3:T1.reflect();
			cout << "reflected tree: ";
			T1.inOrder();
			T1.reflect();
			cout << endl;
			break;
		case 4: cout << "# left sons only: " << T1.onlyLeftSon() << endl;
			break;
		case 5: cout << "enter a number ";
			cin >> y;
			cout << "level of " << y << " on tree: " << T1.level(y) << endl;
			break;
		case 6: cout << "enter a number ";
			cin >> y;
			T1.remove(y);
			cout << "after removing " << y << ": ";
			T1.inOrder();
			cout << endl;
		}
		cout << "enter 0-6:\n";
		cin >> x;
	}
	return 0;
}

//enter 10 numbers
//1 2 5 2 3 6 5 2 1 4
//inorder: 1 1 2 2 2 3 4 5 5 6
//enter 0-6:
//2
//height of tree: 6
//enter 0-6:
//1
//# of leaves: 4
//enter 0-6:
//2
//height of tree: 6
//enter 0-6:
//5
//enter a number 1
//level of 1 on tree: 0
//enter 0-6:
//2
//height of tree: 6
//enter 0-6:
//5
//enter a number 4
//level of 4 on tree: 5
//enter 0-6:
