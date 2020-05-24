#include <stdio.h>
#include "Tchar.h"

//typedef unsigned short wchar_t;

int main()
{
	//多字节(ANSI编码)和Unicode编码
	//char ch = 'A';	
	//wchar_t wch = L'W';	

	//TEXT 等价于  __TEXT  他是自动适应工程的字符集编码
	//_T 等价于 __T  MFC中，他是自动适应工程的字符集编码


	//wchar_t arr[] = L"123456";


	//Windows API函数 

	//Unicode版本函数：CreateWindowW
	//ANSI版本函数：CreateWindowA
	//Windows API里面，Windows实际提供了两个版本的函数
	//CreateWindow ：只是一个宏定义，不是函数名
	//DialogBox

	//C语言库函数中
	//ANSI版本函数：strlen ,strcpy , strcat
	//Unicode版本函数：wcslen, wcscpy, wcscat


	//字符集的转化问题
	//ANSI转Unicode

	char str[] = "Unicode版本函数：wcslen, wcscpy, wcscat";

	Tchar t;
	wchar_t* wstr = t.AnsiToUnicode(str);

	//Unicode转ANSI
	wchar_t wstr2[] = L"线程 0x4be0 已退出，返回值为 0 (0x0)。";	
	char* str2 = t.UnicodeToAnsi(wstr2);

	//ANSI转UTF-8
	char str3[] = "无法查找或打开 PDB 文件。";
	char* utf8_3 = t.AnsiToUtf8(str3);

	//UTF-8转ANSI
	//Unicode转UTF-8
	//UTF-8转Unicode
	



	return 0;
}