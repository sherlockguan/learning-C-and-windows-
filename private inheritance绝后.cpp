#include <iostream>
#include <string>
using namespace std;
//私有继承：断子绝孙， 让类只能被继承一次

class  A
{
public:
	A(int a) :a(a){}
	void print()
	{
		cout << a << endl;
	}
protected:
	int a;
};
class B :private A        //B 的子类不会再有祖宗A的属性， 继承的传递性消失。   如果A 有其他非私有继承的属性，可以啊；； 保护类所有继承下来
{
public:
	B(int a, int b) :A(a), b(b){}
protected:
	int b;
private:
	//void print()
	//int a;
};
class C :public B
{
public:
	C(int a, int b, int c) :B(a, b), c(c)
	{

	}
	void print()
	{
		//cout << a << endl; 祖辈类的属性丢失
		cout << b << endl;
		cout << c << endl;
	}
protected:
	int c;
};

int main()
{
	C c(1, 2, 3);
	c.print();
	system("pause");
	return 0;
}
