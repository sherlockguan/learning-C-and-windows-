#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node()
	{
		next = nullptr;
	}//无参构造
	Node(int dataA)
	{ 
		data = dataA;
	}//第二种
	Node(int dataA, Node* nextA)
	{
		data = dataA;
		next = nextA;
	}//第三种构造函数
};
struct list
{
	Node* firstNode;
	int size;
	list();//构造函数 先声明 
	void insertNode(int data);
	void printList();
};
list::list()//后构造函数在结构体外面定义  函数需要加上前缀作用域分辨符，为struct list 基本数据成员初始化
{
	firstNode = NULL;
	size = 0;

}
void list::insertNode(int data)
{
	firstNode = new Node(data, firstNode);

}
void list::printList()
{
	Node* pMove = firstNode;
	while (pMove)
	{
		cout << "\t" << pMove->data << endl;
		pMove = pMove->next;
	}
	cout << endl;

}
int main()
{
	list* pList = new list;
	pList->insertNode(1);
	pList->insertNode(2);
	pList->insertNode(3);
	pList->printList();

}
