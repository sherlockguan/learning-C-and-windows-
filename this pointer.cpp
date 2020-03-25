#include<iostream>
#include<string>
using namespace std;
//this指针代表对象本身，每个对象的首地址,
//当形参名和数据成员名字相同时， this指针标识数据成员
//2/当作返回对象本身使用，函数返回值
class MM
{
public:
	MM(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	MM* getObjectAddr()//指针
	{
		return this;//指向常属性值
	}
	MM &getOject()//引用
	{
		return (*this);//取值
	}
	void print()
	{
		cout << name << "\t" << age << endl;
	}
protected:
	string name;
	int age;
};

int main()
{
	MM girl("laolao", 88);
	girl.print();

	MM* p = girl.getObjectAddr();
	p->print();

	MM beauty = girl.getOject();
	beauty.print();
	system("pause");
	return 0;
}
