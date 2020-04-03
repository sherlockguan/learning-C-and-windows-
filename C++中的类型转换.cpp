C++转换问题
#include <iostream>
using namespace std;
/*
	C++中的类型转换
	C++ 中的说法:更为安全
	const_cast :去掉const属性
	static_cast: 类型转换-->C语言的强转 （类型）变量  没有virtual
	dynamic_cast				
		上行: 子类到父类
		下行：父类到子类
	reinterpret_cast--->把数字当做地址处理
	语法:
	关键字<new_type>(expression);
*/
class parent
{
public:
	virtual void print()
	{
		cout << "parent" << endl;
	}
};

class son :public parent
{
public:
	 void print()
	{
		cout << "son" << endl;
	 }
	 void printData()
	 {
		 cout << "printData" << endl;
	 }
};


int main()
{
	const int a = 1;
	int *p = const_cast<int *>(&a);
	*p=1002;
	cout << *p << endl;
	cout << a << endl;
	cout << p << endl;
	cout << &a << endl;
	int  num = 1;
	double data = 1.222;
	num = (int)data;
	num = static_cast<int>(data);
	int *pData = reinterpret_cast<int *>(1212);
	parent pObject;
	//下行转换
	son *sp = (son *)&pObject;	//C语言强转
	sp->print();
	sp->printData();
	son* pSon = nullptr;
	if ((pSon = dynamic_cast<son *>(&pObject)) != nullptr)
	{
		pSon->print(); 
	}
	else
	{
		cout << "转换失败" << endl;
	}
	//dynamic_cast 适用于多态情况
	//只能把被子类对象初始化的父类指针转换子类指针类型
	parent* ppParent = new son;  //调用是子类中与virtual 的同名函数
	ppParent->print();			//调用是子类中与virtual 的同名函数
	son* ppSon = nullptr;
	if ((ppSon = dynamic_cast<son *>(ppParent)) != nullptr)
	{
		ppSon->print(); 
		ppSon->printData();
	}
	else
	{
		cout << "转换失败" << endl;
	}
	system("pause");
	return 0;
}
