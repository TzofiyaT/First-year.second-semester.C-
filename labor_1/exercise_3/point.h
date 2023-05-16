#pragma once
class point
{
	int centerX;
	int centerY;
	int R;
public:
	point(int r = 0, int a = 0, int b = 0);
	void setcenterX(int num);
	void setcenterY(int num);
	void setR(int num);
	int getcenterX();
	int getcenterY();
	int getR();
	float area();
	float scope();
	int check(int x, int y);
};

