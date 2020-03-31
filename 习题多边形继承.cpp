#include<iostream>
#include<string>
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;
class polygon
{
public:

	void print()
	{
		cout << "this is a abstract base class" << endl;
	}
	//polygon(){}
	void printArea()
	{
		cout << "the area of this polygon is" << endl;
	}
	void printPerimeter()
	{
		cout << "the perimeter of this polygon is" << endl;
	}
//protected:
//	int area;
//	int perimeter;
};

class rectangle :public polygon
{
public:
	rectangle(int a, int b) :a(a), b(b)
	{
		this->a = a;
		this->b = b;
	}
	int myArea()
	{
		return a*b;
	}
protected:
	int a;
	int b;
};
class circle :public polygon
{
public:
	
	circle(int radius) :radius(radius)
	{
		this->radius = radius;
	}
	
	double myPerimeter()
	{
		return 2 * M_PI*radius;

	}
protected:
	int radius;

};
int main()
{
	
	circle *pCircle = new circle(5);
	pCircle->printPerimeter();
	pCircle->myPerimeter();
	
	rectangle object(2, 3);
	object.printArea();
	object.myArea();

	system("pause");
	return 0;
}


//亲爱的小鬼老师， 我写是写了， 怎么也打印不出值来，辛苦老师了，都快结课了。。
