#include <iostream>
#include <cstring>
#include "Rational.h"
using namespace std;
int main()
{
	cout << "enter two rational numbers" << endl;
	int a, b, c, d;                // a is the first mone, b is the first mechane, c is the second mone, d is the second mechane. 
	char g;                     // for the separator line ('/')
	bool i;
	// create 2 rational objects
	cout << "a:"; cin >> a >> g >> b;
	cout << "b:"; cin >> c >> g >> d;
	if (b == 0 || d == 0)
	{
		cout << "ERROR\n";
	}
	Rational A(a, b), B(c, d);
	cout << "b-a: "; (B - A).print(); cout << endl;
	bool x = false;
	x = (A != B);
	if (x)
	{
		cout << "a!=b: true" << endl;
	}
	else
	{
		cout << "a!=b: false" << endl;
	}
	x = (A<B);
	if (x)
	{
		cout << "a<b: true" << endl;
	}
	else
	{
		cout << "a<b: false" << endl;
	}
	x = (A>B);
	if (x)
	{
		cout << "a>b: true" << endl;
	}
	else
	{
		cout << "a>b: false" << endl;
	}
	x = (A >= B);
	if (x)
	{
		cout << "a>=b: true" << endl;
	}
	else
	{
		cout << "a>=b: false" << endl;
	}
	cout << "a++: "; A++.print(); cout << endl;
	cout << "--a: "; (--A).print(); cout << endl;
	cout << "a--: "; (A--).print(); cout << endl;
	B = A;
	//cout<< "now A is:";A.print(); cout<<"   now B is:"; B.print(); cout<<endl;
	cout << "b-a: "; (B - A).print(); cout << endl;
	cout << "b/a: "; (B / A).print(); cout << endl;
	x = (A != B);
	if (x)
	{
		cout << "a!=b: true" << endl;
	}
	else
	{
		cout << "a!=b: false" << endl;
	}
	x = (A<B);
	if (x)
	{
		cout << "a<b: true" << endl;
	}
	else
	{
		cout << "a<b: false" << endl;
	}
	x = (A >= B);
	if (x)
	{
		cout << "a>=b: true" << endl;
	}
	else
	{
		cout << "a>=b: false" << endl;
	}
	//  system("pause");
	return 0;
}
