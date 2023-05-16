#pragma once
#include <cstring>
class worker
{
	int id;
	char name[20];
	float salary;
	int hour;
	int morehour;
public:
	worker(int Id=0, char Name[]=NULL,float Salary=0.0, int Hour=0, int Morehour=0 );
	void setid(int x);
	char setname(char name1[]);
	void setsalary(int y);
	void sethour(int g); 
	void setmorehour(int k);
	int getid();
	char* getname();
	int getsalary();
	int gethour();
	int getmorehour();
	int calculation();
};

