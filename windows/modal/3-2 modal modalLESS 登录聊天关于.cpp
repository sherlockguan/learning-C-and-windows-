//之前讲的是通用窗口创建流程，比较繁琐，窗口的底层原理
//今天对话框窗口（模态model：阻塞；打开后必须操作完成后才可以操作其他窗口 
//非模态modalless：互不影响的窗口）
#include<windows.h>
#include"resource.h"
//windows遵循匈牙利命名法
/*前缀：a：数组  aData
b: 布尔类型  bFlag
n: 整形     nCmdShow
by：无符号   unsigned char= BYTE
c: 字符     char
dw：DWORD   dwThreadID (WORD= unsigned short，字)
h: 句柄		hWnd hInstance
l: long
w: WORD
sz: char[5] 字符数组
s: string
Cstring str 跟上一个区分不大
p: 指针void* 或者ptr
m_ ： 成员变量 m_nAge
g:全局变量 g_hInstance
s_:静态变量
*/

HINSTANCE g_hInstance;//所以定义全局变量(global)： 应用程序实例句柄


//非模态聊天窗口处理函数
BOOL CALLBACK ChatProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//登录对话框处理函数
BOOL CALLBACK LoginProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//主对话框处理函数
BOOL CALLBACK MainDialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//关于对话框回调函数
BOOL CALLBACK AboutProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	g_hInstance = hInstance;
	//首先弹出登录
	int result = DialogBox(hInstance, MAKEINTRESOURCE(IDD_LOGIN_DLG), NULL, LoginProc);

	if (result == IDC_BTN_LOGIN)
	{ //登录成功 弹出主对话框
		DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN_DLG), NULL, MainDialogProc);
	}
	//DIALOGBOX阻塞函数
	//模态对话框modal: 参数 HINSTANCE hInstance, LPCTSTR lpTemplate(右键添加资源DIALOG,右键属性)，HWND hWndParent, 函数名是函数指针DLGPROC lpDialogFunc

	return 0;
}
BOOL CALLBACK MainDialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{//主对话框处理函数
	switch (uMsg)
	{
	case WM_INITDIALOG:
		//对话框初始化消息,发生在对话框窗口已经创建好了，子控件也已经创建好了，还没显示出来而已
	{
		SetWindowText(hWnd, L"这是我的win32对话框窗口");
		//加载图标

		//下面用到hinstance 所以定义全局变量： 应用程序实例句柄
		HICON hIcon1 = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_ICON1));
		//HICON hIcon2 = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_ICON2));
		//发送消息
		SendMessage(hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon1);//hIcon强制转换(handle to icon) //大图标设置成功
		//SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon2);
		//半透明风格设置
		SetLayeredWindowAttributes(hWnd, RGB(240, 240, 240), 120, LWA_ALPHA);
		break;
	}
	case WM_DROPFILES://属性 acceptefile->TRUE 拖拽文件消息,能够获取文件路径hDrop句柄

	{	 wchar_t szFilePath[MAX_PATH];//路径大小 字符数组
	HDROP hDrop = (HDROP)wParam;
	//首先查询共拖拽了几个文件
	int nCount = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);
	for (int i = 0; i < nCount; i++)
	{
		DragQueryFile(hDrop, i, szFilePath, MAX_PATH);
		MessageBox(hWnd, szFilePath, L"HINT", MB_OK);//阻塞函数

	}


	break;
	}
	case WM_COMMAND:
	{
					   //菜单 控件 快捷键,case里面定义变量一定要写花括号,不能具体分辨
					   //MessageBox(hWnd, L"有命令", L"hint", MB_OK);
					   int wID = LOWORD(wParam);
					   switch (wID)
					   {
					   case IDOK:
						   SetWindowText(hWnd, L"点了确定按钮");
						   break;
					   case IDCANCEL:
						   EndDialog(hWnd, IDCANCEL);
						   //or SendMessage(hWnd,WM_CLOSE,0,0);
						   break;
						   //关于按钮, 父亲是主对话框句柄hWnd,不是NULL
					   case IDC_BTN_ABOUT:
						   DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_ABOUT_DLG), hWnd, AboutProc);
						   break;
					   case IDC_BTN_CHAT://聊天按钮
						   //非模态 CreateDialog(返回窗口句柄成功）, DestroyWindow
					   {	HWND hChatWnd = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_CHAT_DLG), hWnd, ChatProc);
					   ShowWindow(hChatWnd, SW_SHOW);//必须
					   break;
					   }


					   }
					   break;


	}

	case WM_CLOSE://窗口关闭消息
		//DestroyWindow(hWnd);
		EndDialog(hWnd, IDOK);
		break;// 或者 return True

		//case WM_DESTROY:
		//	EndDialog(hWnd, IDOK);//销毁消息，结束对话框
		//	break;
	}
	return FALSE;//交给系统默认处理
	//true 自己已经处理了
}
BOOL CALLBACK AboutProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		EndDialog(hWnd, IDCANCEL);
		return TRUE;
	}

	return FALSE;//响应一下消息，没有处理的全部交给系统处理
}

BOOL CALLBACK LoginProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))//手册 表示ID
		{
		case IDC_BTN_LOGIN:
		{
			//获取用户名和密码
			wchar_t szUsername[20], szPassword[20];
			GetDlgItemText(hWnd, IDC_USERNAME, szUsername, 20);
			GetDlgItemText(hWnd, IDC_PASSWORD, szPassword, 20);
			//宽字符 字符串比较
			if (wcscmp(szUsername, L"admin") == 0 && wcscmp(szPassword, L"123456") == 0)
			{
				//关闭登录框 进入主对话框
				EndDialog(hWnd,IDC_BTN_LOGIN);
				return TRUE;
			}
			else
			{
				MessageBox(hWnd, L"用户名或者密码错误", L"HINT", MB_OK);
				return TRUE;//表示我处理了
			}
			break;
		}
		case IDCANCEL:
			EndDialog(hWnd, IDCANCEL);
			return TRUE;
		}
		break;
	}
	case WM_CLOSE://窗口关闭消息
		//DestroyWindow(hWnd);
		EndDialog(hWnd, IDC_BTN_LOGIN);
		break;// 或者 return True
	}
	return FALSE;
}

BOOL CALLBACK ChatProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);//非模态关闭方法, enddialog 只是隐藏
		break;
	}

	return FALSE;
}
