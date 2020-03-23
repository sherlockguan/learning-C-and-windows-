#include<iostream>
#include<string>
using namespace std;
//c++ 既可以面向过程（结构体）， 面向对象（结构体或者类）， 面向对象写一个链表举例
struct MM
{
	string name;
	int age;
	void print()
	{
		cout << name << " " << age << endl;
	}
	//构造函数：负责为对象的基本数据成员初始化，不需要自己调用
		//在结构体变量创建的时候调用；名字和结构体名字相同， 没有返回值， 调用为结构体变量被创建时调用
		//C 语言的main默认初始化不可以在用了,除非加上构造函数初始化数据成员
	MM(string name1="meow",int age1=50)//通过构造函数形参初始数据成员,缺省--决定结构体变量的形态
	{
		name = name1;
		age = age1;
		cout << "调用构造函数的过程" << endl;
	}
};//C++ 的方式
void print(struct MM mm)
{
	cout << mm.name << " " << mm.age << endl;
}
	//C 语言是行为访问属性，用行为调用对象
int main()
{
	//构造函数： 名字和结构体名字相同， 没有返回值， 调用为结构体变量被创建时调用
	MM mm = { "Love", 12 };//C语言的默认初始化------C++（面向对象）用对象调用行为,用对象访问成员 !!! 构造函数在结构体调用
	mm.print();//C++（面向对象）用对象调用行为,用对象访问成员,对象.行为，行为是描述对象的
	print(mm);//C 语言永远行为（print行为）操作对象mm，行为是指函数， 属性是数据成员

	MM mm2{ "baby", 13 };//C++调用构造函数来初始化，为数据成员初始化
	//前文函数缺省就是为了创建不同形态的结构体变量/对象 mm1,mm2
	MM object;




	system("pause");
	return 0;
}
