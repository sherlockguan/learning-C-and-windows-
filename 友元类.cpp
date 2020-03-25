#include<iostream>
#include<string>
using namespace std;
/*
友元; 赋予类打破权限的作用
友元函数，friend修饰的函数
友元类：把一个类声明为另一个类的友元，赋予其打破另一个类权限的作用
*/
class MM
{
public:
	MM(string name, int age) :name(name), age(age){}
	MM(){}
	friend class GG;
protected:
	string name;
private:
	int age;
};
class GG
{
public:
	GG(string name, int age) :mm(name, age)
	{
		cout << mm.name <<" "<< mm.age << endl;
	}
	void print()
	{//友元时赋予对象权力
		MM mygirl("mm", 18);
		cout << mygirl.name << " " << mygirl.age<<endl;
	}
	MM& getMM()
	{
		return mm;
	}
protected:
private:
	MM mm;

};

int main()
{
	GG son("hi", 17);
	//脱离了类，错 cout << son.getMM().name << son.getMM().age << endl;
  return 0;

}
