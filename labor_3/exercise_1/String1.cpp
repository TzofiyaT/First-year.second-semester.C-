#include "String1.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

String::String()
{
}

String::String(char*string)
{
	str = new char[strlen(string) + 1];   // creayte arrary for the length of this sting +1 for \0
	strcpy(str, string);
}

char* String::get_str()
{
	return str;
}

void String::print_str()
{
	cout << str << endl;
}

String String::operator+(String s)
{
	char*temp = new char[strlen(str) + strlen(s.str) + 1];          //creayte arrary for the length of two string  +1 for \0       
	strcpy(temp, str);
	strcat(temp, s.str);                              // add the second string to the first one
	String Temp(temp);                               // creayte new string that contine the two stings
	return Temp;
}

String String::insert(int index, const char* s)
{
	if (index <= strlen(str))
	{
		char*temp = new char[strlen(str) + strlen(s) + 1];          //creayte arrary for the length of two string  +1 for \0         
		strncpy(temp, str, index);                              //copy the first string but only form the begining to the index
		temp[index] = '\0';            // end the first word (not complete word)
		strcat(temp, s);                // add the second string
		strcat(temp, str + index);          //add the first word (the left letters(from the index))
		String Temp(temp);
		return Temp;
	}
	else
	{
		cout << "ERROR\n";
		str = NULL;
	}
}

void String::operator>(String s)
{
	if (strcmp(str, s.get_str())>1)    //its mean: the first word is biger from the second word
	{
		cout << "a>b\n";
	}
}

void String::operator<(String s)
{
	if (strcmp(str, s.get_str())<0)   //its mean: the first word is smaller from the second word
	{
		cout << "a<b\n";
	}
}

void String::operator=(String s)
{
	if (strcmp(str, s.get_str()) == 0)   //its mean: the two words is even
	{
		cout << "a=b\n";
	}
}

String::~String()
{
}