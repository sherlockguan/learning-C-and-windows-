#include <stdio.h>
#include "Tchar.h"

//typedef unsigned short wchar_t;

int main()
{
	//���ֽ�(ANSI����)��Unicode����
	//char ch = 'A';	
	//wchar_t wch = L'W';	

	//TEXT �ȼ���  __TEXT  �����Զ���Ӧ���̵��ַ�������
	//_T �ȼ��� __T  MFC�У������Զ���Ӧ���̵��ַ�������


	//wchar_t arr[] = L"123456";


	//Windows API���� 

	//Unicode�汾������CreateWindowW
	//ANSI�汾������CreateWindowA
	//Windows API���棬Windowsʵ���ṩ�������汾�ĺ���
	//CreateWindow ��ֻ��һ���궨�壬���Ǻ�����
	//DialogBox

	//C���Կ⺯����
	//ANSI�汾������strlen ,strcpy , strcat
	//Unicode�汾������wcslen, wcscpy, wcscat


	//�ַ�����ת������
	//ANSIתUnicode

	char str[] = "Unicode�汾������wcslen, wcscpy, wcscat";

	Tchar t;
	wchar_t* wstr = t.AnsiToUnicode(str);

	//UnicodeתANSI
	wchar_t wstr2[] = L"�߳� 0x4be0 ���˳�������ֵΪ 0 (0x0)��";	
	char* str2 = t.UnicodeToAnsi(wstr2);

	//ANSIתUTF-8
	char str3[] = "�޷����һ�� PDB �ļ���";
	char* utf8_3 = t.AnsiToUtf8(str3);

	//UTF-8תANSI
	//UnicodeתUTF-8
	//UTF-8תUnicode
	



	return 0;
}