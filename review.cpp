#include<iostream>
#include<string>
using namespace std;
class MM
//默认是private
{
	int num;
public:
	MM(string name, int num) :count(10)
	{
		this->name = name;
		this->num = num;
		cout << " " << endl;
	}
	MM() :count(10)
	{
		cout << "无参" << endl;
	}
	//特殊构造函数： 对对象的引用 功能： 实现对象给对象的赋值/初始化===》拷贝构造函数,存在默认
	MM(MM& mm) :count(10)
	{
		cout << "拷贝构造函数" << endl;
		this->name = mm.name;
		this->num = mm.num;
	}
	void print()
	{
		cout << name << "\t" << num << endl;
	}
	void print()const
	{
		cout << "静态对象只能调用静态方法" << endl;
	}
protected:
	string name;
	const int count;//必须通过初始化参数列表来初始化 :count(10)
};

int main()
{
	MM mm;
	MM array[4];
	MM object("name", 15);//参数必须一致
	system("pause");//数组就是无参的对象，需要无参构早函数
	MM *pObject;//创建对象指针不调用构造函数
	pObject = &mm;
	//new 的过程构建无名对象也是调用构造函数， 之后把无名对象的首地址赋值给指针
	pObject = new MM("baby", 1002);
	delete pObject;

	cout << "拷贝构造函数" << endl;
	mm = object;
	mm.print();
	//法二
	MM objectA(mm);
	objectA.print();

	const MM objectB("CONST", 1005);
	return 0;
}
