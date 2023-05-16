#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student(int id, char* f_name, char* L_name, int num_courses)
{
	this->id = id;
	this->f_name = f_name;
	this->L_name = L_name;
	this->num_courses = num_courses;
}

int Student::get_id()
{
	return id;
}

char* Student::get_f_name()
{
	return f_name;
}

char* Student::get_L_name()
{
	return L_name;
}

int Student::get_num_courses()
{
	return num_courses;
}

Student::~Student(void)
{
}