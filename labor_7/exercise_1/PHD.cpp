#include "PHD.h"
#include <iostream>
#include <string>
using namespace std;
#include "Student.h"

PHD::PHD(int id, char* f_name, char* L_name, int num_courses, int week_hours) :Student(id, f_name, L_name, num_courses)
{
	this->week_hours = week_hours;
}

void PHD::print()
{
	cout << "ID: " << this->get_id() << endl;
	cout << "first name: " << this->get_f_name() << endl;
	cout << "last name: " << this->get_L_name() << endl;
	cout << "num courses: " << this->get_num_courses() << endl;
	cout << "hours: " << this->week_hours << endl;
}

bool PHD::milga()
{
	if (this->get_num_courses() == 2 && this->week_hours >= 25)
	{
		return true;
	}
	return false;
}

PHD::~PHD(void)
{
}