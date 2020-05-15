//之前讲的是通用窗口创建流程，比较繁琐，窗口的底层原理
//今天对话框窗口（模态：阻塞；打开后必须操作完成后才可以操作其他窗口 
		//非模态：互不影响的窗口）
#include<windows.h>
#include"resource.h"
//对话框处理函数
BOOL CALLBACK DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{//DIALOGBOX阻塞函数
	//模态对话框modal: 参数 HINSTANCE hInstance, LPCTSTR lpTemplate(右键添加资源DIALOG,右键属性)，HWND hWndParent, 函数名是函数指针DLGPROC lpDialogFunc
	int result = DialogBox(hInstance,MAKEINTRESOURCE(IDD_MAIN_DLG),NULL,DialogProc);
	/*if (result == IDOK)
	{
		MessageBox(NULL, L"点了确定按钮关闭程序", L"提示", MB_OK);
	}
	else if (result == IDCANCEL)
	{
		MessageBox(NULL, L"点了取消按钮关闭", L"HINT", MB_OK);
	}*/
	return 0;
}
BOOL CALLBACK DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{//对话框处理函数
	switch (uMsg)
	{
	case WM_INITDIALOG://对话框初始化消息,发生在对话框窗口已经创建好了，子控件也已经创建好了，还没显示出来而已
		SetWindowText(hWnd,L"这是我的win32对话框窗口");
		break;
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
