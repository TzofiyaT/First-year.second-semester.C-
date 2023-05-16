#include <iostream>
#include <cstring>
#include "String1.h"
using namespace std;
int main()
{
	char str1[50];
	char str2[50];
	int n;
	cout << "Enter strins\n";
	int index;
	cin >> str1;
	cin >> str2;
	cin >> n;
	String A(str1);
	String B(str2);
	A>B;
	A<B;
	A = B;
	String C = B.insert(n, str1);
	if (n <= strlen(str1))
	{
		C.print_str();
	}
	//system("pause");
	return 0;
}

//Enter strins
//hello
//hello
//2
//a=b
//hehellollo

//Enter strins
//hello
//world
//3
//a<b
//worhellold
