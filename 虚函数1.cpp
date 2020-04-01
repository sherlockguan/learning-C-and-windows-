//构造函数没有虚函数， 也没有虚静态函数，虚函数就是为了实现多态，多态就是同一个行为造成不同结果（函数重载是静态多态），没有虚函数会覆盖现象
//菱形继承没有多态，只会继承祖父的，父母不起作用
//空的类 标记位，一个字节
//非空不用考虑标记位,所有虚函数存放在一个指针里面，占用四个字节
//原理是类里面的虚函数表

#include<iostream>
using namespace std;
class MM
{
public:
	virtual void print()
	{
		cout << "this is virtual func" << endl;
	}
};

int main()
{
	cout << sizeof(MM) << endl;
	system("pause");

}
