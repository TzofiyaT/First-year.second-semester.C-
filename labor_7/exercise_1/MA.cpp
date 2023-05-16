#include "MA.h"
#include "BA.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

MA::MA(int id, char* f_name, char* L_name, int num_courses, int*arr, bool research) :BA(id, f_name, L_name, num_courses, arr)
{
	this->research = research;

}

void MA::print()
{
	cout << "ID: " << this->get_id() << endl;
	cout << "first name: " << this->get_f_name() << endl;
	cout << "last name: " << this->get_L_name() << endl;
	cout << "num courses: " << this->get_num_courses() << endl;
	cout << "grades: ";
	for (int i = 0; i < this->get_num_courses(); i++)
	{
		cout << get_grades(i) << " ";
	}
	cout << endl;
	cout << "research: ";
	if (this->research)    
	{
		cout << "yes" << endl;
	}
	else                   
	{
		cout << "no" << endl;
	}
}

bool MA::milga()
{
	if (this->get_num_courses() >= 7 && this->average()>90 && (this->research))
	{
		return true;
	}
	return false;
}

MA::~MA(void)
{
}