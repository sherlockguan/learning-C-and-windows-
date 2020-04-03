纯虚函数和ADT过程
#include <iostream>
using namespace std;
/*
	1.纯虚函数:也是虚函数  没有函数体的虚函数
		虚函数=0;
	2.抽象类: 具有至少一个纯虚函数的类，称之为抽象类
		2.1抽象类的特性:不能创建对象,可以创建对象指针
		2.2 抽象类继承，子类需要把抽象类中所有纯虚函数，实现，子类才可以对象
*/
//抽象类--->ADT abstract data type
class stack
{
public:
	//纯虚函数
	virtual void push(int data) = 0;
	virtual void pop() = 0;
	virtual int top() = 0;
	virtual int size() const = 0;
	virtual int empty() const = 0;
};

class arrayStack:public stack
{
public:
	arrayStack(int MAX = 10)
	{
		stackMemory = new int[MAX];
		stackTop = -1;
	}
	//重写过程
	void push(int data)
	{
		stackMemory[++stackTop] = data;
	}
	//重写过程
	void pop()
	{
		stackTop--;
	}
	//重写过程
	int top()
	{
		return stackMemory[stackTop];
	}
	//重写过程
	int size() const
	{
		return stackTop+1;
	}
	//重写过程
	int empty() const 
	{
		return stackTop==-1;
	}
protected:
	int *stackMemory;
	int stackTop;
};

class listStack :public stack
{
public:
	listStack(int MAX = 10)
	{
		stackMemory = new int[MAX];
		stackTop = -1;
	}
	void push(int data)
	{
		stackMemory[++stackTop] = data;
	}
	void pop()
	{
		stackTop--;
	}
	int top()
	{
		return stackMemory[stackTop];
	}
	int size() const
	{
		return stackTop + 1;
	}
	int empty() const
	{
		return stackTop == -1;
	}
protected:
	int *stackMemory;
	int stackTop;
};

int main()
{
	stack* pStack = new listStack;
	for (int i = 0; i < 3; i++)
		pStack->push(i);
	while (!pStack->empty())
	{
		cout << pStack->top() << '\t';
		pStack->pop();
	}
	cout << endl;
	system("pause");
	return 0;
}

