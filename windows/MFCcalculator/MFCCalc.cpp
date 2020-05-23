

#include "stdafx.h"
#include "MFCCalc.h"
#include "MFCCalcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCalcApp

BEGIN_MESSAGE_MAP(CMFCCalcApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCCalcApp 构造

CMFCCalcApp::CMFCCalcApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

}



CMFCCalcApp theApp;


BOOL CMFCCalcApp::InitInstance()
{
	
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	
	CShellManager *pShellManager = new CShellManager;

	
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));


	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CMFCCalcDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		
	}
	else if (nResponse == IDCANCEL)
	{
	
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "\n");
		TRACE(traceAppMsg, 0, "haha\n");
	}


	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	return FALSE;
}

