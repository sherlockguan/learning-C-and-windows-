继承中的构造函数写法-单继承
#include <iostream>
#include <string>
/*
	1.子类的构造函数写法
		除了要初始化自身数据，还需要初始化继承下来数据
	2.父类的数据必须调用父类的构造函数
		子类的构造函数必须采用初始化 参数列表的写法去写
	3.子类的构造函数，必须要调用父类的构造函数
	子类的对象的构建，百分百调用父类中构造函数
		
*/
using namespace std;
class girl
{
public:
	girl(string firstName, string secondName) :firstName(firstName), secondName(secondName)
	{
		cout << "girl的构造函数"<<endl;
	}
	girl()
	{
		cout << "父类的无参构造函数" << endl;
	}
protected:
	string firstName;
	string secondName;
};

class boy :public girl
{
public:
	boy(string firstName, string secondName, string boyName) :girl(firstName, secondName), boyName(boyName)
	{
		cout << "boy函数的构造函数" << endl;
	}
	//子类调用父类无参的构造函数的时候，可以省略不写,用的少，因为没有初始化，省略父类中的调用但也调用父类了
	boy(string boyName)
	{
		this->boyName = boyName;
	}
	void printBoy()
	{
		cout <<girl::firstName << boyName << endl;
	}
protected:
	string boyName;
};
//继承具有传递性
//继承的东西一直都存在
class A
{
public:
	A(int a) :a(a){}
	A(){} //关于子类想要构建无参的对象时候，父类中必须存在无参的构建
protected:
	int a;

};
class B :public A
{
public:
	B(int a, int b) :A(a), b(b){}
	B(){}  //关于子类想要构建无参的对象时候，父类中必须存在无参的构建
protected:
	int b;
};

class C :public B
{
public:
	C(int a, int b, int c) :B(a, b),c(c){}
	C(){} //关于子类想要构建无参的对象时候，父类中必须存在无参的构建
	void print()
	{
		cout << a << b << c << endl;
	}
protected:
	//int a;
	//int b;
	int c; 
};


int main()
{
	boy object1("BoyOne");
	object1.printBoy();
	boy object2("王", "丽", "大锤");
	object2.printBoy();
	C objectC(1, 2, 3);
	objectC.print();


	system("pause");
	return 0;
}
