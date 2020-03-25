#include<iostream>
#include<string>
using namespace std;
class empty
{

};
class mm
{
public:
	char name[5];
	int age;
	double dNum;//内存对齐问题
};
struct MM
{
protected:
	int age;
	string name;

};
struct MM2
{
	int age;
	string name;
	MM2(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	MM2(){}//构造数组使用
	void print()
	{
		cout << name << "\t" << age << endl;
	}
};//只能按照c++规则去写
int main()
{
	cout << sizeof(empty)<<endl;//标记位，一个字节，有数据的话不用考虑标记位
	cout << sizeof(mm) << endl;
	MM mm;
	/*mm.age = 100;
	mm.name = "meow"*/;//结构体一般不写权限，但仍然有效，构造函数对结构体仍然有效
	MM2 mm2("hello", 24);
	mm2.print();//结构体用了c++东西，构造函数等，必须一切c++规矩
	/*    MM2 array[4];    错误，必须无参构造函数*/
	system("pause");
	return 0;
}
