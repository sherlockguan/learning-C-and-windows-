#include<iostream>
using namespace std;
/*特殊成员有特殊的使用方式;只能通过初始化参数列表来初始化; const:不能被修改，初始化后。
const 数据成员
const 成员函数
const 对象
*/
class MM
{
public:
	MM(int num, int age) :num(num)
	{
		this->age = age;
	}
	void print()
	{ //num+= 1 错
		cout << num << " " << age << endl;
	}
	void print()const//常成员函数,可以和普通函数形成重载
	{
		cout << num << " " << age << endl;
	}
	void printA()
	{
		cout << num << " " << age << endl;
	}
protected:
	const int num;
	int age;
};
int main()
{
	//常对象,只能调用常成员函数
	const MM constObject(1001,12);
	constObject.print();
	//constObject.printA()错
	system("pause");
	return 0;
}
