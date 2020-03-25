#include<iostream>
using namespace std;
#include<string>
struct girl
{
	string name;
	int age;
	girl(string nameA, int ageA)
	{
		name = nameA;
		age = ageA;
	}
};
int main()
{
	girl *pGirl = new girl("love", 13);//struct 中 new 的过程 就是调用构造函数的过程， 注意一致性
	girl object("object", 12);
	cout << pGirl->age << " " << pGirl->name << endl;
	cout << object.age << " " << object.name << endl;
	delete pGirl;
	system("pause");
	return 0;
}
