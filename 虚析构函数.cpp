#include <iostream>
using namespace std;
/*析构函数就是当你类中属性申请了内存的时候，需要手动写

一般你做了子类对象初始化父类指针都需要把父类中的析构函数改为虚析构函数哦
*/
class parent
{
public:
	parent()
	{
		name = new char[4];
	}

	//虚析构函数
	virtual ~parent()
	{
		delete[] name;
		name = nullptr;
		cout << "parent" << endl;
	}
	char *name;
};
class son :public parent
{
public:
	~son()
	{
		cout << "son" << endl;
	}
};
//虚函数继承，在继承中遗传性(传递性)

class A
{
public:
	virtual void print()
	{
		cout << "A" << endl;
	}
};

class B :public A
{
public:
	virtual void print()
	{
		cout << "B" << endl;
	}
	//virtual void print()

};
class C :public B
{
public:
	void print()
	{
		cout << "C" << endl;
	}
};

int main()
{
	{
		parent *p = new son;
		delete p;
		p = nullptr;
	}
	A* AObject = new B;
	AObject->print();		//调用B类中


	B* BObject = new C;
	BObject->print();	//调用C

	AObject = new C;
	AObject->print();

	system("pause");
	return 0;
}
