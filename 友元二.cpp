//一个类的成员函数是另一个类的友元函数， 注意编译顺序从上往下，不要出现未定义问题
//引用就是防止拷贝本的产生
#include<iostream>
#include<string>
using namespace std;
class MM;
class boy;
class boy
{
public:
	void know(MM mm);
protected:

};
class MM
{
public:
	MM(string name, int age) :name(name), age(age){}
	friend void boy::know(MM mm);
protected:
	string name;
	int age;
};
void boy::know(MM mm)
{//智能检测 有时候不太好用,编译能通过就行
	cout << mm.name << "\t" << mm.age << endl;
}
int main()
{

	MM mm("po", 1001);
	boy *p = new boy;
	p->know(mm);
	delete p;
	system("pause");
	return 0;
}
