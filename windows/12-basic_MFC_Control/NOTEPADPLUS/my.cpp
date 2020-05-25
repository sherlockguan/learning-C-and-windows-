#include "stdafx.h"
#include "mychar.h"


Tchar::Tchar()
{
	str = NULL;
	wstr = NULL;
	utf8 = NULL;
}


Tchar::~Tchar()
{
	if (str)
	{
		delete str;
		str = NULL;
	}

	if (wstr)
	{
		delete wstr;
		wstr = NULL;
	}

	if (utf8)
	{
		delete utf8;
		utf8 = NULL;
	}
}


//ANSIתUnicode
wchar_t* Tchar::AnsiToUnicode(char* str)
{
	if (wstr)
	{
		delete wstr;
		wstr = NULL;
	}

	int length = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL,0);

	wstr = new wchar_t[length];
	if (wstr == NULL)
		return NULL;

	MultiByteToWideChar(CP_ACP, 0, str, -1, wstr, length);
	return wstr;
}

//UnicodeתANSI
char* Tchar::UnicodeToAnsi(wchar_t* wstr)
{
	if (str)
	{
		delete str;
		str = NULL;
	}

	int length = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	
	str = new char[length];
	if (str == NULL)
		return NULL;

	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, length, NULL, NULL);
	return str;
}

//ANSIתUTF-8
char* Tchar::AnsiToUtf8(char* str)
{
	if (wstr)
	{
		delete wstr;
		wstr = NULL;
	}

	if (utf8)
	{
		delete utf8;
		utf8 = NULL;
	}

	//ANSI=>Unicode
	wstr = AnsiToUnicode(str);

	//Unicode=>UTF8
	utf8 = UnicodeToUtf8(wstr);

	return utf8;
}

//UTF-8תANSI
char* Tchar::Utf8ToAnsi(char* utf8)
{
	if (wstr)
	{
		delete wstr;
		wstr = NULL;
	}

	if (str)
	{
		delete str;
		str = NULL;
	}

	//UTF8=>Unicode
	wstr = Utf8ToUnicode(utf8);

	//Unicode=>ANSI
	str = UnicodeToAnsi(wstr);
	return str;
}

//UnicodeתUTF-8
char* Tchar::UnicodeToUtf8(wchar_t* wstr)
{
	if (utf8)
	{
		delete utf8;
		utf8 = NULL;
	}

	int length = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);

	utf8 = new char[length];
	if (utf8 == NULL)
		return NULL;

	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8, length, NULL, NULL);

	return utf8;
}

//UTF-8תUnicode
wchar_t* Tchar::Utf8ToUnicode(char* utf8)
{
	if (wstr)
	{
		delete wstr;
		wstr = NULL;
	}

	int length = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);

	wstr = new wchar_t[length];
	if (wstr == NULL)
		return NULL;

	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, length);

	return wstr;
}