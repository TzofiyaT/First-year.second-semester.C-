#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Student.h"
#include "BA.h"
#include "MA.h"
#include "PHD.h"

void print_milga(vector<Student*> studentim)
{
	for (int i = 0; i < 7; i++)
	{
		if (studentim[i]->milga())                         
		{                                                 
			studentim[i]->print();
		}
	}
}

int main()
{
	int arr1[3] = { 90, 100, 90 };                                         
	int arr2[10] = { 100, 100, 90, 100, 90, 100, 90, 100, 90, 100 };      
	int arr3[7] = { 90, 100, 90, 100, 90, 100, 90 };                       
	vector<Student*> studentim;                                         
	studentim.push_back(new BA(123, "abe", "avraham", 3, arr1));            
	studentim.push_back(new BA(234, "yitzhak", "avrahamson", 10, arr2));     
	studentim.push_back(new MA(345, "yaacov", "jacobson", 7, arr3, 0));   
	studentim.push_back(new MA(456, "sara", "emanu", 7, arr3, 1));        
	studentim.push_back(new PHD(567, "rivka", "imanu", 1, 30));           
	studentim.push_back(new PHD(678, "jacobs", "rachel", 2, 20));         
	studentim.push_back(new PHD(789, "leah", "jacobs", 2, 30));           
	print_milga(studentim);
	for (int i = 0; i < 7; i++)
	{
		delete studentim[i];                                      
	}
	return 0;
}

//ID: 234
//first name: yitzhak
//last name: avrahamson
//num courses: 10
//grades: 100 100 90 100 90 100 90 100 90 100
//ID: 456
//first name: sara
//last name: emanu
//num courses: 7
//grades: 90 100 90 100 90 100 90
//research: yes
//ID: 789
//first name: leah
//last name: jacobs
//num courses: 2
//hours: 30
//Press any key to continue . . .
