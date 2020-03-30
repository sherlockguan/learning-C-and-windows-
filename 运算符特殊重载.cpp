/*
1.自定义类型和普通数据相加
2.++/-- 前置和后置重载区别
*/
#include <iostream>
#include <string>
using namespace std;
class MM
{
public:
	MM(){}
	MM(int weight) :weight(weight)
	{

	}
	MM operator+(MM object2)
	{
		MM  object;
		object.weight = this->weight + object2.weight;
		return object;
	}
	void print()
	{
		cout << "\t" << weight << "kg\t" << endl;
	}
protected:
	int weight;
};

class Data
{
public:
	Data(){}
	Data(int num) :num(num)
	{

	}
	//以++为例
	void print()
	{
		cout << num << endl;
	}
	// warning C4620: 未找到类型“Data”的“运算符 ++”后缀形
	Data operator++(int)	//int表示这个是后置,起说明作用
	{
		cout << "后置++" << endl;
		Data object(this->num++);
		return object;
	}
	//前置的
	Data operator++()
	{
		cout << "前置++" << endl;
		this->num++;
		return (*this);
	}
protected:
	int num;
};
//迭代器-->类 的对象来模仿指针的行为（容器）
int main()
{
	MM mm(48);
	mm.print();
	//1.operator+(mm);
	//常量在前:一定是友元重载的方式
	MM boy = mm + 1;		//自定义类型和普通数据相加
	boy.print();
	Data object(1002);
	//++ 的解释: object=object+1;
	Data result = object++;
	object.print();
	result.print();
	Data result2 = ++object;
	result2.print();
	object.print();


	system("pause");
	return 0;
}
