#include<iostream>
using namespace std;
void modiFy(int &a)
{
	a = 1; //int 形参 = 实参 ，形参是实参的别名,本质是指针的封装而已，起别名 ，防止拷贝本产生，提高效率
}
void modiFy(int *a)
{
	*a = 10;//int 形参 = 实参 ，形参是实参的别名
}
void print(int&a)
{
	cout << a << endl;
}
void print1(const int&a)//传常量
{
	cout << a << endl;
}
void print2(int &&a)//也可以传常量
{
	cout << a << endl;
}
//引用二; 当作函数返回值，返回一个变量，增加函数左值的使用
struct girl
{
	char name[20];
	int age;
	int& getAge()
	{
		return age;
	}
};
int main()
{ // 引用就是 &起别名
	//当作函数返回， 防止拷贝本的产生
	int water = 10;
	int &H2O = water;
	H2O = 2;
	cout << water << endl;
	//引用不能和普通函数重载
	int iNum = 100;
	modiFy(iNum);
	//引用不支持传常量 mofidy（1000）
	//print(10）X
	//const；或者&&, 在函数里不能修改形参的值,不能传变量

	cout << iNum << endl;
	print1(12);
	print2(122);

	//引用二; 当作函数返回值，返回一个变量，增加函数左值的使用
	//不能返回局部变量的引用，形参可以，只要作用域满足
	girl myGirl = { "MM", 18 };
	cout << myGirl.age << "\t" << myGirl.name << endl;
	myGirl.getAge() = 13;
	cout << myGirl.age << "\t" << myGirl.name << endl;
	system("pause");
	return 0;
}
