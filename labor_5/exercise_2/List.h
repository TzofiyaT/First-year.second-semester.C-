#pragma once
#include <iostream>
using namespace std;

class List
{
private:
	class Link
	{
	public:
		Link(int linkValue, Link *nextPtr);
		Link(const Link &);
		int value;
		Link * next;
	};
public:
	Link* head;   
	List();
	List(const List&);
	~List();
	void print() const;
	void operator=(const List& other);
	void clear();
	void setCin(int);
	friend istream& operator >> (istream&, List&);
	friend ostream& operator<<(ostream&, const List&);
	void insert(int key);
	void remove(int key);
};