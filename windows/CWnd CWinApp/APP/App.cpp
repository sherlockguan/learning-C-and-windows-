
// App.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "App.h"
#include "AppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAppApp

BEGIN_MESSAGE_MAP(CAppApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CAppApp 构造

CAppApp::CAppApp() :CWinApp(L"DunkaiEDU")
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CAppApp 对象

CAppApp theApp;


// CAppApp 初始化

BOOL CAppApp::InitInstance()
{
	//m_pszAppName = L"123456";//引起中断的原因，通过构造函数传参，解决这个问题

	CWinApp::InitInstance();

	
	//SetRegistryKey(_T("DunkaiEDU"));  //注释掉这里写了配置文件

	CAppDlg dlg;
	m_pMainWnd = &dlg;//m_pMainWnd这个成员，记录了主窗口指针
	dlg.DoModal();
	
	//AfxGetMainWnd();			//获取主窗口
	//AfxGetInstanceHandle();	//返回的是实例句柄 m_hInstance
	//AfxGetApp()				//theApp的对象指针
	//AfxMessageBox()
	//AfxGetAppName();			//返回m_pszAppName

	//theApp.m_lpCmdLine;

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return TRUE;
}


//Pre前置

BOOL CAppApp::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类

	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN))
	{
		return TRUE;
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_DOWN)
	{
		AfxMessageBox(L"按下");
	}

	return CWinApp::PreTranslateMessage(pMsg);
}
