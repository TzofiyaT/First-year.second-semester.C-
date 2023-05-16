#pragma once
#include <string>

class Student      
{
	int id;
	char* f_name;
	char* L_name;
	int num_courses;
public:
	int get_id();
	char* get_f_name();
	char* get_L_name();
	int get_num_courses();
	Student(int, char*, char*, int);
	virtual void print() = 0;          
	virtual bool milga() = 0;
	~Student(void);
};
