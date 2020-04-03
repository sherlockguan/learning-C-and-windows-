#include <iostream>
using namespace std;
class Human
{
public:
	virtual void makeFriend()
	{
		cout << "huMan make friend" << endl;
	}
};
class Girl :public Human
{
public:
	void makeFriend()
	{
		cout << "girl make Friend" << endl;
	}
};
class Boy :public Human
{
public:
	void makeFriend()
	{
		cout << "boy make Friend" << endl;
	}
};

void test(Human* object)
{
	object->makeFriend();
}

int main()
{
	Human* pHuman = new Human;
	Girl *pGirl = new Girl;
	Boy *pBoy = new Boy;
	test(pHuman);
	test(pGirl);
	test(pBoy);
	//1.必须父类存在虚函数
	//2.存在父类指针对子类对象的引用
		//2.1 new语法  2.2 取对象的地址
	Human* pParent = new Girl;
	pParent->makeFriend();
	pParent = new Boy;
	pParent->makeFriend();
	Girl objectGirl;
	pParent = &objectGirl;
	pParent->makeFriend();
	Boy objectBoy;
	pParent = &objectBoy;
	pParent->makeFriend();
	/*
		那个指针调用哪个东西
		在没有virtual的父类被继承下
			1.父类指针被子类对象初始化
			2.永远只能调用父类的成员
		在存在virtual情况下,存在父类指针被子类对象的初始化
			1.指针调用的成员是根据子类对象
	*/
	system("pause");
	return 0;
}


