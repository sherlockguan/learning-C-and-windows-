#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
/*
	Lambada表达式-->短小精悍的函数写成表达式
完全的组成部分:
	[captrue list](parems  list) mutable exception->return type{function body;};
	[捕获方式](参数列表) 能否修改捕获的值 异常->函数返回值类型{函数体;};
	捕获方式:
		[] [=]:用值的方式捕获
		[this]: 指针方式 成员函数
		[&]: 引用
		[=,&x]:指定x是引用 ，其他的变量用值的方式
	参数列表: 函数参数
	是否存在异常: throw()
	注意: 
		No.1 Lambada返回的最终其实一个个函数指针,所以经常结合auto去使用
		No.2 除了捕获方式以及函数体，其他的都可以省略
				[]{}

*/
int Max(int a, int b)
{
	return a > b ? a : b;
}
//this的捕获方式
class test
{
public:
	void print()
	{
		cout << [this]()->int{return a + b; }() << endl;
	}
protected:
	int a = 1001;
	int b = 1002;
};

int main()
{
	//[captrue list](parems  list) mutable exception->return type{function body;};
	auto result = [](int a, int b)mutable throw()->int{return a > b ? a : b; };
	cout << result(1, 2) << endl;
	cout << [](int a, int b)mutable throw()->int{return a > b ? a : b; }(2, 3) << endl;
	//2.1 简化版--不考虑能否修改和是否存在异常
	cout << [](int a, int b)->int{return a > b ? a : b; }(1001, 1002) << endl;
	//2.2 没有返回值的简化
	[](int printData){cout << printData << endl; }(1009);
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//3.Lambada表示用在STL算法中
	for_each(array, array + 10, [](int data){cout << data << "\t"; });
	cout << endl;
	//4.所谓的捕获方式指的是使用当前Lambada式外面的变量的方式
	int num = 1;
	auto pFunction = [&]{cout << num << endl; };
	pFunction();
	num = 1002;
	pFunction();
	[=, &num]{cout << num << endl; }();
	test object;
	object.print();
	//5.能否被修改--代表的是一种const 属性
	int modifyNum = 1004;
	auto pModify = [=]()mutable {modifyNum++; cout << modifyNum << endl; };
	pModify();
	cout << modifyNum << endl;
	system("pause");
