//提供公有接口去初始化
//1.提供公有函数传参的方式
//2.提供公有函数返回引用
//正统方式： 构造函数
#include<iostream>
#include<string>
#include<graphics.h>
#include<conio.h>
using namespace std;
class MM
{
public:
	//传参的方式
	void initMMData(string mmName, int mmAge)
	{
		name = mmName;
		age = mmAge;

	}
	//返回引用即返回变量本身
	string& getName()
	{
		return name;
	}
	int& getAge()
	{
		return age;
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
	/*MM mm;
	mm.initMMData("baby", 38);
	mm.print();
	MM *p = new MM;
	p->getName() ="meow";
	p->getAge = 28;
	p->print();
	delete p;*/

	IMAGE img;
	initgraph(400, 300);
	loadimage(&img, "1.jpg");
	putimage(0,0,img);
	_getch();
	closegraph();
	
}
