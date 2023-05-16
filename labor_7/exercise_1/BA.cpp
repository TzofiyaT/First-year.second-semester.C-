#include "BA.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

BA::BA(int id, char* f_name, char* L_name, int num_courses, int*arr) :Student(id, f_name, L_name, num_courses)
{
	grades = new int[num_courses];
	for (int i = 0; i < num_courses; i++)
	{
		grades[i] = arr[i];
	}
	this->grades_size = num_courses;
}

void BA::print()
{
	cout << "ID: " << this->get_id() << endl;
	cout << "first name: " << this->get_f_name() << endl;
	cout << "last name: " << this->get_L_name() << endl;
	cout << "num courses: " << this->get_num_courses() << endl;
	cout << "grades: ";
	for (int i = 0; i < this->get_num_courses(); i++)
	{
		cout << grades[i] << " ";
	}
	cout << endl;
}

void BA::set_grades(int n)
{
	for (int i = 0; i < this->get_num_courses(); i++)
	{
		grades[i] = n;
	}
}

int BA::get_grades(int index)
{
	return grades[index];
}

double BA::average()
{
	int sum = 0;
	double average;
	for (int i = 0; i < this->get_num_courses(); i++)
	{
		sum += grades[i];
	}
	average = sum / get_num_courses();
	return average;
}

bool BA::milga()
{
	if (this->get_num_courses() >= 10 && this->average()>95)
	{
		return true;
	}
	return false;
}

BA::~BA(void)
{
	delete[]grades;
}