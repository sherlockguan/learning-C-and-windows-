/*
	1.什么是虚函数
		virtual修饰的成员函数
			//1.没有虚构造函数
			//2.没有虚静态函数
	2.虚函数对于类的内存影响
		2.1 对于一个空的类 需要一个标记，占用1个字节
		2.2 所有虚函数用一个指针去存储:需要四个字节
	3.虚函数表---了解下
*/
#include <iostream>
using namespace std;
class MM
{
public:
	virtual void print()
	{
		cout << "我是虚函数first" << endl;
	}
	virtual void print1()
	{
		cout << "我是虚函数second" << endl;
	}
	int  age;
};

int main()
{
	cout << sizeof(MM) << endl;
	MM object;
	//了解部分
	cout << "对象的地址:" << &object << endl;
	cout << "虚函数表的地址:" << (int *)&object << endl;
	cout << "第一个虚函数的地址" <<(int *)*(int *)&object << endl;
	typedef void(*pFunction)();
	pFunction pPrint = (pFunction)*(int *)*(int *)&object;
	pPrint(); 

	system("pause");
	return 0;
}
