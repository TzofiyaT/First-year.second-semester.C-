#pragma once
class String
{
	char* str;
public:
	String();    //defolt c-tor
	String(char*); //c-tor
	void print_str();
	char*get_str();
    String operator+(String str);
	void operator>(String str);
	void operator<(String str);
	void operator=(String str);
	String insert(int index, const char* str);
	~String(void);
};