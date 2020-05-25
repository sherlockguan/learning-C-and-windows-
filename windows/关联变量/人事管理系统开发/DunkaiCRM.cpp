
// DunkaiCRM.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "DunkaiCRM.h"
#include "DunkaiCRMDlg.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDunkaiCRMApp

BEGIN_MESSAGE_MAP(CDunkaiCRMApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CDunkaiCRMApp 构造

CDunkaiCRMApp::CDunkaiCRMApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CDunkaiCRMApp 对象

CDunkaiCRMApp theApp;


// CDunkaiCRMApp 初始化

BOOL CDunkaiCRMApp::InitInstance()
{
	CWinApp::InitInstance();

	//登录界面
	CLoginDlg loginDlg;
	if (IDCANCEL == loginDlg.DoModal())
		return TRUE;

	//主界面
	CDunkaiCRMDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

