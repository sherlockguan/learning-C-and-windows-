#include <iostream>
#include <string>
using namespace std;
/*
stream： 流 ，数据一端到 另一端移动过程
输出流: ostream类的对象 ---->cout
输入流: istream类的对象 ---->cin
重载的运算符 <<（输出）    >>（输入）
注意点：
1.流重载一定要使用引用&！！！ 流重载是左移和右移运算符的重载，重载的对象是C++标准库的不是自己的
2.只能通过友元重载
*/
class MM
{
public:
	MM(){}
	void print()
	{
		cout << name << "\t" << num << "\t" << age << endl;
	}
	//首先:最直接的写法
	//ostream operator<<(ostream out ,MM mm) 成员函数不对
	
	friend ostream& operator<<(ostream& out, MM mm)//输出
	{
		//把out当做cout去使用就可以， out 就是一个形参，代表流对象
		out << mm.name << "\t" << mm.age << "\t" << mm.num << endl;
		return out;
	}
	friend istream& operator>>(istream& in, MM& mm) //一定要用& 
		//输入数据也要用引用，输入去初始化 MM输入也要引用，in 修改了形参的值，
		//同步到实参的话要防止拷贝本产生
	{
		cout << "cin name num age:" << endl;
		in >> mm.name >> mm.num >> mm.age;
		return in;//返回in对象
	}
protected:
	string name;
	int num;
	int age;
};
//2.流重载的间接写法：把访问数据的部分用一个子(成员）函数封装，间接友元的方式
class boy
{
public:
	boy(){}
	void input(istream& in)
	{
		cout << "cin name num age:" << endl;
		in >> this->name >> this->age;
	}
	void output(ostream& out)
	{
		//把out当做cout去使用就可以
		out << this->name << "\t" << this->age << endl;
	}
	friend ostream& operator<<(ostream& out, boy mm)
	{
		mm.output(out);//间接，用成员函数封装 out << this->name << "\t" << this->age << endl;
		return out;
	}
	friend istream& operator>>(istream& in, boy& mm)
	{
		mm.input(in);
		return in;
	}
protected:
	string name;
	int age;
};

int main()
{
	string str = "Love";
	cout << str << endl;
	MM  mm;
	//cin.operator>>(mm); 写不到cin里面，不可能用类成员函数的方式，只能用友元
	//operator>>(ostream object, MM mm);
	cin >> mm;
	cout << mm << endl;
	/*cin >> object 不在是输入一个东西了，函数重载：而是解释为operator >> (cout, obect); 函数的调用了，然后这个函数从上往下执行，函数运行结束 ，cin >> object 就运行完了

*/


	//再拿数组举例子流重载，更方便简单，链表打印输入也是一样
	MM array[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> array[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cout << array[i];
	}
	//间接写法
	boy myBoy;
	cin >> myBoy;
	cout << myBoy << endl;


	system("pause");
	return 0;
}
