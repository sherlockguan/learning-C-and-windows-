#include<iostream>
#include<string>
#include<cstring>//C语言字符串处理函数
using namespace std;
int size = 0;//全局变量
bool empty()
{
	return size == 0;
}
//6.结构体改变之一允许存在函数

struct girl
{
	char name[20];//数据成员：属性
	int age;
	void print()//成员函数：行为
	{
		cout << name << " " << age << endl;
	}
};
int main()
{
	bool boolNum = 1;
	// 开关 函数返回值， 特殊初始化用False ，True
	//只要非零表示成立， 只有零是表示不成立
	//2.指针赋值变为 nullptr 空
	int *ptr = nullptr;
	//3.动态内存申请由malloc free 变为 new delete
	ptr = new int;
	delete ptr;
	  //3.2分配一段内存
	int *array = new int[10];
	delete[] array;
	 //3.3 申请内存并且初始化
	int *pInt = new int(12);//普通变量用括号初始化
	int *pArray = new int[3]{1, 2, 3};//一段内存大括号初始化
	delete pInt;
	delete pArray;
	//4.内存池;申请的内存可以再分配
	char *malloc = new char[1024];
	int *pIntNum = new(malloc)int;//从已申请的char中再申请int4字节,pIntNum 指向malloc首地址
	//从原来的char+4之上再分配
	char *charArray = new(malloc + 4)char[100];
	//一段内存不要释放多次
	delete[] malloc;//释放总内存即可
	//5.输入和输出 printf --》 cout<<; scanf -- cin>>,不需要格式控制字符
	//单个数据的输入输出
	int num = 0;
	char str[20] = "";
	printf("请输入一个数据");
	cin >> num;
	cout << num;
	printf("请输入一个字符串");
	//5.2cout的原样输出
	cout << "I LOVE You\n";
	cout << "i love you" << num << "\t" << str << endl;//endl清空缓冲区并且换行\n
	cin >> num >> str;
	cout << num << "\t" << str << endl;
	//6.结构体数据的改变
	///6.2 用到结构体类型不需要struct
	girl MYgirl = { "baby", 18 };//按照内存排布顺序初始化
	MYgirl.print();//访问函数
//string 类型基本使用,并不是C语言字符串,不用字符串处理函数简化了
	string str1;
	string str2("I love C++");
	string str3 = "love";
	string str4 = str2 + str3;
	cout << (str4 > str) << endl;
	//c++语言的string 转化为c语言的字符串，否则乱码
	printf("\n%s\n", str4.c_str());

	system("pause");
	return 0;
}
