#include<iostream>
#include<string>
using namespace std;
//类外实现不用static修饰
//静态成员的访问可以不用对象
//静态成员函数访问静态无要求
//访问非静态--对象：传参;或者自己创建对象
class MM
{
public:
	MM(string name) :name(name){}//访问非静态--对象：传参; 或者自己创建对象
	static void print(MM object)
	{
		cout << num << endl;///静态成员函数访问静态无要求
		cout << object.name << endl;//访问非静态--对象：传参
		cout << "static function" << endl;
	
	}
	static void print2();
protected:
	static int num;
	string name;
};
int MM::num = 1001;
void MM::print2()
{
	MM object("MM");
	cout << object.name << "\t"<<num<<endl;
	cout << "static2 fucntion" << endl;
}
int main()
{
	MM ob("girl");
	MM::print(ob);//静态特色
	ob.print(ob);//一般
	system("pause");
	return 0;
}
//数组是无参的对象；所以需要构造无参的构造函数，不存在默认无参构造函数，自己写上
//不写构造函数，有默认无参的构造函数，可以构造对象
//构造函数有参数，对象的参数一致，决定对象的样子
