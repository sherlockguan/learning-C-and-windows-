#include<Windows.h>
//窗口处理函数 LRESULT/LPARAM: long 长整型 UNIT/WPARAM:unsigned int 
//cs_HREDRAW:水平调正 classstyle
//cs_VREDRAW:竖直调整
//cs_DBLCLKS:双击
//WINDPROC 函数指针
//UNIT/WPARAM  :unsigned int
//LPARAM:long
//LPCWSTR: const wchar_t* 宽字符wide
//ATOM 是word : 字类型 占两个字节 unsigned short 也许是bug 少用
//deword：双子 unsigned long 占4个字节
//LPCTSTR unicode 环境！c:const w:wide
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lparam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{//HINSTANCE 相当于一个指针，宏定义 声明句柄
//1.设计窗口类  wndclass
	/*
	typedef struct tagWNDCLASSA {
		UINT      style;
		WNDPROC   lpfnWndProc;
		int       cbClsExtra;
		int       cbWndExtra;
		HINSTANCE hInstance;
		HICON     hIcon;
		HCURSOR   hCursor;
		HBRUSH    hbrBackground;
		LPCSTR    lpszMenuName;
		LPCSTR    lpszClassName;
	} WNDCLASSA, *PWNDCLASSA, *NPWNDCLASSA, *LPWNDCLASSA;
	*/
	wchar_t szAppClassName[] = TEXT("DunKaiEdu"); //wchar 宽字符
	WNDCLASS wc;
	
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;//ClassStyle
	wc.lpfnWndProc = WindowProc;	//窗口回调函数/窗口处理函数，消息处理原理, 函数实现在上面
	wc.cbClsExtra = 0;////窗口类附加内存大小,单位是字节，0是没分配
	wc.cbWndExtra = 0;////窗口附加内存大小
	wc.hInstance = hInstance;//winmain 当前应用程序实例句柄
	wc.hIcon = NULL;//图标句柄
	wc.hCursor = NULL;//默认没有光标，光标句柄
	wc.hbrBackground = CreateSolidBrush(RGB(255,255,0));
	//背景颜色 红绿蓝 都是 0-255 三个都为零为最暗为（0，0，0）黑，255白最亮
	wc.lpszMenuName = NULL; //菜单名
	wc.lpszClassName = szAppClassName;//winOS一切都是窗口，桌面也是窗口 用spy++查看  设计窗口类
	//2. 注册窗口类
	if (0 == RegisterClass(&wc))//0 是失败 wc取地址 第一步
	{
		MessageBox(NULL, TEXT("COULDN'T BE RUN"), TEXT("HINT"), MB_OK);
		//每一个成员都赋值 才不失败
		return 0;
	}
	//3.创建窗口
	HWND hWnd = CreateWindow(
		szAppClassName,	//窗口类型名
		TEXT("这是我的第一个Windows窗口程序"),//窗口左上角标题
		WS_BORDER | WS_CAPTION | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SYSMENU,	
		//窗口的风格
		200, 300,		//窗口左上角坐标
		800, 600,		//窗口的宽和高
		NULL,		//父窗口句柄
		NULL,				//菜单句柄
		hInstance,		//应用程序实例句柄
		NULL	//创建窗口的附加参数，WM_CREATE消息，lParam来接受这个参数
		);
	if (hWnd == NULL)
	{
		MessageBox(NULL, TEXT("创建窗口失败"), TEXT("提示"), MB_OK);
		return 0;
	}
	//4.显示窗口
	ShowWindow(hWnd, SW_SHOW);//在原位置显示
	//SW_SHOW:原来在什么位置，就在什么位置显示
	//SW_SHOWMAXIMIZED:最大化显示
	//SW_SHOWMINIMIZED:最小化显示
	//SW_SHOWNORMAL:正常显示
	//SW_HIDE:隐藏运行

	//5.更新窗口,显示窗口时重新绘制
	UpdateWindow(hWnd);
	//6消息循环
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
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//将虚拟键消息转换为字符消息	一个按下消息+抬起消息=》字符消息
		TranslateMessage(&msg);
		//将消息分发给窗口处理函数
		DispatchMessage(&msg);
	}

	return 0;
}
//BOOL: true: 1  false:0
//窗口处理函数
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lparam)
{    //LRESULT:long 长整型
	//callback回调函数
	//第一个参数：当前窗口句柄
	//第二个参数：消息类型 unsigned int  
	//第三第四个：附加参数/附加信息 当前鼠标单击的坐标
	switch (uMsg)
	{
	case WM_CLOSE://窗口关闭消息
		DestroyWindow(hWnd);	//销毁窗口， 干掉界面，不会发出WM_QUIT，会发出一个WM_DESTROY消息
		break;
	case WM_DESTROY://窗口销毁消息
		PostQuitMessage(0);		//发出WM_QUIT
		break;
	}



	return DefWindowProc(hWnd, uMsg, wParam, lparam);//交给操作系统默认处理
}

//操作系统有一个先进先出的消息队列，应用程序从消息队列里面取消息Getmessage
//将虚拟键消息转换为字符消息	一个按下消息+抬起消息=》字符消息
//将消息分发给窗口处理函数，操作系统调用窗口处理函数
