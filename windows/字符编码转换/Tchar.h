#ifndef __TCHAR
#define __TCHAR



class Tchar
{
private:
	char* str;
	wchar_t* wstr;
	char* utf8;

public:
	Tchar();
	~Tchar();

	//ANSI转Unicode
	wchar_t* AnsiToUnicode(char* str);

	//Unicode转ANSI
	char* UnicodeToAnsi(wchar_t* wstr);

	//ANSI转UTF-8
	char* AnsiToUtf8(char* str);

	//UTF-8转ANSI
	char* Utf8ToAnsi(char* utf8);

	//Unicode转UTF-8
	char* UnicodeToUtf8(wchar_t* wstr);

	//UTF-8转Unicode
	wchar_t* Utf8ToUnicode(char* utf8);


	//字符集的转化问题


	//两个重要的函数
	//WideCharToMultiByte
	//MultiByteToWideChar
};

#endif