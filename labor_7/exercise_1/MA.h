#pragma once
#include <iostream>
#include <string>
#include "Student.h"
#include "BA.h"
using namespace std;

class MA :public BA   
{
	bool research;
public:
	virtual void print();
	virtual bool milga();
	MA(int, char*, char*, int, int*, bool research);
	~MA(void);
};