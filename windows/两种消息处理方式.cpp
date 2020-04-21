#include <Windows.h>
#include "resource.h"
#define UM_TEST				WM_USER+1				//用户自定义消息 ，测试消息

//LRESULT	:  long
//UINT		:  unsigned int
//WPARAM	:  unsigned int
//LPARAM	:  long
//LPSTR		:  char*
//LPCWSTR	:  const wchar_t *
//LPCTSTR	:  const wchar_t * (Unicode)
//WORD		:  unsigned short
//DWORD		:  unsigned long


//窗口处理函数
//第一个参数：当前窗口句柄
//第二个参数：消息类型
//第三个参数：附加信息/附加参数
//第四个参数：附加信息/附加参数

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//创建一个窗口
	//流程
	//1.设计窗口类

	/*
	typedef struct tagWNDCLASSW {
	UINT        style;
	WNDPROC     lpfnWndProc;
	int         cbClsExtra;
	int         cbWndExtra;
	HINSTANCE   hInstance;
	HICON       hIcon;
	HCURSOR     hCursor;
	HBRUSH      hbrBackground;
	LPCWSTR     lpszMenuName;
	LPCWSTR     lpszClassName;
	}

	WNDPROC  函数指针类型

	//WNDPROC		typedef LRESULT (CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

	*/

	wchar_t szAppClassName[] = TEXT("DunkaiEDU");

	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	//窗口类的风格
	wc.lpfnWndProc = WindowProc;		//窗口回调函数/窗口处理函数 
	wc.cbClsExtra = 0;					//窗口类的附加内存大小
	wc.cbWndExtra = 0;					//窗口附加内存大小
	wc.hInstance = hInstance;			//当前应用程序实例句柄
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));		//图标句柄
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	//光标句柄
	wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 0));	//红，绿，蓝 0->255	0:最暗, 255:最亮, RGB(0,0,0)：黑色， RGB(255,255,255):白色
	wc.lpszMenuName = NULL;									//菜单名
	wc.lpszClassName = szAppClassName;						//窗口类型名 Spy++

	//2.注册窗口类
	//ATOM 
	//ATOM
	if (0 == RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("此程序不能运行在Windows NT平台."), TEXT("提示"), MB_OK);
		return 0;
	}

	//3.创建窗口
	//WS: Window Style
	HWND hWnd = CreateWindow
		(
		szAppClassName,															//窗口类型名
		TEXT("这是我的第一个Windows窗口程序"),										//窗口左上角标题
		WS_BORDER | WS_CAPTION | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SYSMENU,	//窗口的风格
		200, 300,				//窗口左上角坐标
		800, 600,					//窗口的宽和高
		NULL,							//父窗口句柄
		NULL,						//菜单句柄
		hInstance,			//应用程序实例句柄
		(void*)100;	//this指针		//创建窗口的附加参数，WM_CREATE消息，lParam来接受这个参数
		);

	if (hWnd == NULL)
	{
		MessageBox(NULL, TEXT("创建窗口失败"), TEXT("提示"), MB_OK);
		return 0;
	}

	//4.显示窗口
	//SW_SHOW:原来在什么位置，就在什么位置显示
	//SW_SHOWMAXIMIZED:最大化显示
	//SW_SHOWMINIMIZED:最小化显示
	//SW_SHOWNORMAL:正常显示
	//SW_HIDE:隐藏运行

	ShowWindow(hWnd, SW_SHOW);
	//5.更新窗口 //窗口显示的时候，重新绘制一下
	UpdateWindow(hWnd);
	//6.消息循环
	/*typedef struct tagMSG {
	HWND        hwnd;			//消息发向窗口的窗口句柄
	UINT        message;		//消息编号
	WPARAM      wParam;			//附加信息
	LPARAM      lParam;			//附加信息
	DWORD       time;			//消息放入消息队列的时间
	POINT       pt;				//消息放入消息队列时鼠标坐标
	}*/
	//Windows程序都是通过消息机制驱动运行

	//GetMessage：什么时候返回FALSE 
	//当获取到WM_QUIT消息时，返回FALSE,退出循环，没有获取到这个消息，返回非0，不退出循环

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))  //0
	{
		//将虚拟键消息转化为字符消息 
		//一个按下消息+抬起消息=》字符消息，WM_KEYDOWN和WM_KEYUP=>WM_CHAR
		TranslateMessage(&msg);
		//将消息分发给窗口处理函数
		DispatchMessage(&msg);
	}

	return 0;
}

//窗口处理函数
//Windows Message缩写
//消息分为两类：
//不进队列消息 WM_CREATE
//进队列消息 ：大部分消息时属于这一类

//WM_CREATE消息
//WPARAM: 没有实用的
//LPARAM: CREATESTRUCT结构体指针

//WM_CLOSE消息 窗口关闭消息 ， 此时还能还原出来窗口
//发生在：点击关闭按钮的时候
//WPARAM: 没有实用的
//LPARAM: 没有实用的

//WM_DESTROY消息 表示窗口销毁消息， 凡是执行到了WM_DESTROY消息了，那么此时此时已经没有回头路了，不能还原窗口了，因为界面已经被销毁了
//发生在什么时候：程序退出，进行清理工作了

//WM_LBUTTONDOWN鼠标左键点击客户区消息
//WPARAM:
//LPARAM:

//WM_LBUTTONUP:鼠标左键抬起

//WM_RBUTTONDOWN:鼠标右键按下

//WM_RBUTTONUP:鼠标右键抬起

//WM_LBUTTONDBLCLK://鼠标左键双击消息

//WM_MOUSEMOVE:鼠标移动消息

//WM_KEYDOWN：键盘按下消息
//WPARAM:
//LPARAM:
/*
Value Description
0–15 Specifies the repeat count for the current message. The value is the number of times the keystroke is auto-repeated as a result of the user holding down the key. If the keystroke is held long enough, multiple messages are sent. However, the repeat count is not cumulative.
16–23 Specifies the scan code. The value depends on the original equipment manufacturer (OEM).
24 Specifies whether the key is an extended key, such as the right-hand alt and ctrl keys that appear on an enhanced 101- or 102-key keyboard. The value is 1 if it is an extended key; otherwise, it is 0.
25–28 Reserved; do not use.
29 Specifies the context code. The value is always 0 for a WM_KEYDOWN message.
30 Specifies the previous key state. The value is 1 if the key is down before the message is sent, or it is 0 if the key is up.
31 Specifies the transition state. The value is always 0 for a WM_KEYDOWN message.

*/

//WM_KEYUP：按键抬起消息


//WM_CHAR：字符消息


//后续讲解
//WM_COMMAND消息
//WM_SYSCOMMAND消息

//消息的分类：0=>65535

//1、系统消息	， 刚才介绍的这一些都是系统消息
//WM_USER	1024以下的定义的是系统消息
//1024以上的是用户自定消息

//2、自定义消息
//如果自定义消息
//宏定义

//3.发送消息
//既可以发送系统消息，又可以发送用户自定义消息
//SendMessage: 是一个阻塞函数，如果发送的消息没有没出完，则不返回，处理完成，返回结果，并且结果就是SendMessage的返回值
//PostMessage：是一个非阻塞函数，只负责把消息发过去，不会等待消息的处理完成的结果

//SendMessage：用于自己进程发送消息
//PostMessage：向进程外发送信息

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hDC;

	wchar_t szMsg[200];
	//sprintf字符串格式化函数，窄字符
	wsprintf(szMsg, L"窗口句柄:0X%x\t消息:0X%x\twParam:%d\tlParam:%d\n", hWnd, uMsg, wParam, lParam);//字符串格式化函数，宽字符
	OutputDebugString(szMsg);//仅限于调试

	switch (uMsg)
	{
	case WM_CREATE://窗口处理消息，发生在什么时候：窗口还没有显示的时候，通过调用CreateWindow函数或者CreateWindowEx函数，发出这个消息
	{
					   //MessageBox(NULL, L"这是WM_CREATE消息", L"提示", MB_OK);//阻塞函数，不点不往下走
					   CREATESTRUCT *pcs = (CREATESTRUCT*)lParam;
					   break;
	}
	case WM_LBUTTONDOWN://鼠标左键点击客户区消息
	{
							////MessageBox(hWnd, L"WM_LBUTTONDOWN", L"提示", MB_OK);
							//int xPos = LOWORD(lParam); //WORD：字，unsigned short , 0-》65535
							//int yPos = HIWORD(lParam);

							//wchar_t szText[100];
							//wsprintf(szText, L"当前鼠标点击坐标(%d,%d)", xPos, yPos);

							//if (wParam & MK_CONTROL) //按位&
							//{
							//	wcscat(szText, L"按下了Ctrl;");
							//}
							//if (wParam & MK_LBUTTON)
							//{
							//	wcscat(szText, L"按下了鼠标左键;");
							//}
							//if (wParam & MK_MBUTTON)
							//{
							//	wcscat(szText, L"按下了鼠标中键;");
							//}
							//if (wParam & MK_RBUTTON)
							//{
							//	wcscat(szText, L"按下了鼠标右键;");
							//}
							//if (wParam & MK_SHIFT)
							//{
							//	wcscat(szText, L"按下了鼠标Shift;");
							//}
							//
							////把坐标设置到窗口的标题
							//SetWindowText(hWnd, szText);

							//发送系统消息
							//SendMessage(hWnd, WM_CLOSE, 0, 0);
							//SendMessage(hWnd, WM_DESTROY, 0, 0);
							//SendMessage(hWnd, WM_KEYDOWN, VK_SPACE, 0);

							//PostMessage(hWnd, WM_CLOSE, 0, 0);
							//PostMessage(hWnd, WM_DESTROY, 0, 0);
							//PostMessage(hWnd, WM_KEYDOWN, VK_TAB, 0);
							//SendMessage(hWnd, WM_KEYDOWN, VK_TAB, 0);

							//发送一个用户自定义消息
							//BOOL b = PostMessage(hWnd, UM_TEST, 45, 50);
							//int a = 20;

							HWND hNotepad = FindWindow(L"Notepad", L"无标题 - 记事本");
							if (hNotepad == NULL)
							{
								MessageBox(NULL, L"没有查找到窗口", L"提示", MB_OK);
								break;
							}

							//发送一个关闭消息
							SendMessage(hNotepad, WM_CLOSE, 0, 0);


							break;
	}
	case UM_TEST://用户自定义消息 
	{
					 int a = (int)wParam;
					 int b = (int)lParam;

					 int result = a + b;
					 return result;
	}
		//case WM_LBUTTONUP://鼠标左键抬起
		//{
		//	break;
		//}
		//case WM_RBUTTONDOWN://鼠标右键按下
		//{
		//	break;
		//}
		//case WM_RBUTTONUP://右键抬起
		//{	
		//	break;
		//}
		//case WM_LBUTTONDBLCLK://鼠标左键双击消息
		//{
		//	SetWindowText(hWnd, L"双击了");
		//	break;
		//}
	case WM_MOUSEMOVE://鼠标移动消息
	{
						  int xPos = LOWORD(lParam); //WORD：字，unsigned short , 0-》65535
						  int yPos = HIWORD(lParam);

						  wchar_t szText[100];
						  wsprintf(szText, L"当前鼠标点击坐标(%d,%d)", xPos, yPos);

						  if (wParam & MK_CONTROL) //按位&
						  {
							  wcscat(szText, L"按下了Ctrl;");
						  }
						  if (wParam & MK_LBUTTON)
						  {
							  wcscat(szText, L"按下了鼠标左键;");
						  }
						  if (wParam & MK_MBUTTON)
						  {
							  wcscat(szText, L"按下了鼠标中键;");
						  }
						  if (wParam & MK_RBUTTON)
						  {
							  wcscat(szText, L"按下了鼠标右键;");
						  }
						  if (wParam & MK_SHIFT)
						  {
							  wcscat(szText, L"按下了鼠标Shift;");
						  }

						  //把坐标设置到窗口的标题
						  //SetWindowText(hWnd, szText);

						  break;
	}
	case WM_KEYDOWN://键盘按下消息
	{
						//MessageBox(hWnd, L"提示", L"OK", MB_OK);
						switch (wParam)
						{
						case VK_RETURN://回车键
							SetWindowText(hWnd, L"按下了回车键");
							break;
						case VK_SPACE://空格键
							SetWindowText(hWnd, L"按下了空格键");
							break;
						case VK_ESCAPE://ESC键
							SetWindowText(hWnd, L"按下了ESC键");
							break;
						case VK_SHIFT://Shift键
							SetWindowText(hWnd, L"按下了Shift键");
							break;
						case VK_TAB://Tab键
							SetWindowText(hWnd, L"按下了Tab键");
							break;
						case VK_F1://F1键
							SetWindowText(hWnd, L"按下了F1键");
							break;
						case 0x41://A键
							SetWindowText(hWnd, L"按下了A键");
							break;
						case 0x30://0键
							SetWindowText(hWnd, L"按下了0键");
							break;
						case VK_NUMPAD0://右边的0键
							SetWindowText(hWnd, L"按下了右边的0键");
							break;
						case VK_UP://上
							break;
						case VK_DOWN://下
							break;
						case VK_LEFT://左
							break;
						case VK_RIGHT://右
							break;
						}
						break;
	}
	case WM_CHAR://字符消息
	{
					 char chCharCode = (TCHAR)wParam;

					 wchar_t szText[100];
					 wsprintf(szText, L"当前字符:%c", chCharCode);
					 SetWindowText(hWnd, szText);
					 break;
	}
	case WM_PAINT://客户区绘图消息, GDI绘图技术
	{
					  //开始绘图
					  HDC hDC = BeginPaint(hWnd, &ps);
					  //Rectangle(hDC, 0, 0, 200, 200);
					  //绘制椭圆
					  Ellipse(hDC, 0, 0, 300, 200);
					  //结束绘图
					  EndPaint(hWnd, &ps);
					  break;
	}
	case WM_CLOSE://窗口关闭消息
	{

					  //ShowWindow(hWnd, SW_HIDE);//隐藏
					  //return 1;//表示我已经处理了

					  if (IDYES == MessageBox(hWnd, L"您确定要关闭吗？", L"温馨提示", MB_YESNO))//大窗口句柄hwnd作为msgbox的父亲
					  {
						  DestroyWindow(hWnd);	//销毁窗口， 干掉界面，不会发出WM_QUIT，会发出一个WM_DESTROY消息
					  }
					  else
					  {
						  //break;//还是执行了DefWindowProc系统默认处理，界面销毁，不会退出进程
						  //return 0;//没有处理，没有人去处理
						  return 1;//我已经处理了，
					  }
					  break;
	}
	case WM_DESTROY://窗口销毁消息
		//ShowWindow(hWnd, SW_SHOW);		//无力回天了
		PostQuitMessage(0);		//发出WM_QUIT
		break;

	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);//交给操作系统默认处理
}

