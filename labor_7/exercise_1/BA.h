#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Student.h"

class BA :public Student   // inherete fron Studet class
{
	int* grades;
	int grades_size;
public:
	void set_grades(int n);
	int get_grades(int index);
	double average();
	virtual void print();
	virtual bool milga();
	BA(int, char*, char*, int, int*);
	~BA(void);
};