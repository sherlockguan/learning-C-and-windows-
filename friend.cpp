#include<iostream>
#include<string>
using namespace std;
/*
友元; 赋予类打破权限的作用
友元函数，friend修饰的函数
友元类：
*/
class girl
{
public:
	girl(string name, int age) :name(name), age(age)
	{

	}
	friend void print();//独立不属于类， 类外实现不用作用域限定
	friend void printA(girl object)//独立不属于类， 类外实现不用作用域限定
	{
		//任何属性都可以被调用，打破类的封装
		cout << object.name << " " << object.age << endl;
	}
protected:
	string name;
private:
	int age;
};
void print()
{
	girl myGirl("baby", 98);
	cout << myGirl.name << " " << myGirl.age << endl;
}
int main()
{
	girl beauty("haha", 118);
	print();
	printA(beauty);
	system("pause");
	return 0;
}
