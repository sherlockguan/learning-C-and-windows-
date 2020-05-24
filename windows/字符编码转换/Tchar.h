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

	//ANSIתUnicode
	wchar_t* AnsiToUnicode(char* str);

	//UnicodeתANSI
	char* UnicodeToAnsi(wchar_t* wstr);

	//ANSIתUTF-8
	char* AnsiToUtf8(char* str);

	//UTF-8תANSI
	char* Utf8ToAnsi(char* utf8);

	//UnicodeתUTF-8
	char* UnicodeToUtf8(wchar_t* wstr);

	//UTF-8תUnicode
	wchar_t* Utf8ToUnicode(char* utf8);


	//�ַ�����ת������


	//������Ҫ�ĺ���
	//WideCharToMultiByte
	//MultiByteToWideChar
};

#endif