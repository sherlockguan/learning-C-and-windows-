#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>

using namespace std;
//构造函数：名字和类名同
 //没有返回值，
//不写存在一个默认的无参构造函数，
//不用自己调用，构造对象时被调用
//为对象的数据成员初始化

//析构函数：无参，名字是 ~类名（）{}  对象死亡时被调用，只有一个不用重载
  //不写的话每个类存在一个默认的析构 ， 当数据成员存在指针动态申请内存的时候，通常要手动写析构函数
//析构函数和构造函数的调用顺序
class MM
{
public:
	MM()
	{
		cout << "我是一个无参的构造函数" << endl;
	}
	MM(string  mmName, int mmAge);
	void print()
	{
		cout << name << "\t" << age << endl;
	}
	~MM()
	{
		cout << "我是析构函数" << endl;
	}
protected:
	string name;
	int age;
};
//类外实现成员函数， 要加前缀
MM::MM(string mmName, int mmAge)
{
	name = mmName;
	age = mmAge;
	cout << "类外实现带参构造函数" << endl;
}
//简单案例
class text
{
public:
	text(char testNum)//构造
	{
		num = testNum;
		cout << num;
	}
	~text()//析构
	{
		cout << num;//析构前吧数据输出一下
	}
protected:
	char num;

};
//需要手动写析构函数的案例， 有数据成员的时候
class gg
{
public:
	gg(char*ggName, int ggAge)
	{
		//指针没内存要手动申请
		name = new char[strlen(ggName) + 1];
		strcpy(name, ggName);
	}
	void print()
	{
		cout << name << "\t" << age << endl;

	}
	~gg()
	{
		if (name != NULL){//安全考虑
			delete[]name;
		}
		
	}
protected:
	char * name;
	int age;
};

int main()
{
	//MM mm;
	//mm.print();

	//MM *p = nullptr;//创建对象指针和对象没有关系，所以不会调用构造函数
	//p = new MM;//会调用构造函数， 构造可以被重载缺省
	//delete p;
	////有参的
	//MM girl("meow", 18);
	//girl.print();
	////同理
	//MM *pObject = new MM("baby",38);
	//pObject->print();
	//delete pObject;

	//构造顺序： 按照程序运行从上往下的 方式去构造对象
	//构造的顺序和析构顺序相反！！！
	{
		text target0('A');
		text target1('B');
		//动态内存申请 delete 会影响顺序
		text *p = new text('n');
		delete p;//会调用析构函数
		text target2('C');
		static text targetStatic('S');
	}

	//大括号是作用域限定符， 否则构造再析构， 没有结果
	//我记得字符赋值用单引号	字符串才是双引号
	//static 是最后被析构的， 静态变量最后死亡被释放
	cout << endl;
	cout << "手动析构函数" << endl;
	gg liqi("丹尼斯里奇",78);
	liqi.print();

	cout << endl;

	system("pause");
	return 0;
}
