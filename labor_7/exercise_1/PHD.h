#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Student.h"

class PHD :public Student  
{
	int week_hours;
public:
	virtual bool milga();
	virtual void print();
	PHD(int, char*, char*, int, int);
	~PHD(void);
};
