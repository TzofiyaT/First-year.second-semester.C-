#include "worker.h"
#include <iostream>
#include <cstring>
using namespace std;


worker::worker(int Id, char Name[], float Salary, int Hour, int Morehour)
{
	id = Id;
	if (Name == NULL)
		name[0] = '\0';
	else
		strcpy(name, Name);
	salary = Salary;
	hour = Hour;
	morehour = Morehour;
}

void worker::setid(int x)
{
	id = x;
}

char worker::setname(char name1[])
{
	strcpy(name, name1);
}

void worker::setsalary(int y)
{
	salary = y;
}

void worker::sethour(int g)
{
	hour = g;
}

void worker::setmorehour(int k)
{
	morehour = k;
}

int worker::getid()
{
	return id;
}

char* worker::getname()
{
	return name;
}

int worker::getsalary()
{
	return salary;
}

int worker::gethour()
{
	return hour;
}

int worker::getmorehour()
{
	return morehour;
}

int worker::calculation()
{
	return hour*salary + morehour*1.5*salary;
}