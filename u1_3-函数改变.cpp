#include<iostream>
using namespace std;
/*
内联函数：二进制代码，不用编译，牺牲空间，提高效率 短小； 用inline修饰，或者在结构体，类中 实现的函数
重载 : 允许同名不同参的函数存在 
       不同参： 数目不同； 类型不同； 顺序不同， 建立存在不同类型。
缺省：重载的结合体， 缺省就是给形参初始化,缺省只能从右往左，中间不能有空的
*/
inline int Max(int a, int b)
{
	return a > b ? a : b;
}
char Max(char a, char b)
{
	return a > b ? a : b;
}//类型不同
//数目不同
int Max(int a, int b, int c)
{
	return a > b ? a : b > c ? a > b ? a : b : c;
}
/*int Max(int a, int b, int c)
{
	int d = a>b ? a : b
	return d>c ? d : c
}*/
//顺序不同不是指形参先后顺序，而是存在不同类型
void print(char a, int b)
{
	cout << a << "\t" << b << endl;
}
void function(int a, int b = 5, int c = 1)
{
	cout << a << endl;//不传参数时采用默认值
	cout << b << endl;
	cout << c << endl;


}
int main()
{ // 函数重载， 根据数据类型决定调用哪个函数
	cout << Max('A', 'B') << endl;//必须用单引号
	cout << Max(1, 2, 3) << endl;
	print('A', 12);
	
	function(1);
	function(1, 2, 3);
	function(1, 2);//构造函数， 类的继承多用缺省

	system("pause");
	return 0;
}
