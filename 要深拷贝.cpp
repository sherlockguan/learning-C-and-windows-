#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
/*
1.拷贝构造函数也是构造函数，为了把一个对象的属性赋值给另一个对象
参数特殊化，只有一个参数 ，对对象引用
拷贝构造函数就是为了实现对象之间的赋值
*/
using namespace std;
class MM
{
public:
	MM(string mmName, int mmAge)
	{
		name = mmName;
		age = mmAge;
	}
	MM(MM &object)//浅拷贝
	{
		name = object.name;
		age = object.age;
		cout << "调用拷贝构造函数" << endl;
	}
	void print();
protected:
	string name;
	int age;
};
void MM::print()
{
	cout << name << "\t" << age << "\n";
}
//深拷贝和浅拷贝(不涉及到内存的分配的）
class girl
{
public:
	girl(char* str)
	{
		name = new char[strlen(str) + 1];
		strcpy(name, str);

	}
	girl(const girl& object)
	{
		name = new char[strlen(object.name) + 1];//深拷贝
		strcpy(name, object.name);
		name = object.name;//浅拷贝会引发析构问题
	}
	~girl()
	{
		if (name != nullptr)//避免重复析构->仍然不行-》深拷贝，动态内存申请
		{
			delete[] name;
			name = nullptr;
			cout << "调用析构函数" << endl;
		}
		
	}
protected:
	char* name;

};
void print(const int age)
{//不能修改，常量
	cout << age << endl;
}

int main()
{
	string str0("baby");
	string str1(str0);//一个对象给另一个初始化
	string str2 = str1;//调用默认， 自己写的话默认不存在，调用拷贝构造函数

	MM mm1("god",18);
	MM mm2(mm1);
	mm2.print();

	cout << "深拷贝和浅拷贝问题" << endl;
	{
		girl myGirl("cutie");
		girl yourGirl(myGirl);
	}//加括号为了能看到析构函数,浅拷贝（两个指针指向同一段内存）同一段内存析构的两次会引发析构问题

	


	system("pause");
	return 0;
}
