#include <iostream>
#include "Vector.h"
using namespace std;

Vector::Vector()
{
	capacity = 10;
	data = new int[capacity];
	size = 0;
}

Vector::Vector(int value)
{
	this->capacity = value;
	data = new int[capacity];
	size = 0;
}

Vector::Vector(const Vector&Temp)
{
	this->capacity = Temp.capacity;
	this->size = Temp.size;
	this->data = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = Temp.data[i];
	}
}

int Vector::get_capacity()
{
	return capacity;
}

int Vector::get_size()
{
	return size;
}

void Vector::insert(int i)
{
	*data = i;                 // insert the value
	data++;                  // promote the pointer (for the next insert) 
	size++;                 // num of element in the array is now ++
}

int* Vector::get_data()
{
	return data;
}

void Vector::set_data(int* p)
{
	data = p;
}

void Vector::print()
{
	cout << "capacity: " << capacity << " size: " << this->size << " val: ";
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

Vector Vector::operator=(Vector a)
{
	data = new int[a.capacity];
	size = a.size;
	for (int i = 0; i < a.size; i++)
	{
		data[i] = a.data[i];   // copy the element, now the value is same same.
	}
	return *this;
}

void Vector::clear()
{
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;   // delete the value
	}
	size = 0;
}

void Vector::delLast()
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == 0)
			count++;
	}
	if (count == size)
	{
		cout << "ERROR\n";
	}
	else
	{
		data[size] = 0;     // delete ta last one
		size--;
	}
}

bool Vector::operator==(Vector a)
{
	int count = 0;
	if (size == a.get_size())    // if the arrays size are even
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == a.get_data()[i])
			{
				count++;     // count the element that is even
			}
		}
		if (count == size)    // if all the element is even
		{
			return true;
		}
		return false;
	}
	return false;
}

int Vector::operator*(Vector a)
{
	int result = 0;
	if (size == a.get_size())     // can't multiplicate vectors that are not even (in size)
	{
		for (int i = 0; i < size; i++)
		{
			result += data[i] * a.get_data()[i];   // skalar multiplicate
		}
	}
	else
	{
		cout << "ERROR\n";    // can't multiplicate vectors that are not even (in size)
	}
	return result;
}

Vector Vector::operator+(Vector a)
{
	Vector A;
	int *result = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		A.data[i] = data[i];           // copy the exsist vector in the begining .....               
		A.data[i + size] = a.data[i];    //... add the new vector after the first one                 
	}
	A.size = (a.size) * 2;         // update the array size
	return A;
}

int& Vector::operator[](int a)
{
	if (a <= size)
	{
		return data[a];
	}
	cout << "ERROR\n";
}

Vector::~Vector(void)
{
	if (data)
	{
		delete[]data;
	}
}