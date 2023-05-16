#pragma once
class Vector
{
private:
	int *data;
	int capacity;
	int size;
public:
	Vector();  // float is just to distinguish between the constructors
	Vector(int);
	Vector(const Vector&temp);
	int get_capacity();
	int get_size();
	void insert(int);
	int*get_data();
	void set_data(int*);
	void print();
	Vector operator=(Vector a);
	void clear();
	void delLast();
	bool operator==(Vector a);
	int operator*(Vector a);
	Vector operator+(Vector a);
	int& operator[](int a);
	~Vector();
};

