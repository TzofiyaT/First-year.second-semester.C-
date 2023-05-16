#include <iostream>
#include "Date.h"
using namespace std;
int main()
{
	cout << "Enter a date\n";
	int day;
	int month;
	int year;
	char slash;
	int choice = 0;
	int numberDyas;
	bool x = false;
	Date B;
	cin >> day >> slash >> month >> slash >> year;
	Date A(day, month, year);
	A.print();
	do
	{
		cout << "What do you want to do\n";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Enter a date\n";
			cin >> day >> slash >> month >> slash >> year;
			A.setDate(day, month, year);
			A.print();
			break;
		case 2:
			(++A).print();
			break;
		case 3:
			(A++).print();
			break;
		case 4: cout << "Enter#days\n";
			cin >> numberDyas;
			A += numberDyas;
			A.print();
			break;
		case 5: cout << "Enter a date\n";
			cin >> day >> slash >> month >> slash >> year;
			B.setDate(day, month, year);
			x = (A>B);
			if (x)       // if the first date  is later then the new date
			{
				cout << ">:true\n";
			}
			else            // if the first date  is earlyer then the new date
			{
				cout << ">:false\n";
			}
			break;
		case 6: cout << "Enter a date\n";
			x = (A<B);
			if (x)          // if the first date  is earlyer then the new date
			{
				cout << "<:true\n";
			}
			else           // if the first date  is later then the new date
			{
				cout << "<:false\n";
			}
			break;
		case 7: cout << "Enter a date\n";
			cin >> day >> slash >> month >> slash >> year;
			B.setDate(day, month, year);
			x = (A == B);
			if (x)        // if the both dates are equals
			{
				cout << "==:true\n";
			}
			else
			{
				cout << "==:false\n";     // if the both dates are not equals
			}
			break;
		default:
			break;
		}
	} while (choice != -1);
	return 0;
}

//Enter a date
//-5/1/2010
//Error day
//1/1/2010
//What do you want to do
//1
//Enter a date
//6/1/2000
//6/1/2000
//What do you want to do
//2
//7/1/2000
//What do you want to do
//3
//7/1/2000
//What do you want to do
//4
//Enter#days
//30
//8/2/2000
//What do you want to do
//5
//Enter a date
//8/2/2001
//>:false
//What do you want to do
//7
//Enter a date
//8/2/2000
//==:true
//What do you want to do
