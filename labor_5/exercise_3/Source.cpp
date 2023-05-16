#include <iostream>
#include "List.h"
using namespace std;
List makeSet(List);
List reverse1(List);
List merge(List&, List&);
int main()
{
	List lst1, lst2, mergedList;
    cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;
	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;
	mergedList = makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;
	return 0;
}

//enter sorted values for the first list:
//1 2 56 4
//enter sorted values for the second list:
//2 3 5 6 4 7 1 0
//the new merged list: 1 2 2 3 5 6 56
//the new merged set: 1 2 3 5 6 56
//Press any key to continue . . .
