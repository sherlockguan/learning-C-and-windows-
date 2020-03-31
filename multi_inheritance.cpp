//父类的私有属性 不会继承给子类， 私有权限高于继承权限
//2.子类构造函数写法:必须参数列表初始化：初始自己数据 和初始继承下来的数据，父类的数据必须父类构造函数
//子类构造函数必须调用父类构造函数
//继承具有传递性 A->B->C , 弊端 扩充类越来越大，所以继承不宜过长
//3.谁访问谁：指针
//单亲家庭： 单继承
////关于子类想构造无参对象-》父类中必须存在无参构造函数 所以用缺省的方法写是最好的
#include<iostream>
#include<string>
using namespace std;
//一个子类继承了两个及以上的类 李王玲，多继承
class girl
{
public:
	girl(string girlFirst, string girlSecond)
	{
		this->girlFirst = girlFirst;
		this->girlSecond = girlSecond;
	}
	void showGirl()
	{
		cout << "mother: " << girlFirst + girlSecond << endl;
	}
protected:
	string girlFirst;
	string girlSecond;
};
class boy
{
public:
	boy(string boyFirst, string boySecond)
	{
		this->boyFirst = boyFirst;
		this->boySecond = boySecond;
	}
	void showBoy()
	{
		cout << "father： " <<boyFirst + boySecond<< endl;
	}
protected:
	string boyFirst;
	string boySecond;
};
class son :public boy, protected girl//权限举例罢了
{
public:
	son(string boyFirst, string boySecond, string girlFirst, string girlSecond, string sonName)
		:boy(boyFirst, boySecond), girl(girlFirst, girlSecond), sonName(sonName)
	{

	}
	void showSon()
	{
		cout << boyFirst + girlFirst + sonName << endl;
	}
	void showGirlInfo()
	{
		showGirl();//因为protected是最低权限
	}
protected:
	string sonName;
};
int main()
{
	son object("guan", "gang", "li", "mei", "baobao");
	object.showBoy();
	object.showSon();
	//object.showGirl()虽然 girl 里面是共有属性，但以保护类型继承了，所以没有共有接口的话不能直接访问
	object.showGirlInfo();//有接口函数就可以了
	system("pause");
	return 0;
}//菱形 A父 ， B C 为两子 ， D 为 BC的子， 要用virtual 函数A里面变量的值，只与A 有关，BC不能给初始化，无效


