#include <iostream>
#include <string>
using namespace std;
class parent
{
public:
	string str;
	parent(string str) :str(str){}
	void printParent()
	{
		cout << str << endl;
	}
};

class son:public parent
{
public:
	son(string str,string strSon) :parent(str), strSon(strSon){}
	string strSon;
	void printSon()
	{
		cout << strSon << endl;
	}

};
int main()
{    //普通： 子类中同名函数会覆盖掉父类的同名函数，如果真要访问父类，少用，用作用域分辨符 pSon->parent::print()
	//普通对象，自己访问自己的，就近原则
	parent parentObject("parent");
	parentObject.printParent();
	son sonObject("parent", "son");
	sonObject.printSon();
	//对象指针正常初始化 
	parent *pParent = new parent("father");
	pParent->printParent();
	son *pSon = new son("father","good son");
	pSon->printSon();

	//2. 特殊：指针非正常初始话 
	   //2.1 父类指针用子类对象初始化,指针是谁的，调用谁的--父类， 反之不允许
	parent *pP = new son("parent2", "son2");
	pP->printParent();


	system("pause");
	return 0;
}
