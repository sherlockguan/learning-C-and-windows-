//类外对象不可以访问类中的保护及私有类型
//友元函数：并不是赋予函数上述权限，而是在友元函数中赋予对象访问保护私有的权限
	//	：传参的对象
	//：函数中的对象
#include<iostream>
#include<string>
using namespace std;
class MM
{
public:
	MM(string name, int age) :name(name), age(age){}
	//类中的函数可以直接访问数据成员的
	void print()
	{
		cout << name << "\t" << age << endl;
	}
	friend void printInfo(MM object);
protected:
	string name;
	int age;
};
//类外实现友元函数不需要作用域分辨符和friend关键字-》友元函数不属于类
//友元函数：并不是赋予函数上述权限，而是在友元函数中赋予对象访问保护私有的权限
//1.传参的方式
//2.在友元函数中创建对象
void printInfo(MM object)
{
	MM mm("cute", 20);
	cout << mm.name << "\t" << mm.age << endl;
	cout << object.name << "\t" << mm.age << endl;
}


int main()
{
	MM mm("sunshine", 18);
	printInfo(mm);
}
