#include<iostream>
#include<string>
using namespace std;
//static 成员必须在类外初始化,静态成员，访问不需要对象“公交车”，不用static 关键字
class girl
{
public:
	
	static string name;
	static void print()
	{
		cout << name << endl;//静态成员函数访问非静态数据成员需要指定对象，通过传参
	}
	static void printObject(girl object)
	{
		cout << object.age << endl;
		cout << object.name << endl;
	}
	girl(int age) :age(age){};
protected://权限限定有效依然
	int age;
	
};

string girl::name = "banana";
class data
{
public:
	data()
	{
		count++;
	}
	void print()
	{
		cout << count << endl;

	}
	static int count;
protected:

};
int data::count = 0;
int main()
{

	cout << girl::name << endl;
	girl::print();
	girl beauty(88);//年龄
	girl::printObject(beauty);

	data myData;//创建对象就调用了狗仔函数 -》1
	data ArrayData[3];//-》4
	myData.print();
	system("pause");
	return 0;
}
