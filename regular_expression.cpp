#include <iostream>
#include <regex>
/*
	正则匹配
	正则替换
	正则表达式的基本组成
		常用的:
			次数类:
				{n}		: 出现的次数  "o{2}" love: 匹配上
				{n,}	: 至少出现n次
				{n,m}   : 至少出现n次最多m次
				+		: 至少出现一次  {1,}
				*		：0次或者多次   {0,}
				?		: {0,1}
			特殊字符:
				\		: \n   字符串\变为\\
				^		:开始的地方匹配\n \r  (shitf+^)
				$		:结尾匹配\n \r       (shit+4)
			子集问题:
			   ()       :字符串一部分
			   []		:范围  [abc]  --->plain    [^abc] :abc之外的
			   [a-z]	:a到z之间字母
			正则的转义字符：
				\d		:所有数字   [0-9]
				\D		:所有数字之外 字符 [^0-9]
				\w		:字母数字下划线  [A-Za-z0-9_]
				\W		:除了字母数字下划线之外的字符
			逻辑运算:
						|:  x|y  匹配一个即可
		注意点： 任何字符串都可以当做正则表达式 ,必须完全匹配

		正则匹配常用函数:
		匹配:regex_match()  0:不匹配 1:匹配
		查找:regex_search() 查找
		替换:regex_replace()
	基本操作：
	<1>.构建正则对象
	<2>.调用相应正则函数做相应的功能即可

*/

using namespace std;
int main()
{
	char userName[] = "myFood";
	//1.正则匹配
	cout << regex_match(userName, regex("myFood|o")) << endl;
	//2.正则替换
	string  str = { "我爱你,但是你不爱我,我爱你,你却爱着他!" };
	//2.1 修改所有的满足匹配项的
	regex love("我爱你");
	cout << regex_replace(str, love, "I Love you");
	//2.2 英文 ：忽略大写 正则表达式加一个regex::icase;
	string text = { "I Love you,but you  don't LOVE me!" };
	cout << regex_replace(text, regex("love", regex::icase), "like") << endl;
	regex object("^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"); 
	char Email[20];
	while (1)
	{
		cin >> Email;
		bool result = regex_match(Email, object);
		if (result == 0)
		{
			cout << "这不是邮箱!" << endl;
		}
		else
		{
			cout << "邮箱！！" << endl;
		}
	}
	system("pause");
	return 0; 
}
