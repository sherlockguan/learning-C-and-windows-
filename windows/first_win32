#include<Windows.h>
//做的不是CUI控制台应用程序，不用main入口 函数，是窗口应用程序GUI graphic user interface
//API 应用程序编程接口 SDK: software developement kits
//HINSTANCE:应用程序实例句柄 指针类型， 表示当前应用程序实例句柄
// hinstance； 当前应用程序实例句柄， hprehinstance:前一个。。。(废弃，16位应用程序的一个参数，写上为了前后兼容）
//严格区分大小写
//窗口：标题栏 菜单栏 系统菜单 最小化框，最大化框 边框 滚动条
//句柄用来标识系统资源
//typedef char* 是一样的 LPSTR  就是 char*,字符指针可以指向一个字符串
//IpCmdLine：命令行参数
// nCmdShow：窗口显示方式，最大化最小化隐藏
/*
#define CALLBACK/WINAPI/PASCAL/APIENTRY..都表示__stdcall windows程序的显示添加的调用约定
指函数参数的入栈方式：从右向左入栈!!!
C语言库函数默认__cdecl

struct HINSTANCE__
{
int unused;
}
typedef struct HINSTANCE_* HINSTANCE 指向结构体的指针
会查帮助文档非常重要，减少记忆量
*/
// main 的写法： WINAPI  WinMain   __stdcall...
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//弹出一个消息提示框
	//MessageBox(NULL, L"my first win32", L"hint", MB_OK | MB_ICONEXCLAMATION);
	//HWIND 窗口类型句柄
	//参数一为空 父窗口句柄，没有父窗口，hwind窗口句柄是窗口的唯一身份证，便于操作系统管理窗口
	//HWIND: declare handler:指向结构体的指针
	// 第二个参数：L：宽字符 本工程常规中Unicode，所有一致，编码问题下一课，支持世界各国语言，不会英文OS乱码
	//如果ANSI多字节编码那么不用加L,加补丁
	//第三个参数：消息框标题
	//第四个： 按钮与图标(ICON)的组合， MB_YESNO:是否两个按钮 ,MB_YESNOCANCLE 三个按钮，MB_ABORTRETR
	// MB_ICONWARNING... 文档都有不全写了  ！注意图标与图标不能组合， 按钮与按钮不行 ， 图标与按钮可以
	int result = MessageBox(NULL, L"my first win32", L"hint", MB_YESNOCANCEL | MB_ICONEXCLAMATION);
	if (result == IDOK)
	{
		MessageBox(NULL, L"you pressed the sure botton", L"hint", MB_OK);

	}
	else if (result == IDCANCEL)
	{
		MessageBox(NULL, L"you pressed the CANCEL botton", L"hint", MB_OK);
	}
	else if (result == IDYES)
	{
		MessageBox(NULL, L"you pressed the yes botton", L"hint", MB_OK);
	}
	else if (result == IDNO)
	{
		MessageBox(NULL, L"you pressed the NO botton", L"hint", MB_OK);
	}
	return 0;
}
