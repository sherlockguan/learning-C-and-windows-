
// App.cpp : ����Ӧ�ó��������Ϊ��
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


// CAppApp ����

CAppApp::CAppApp() :CWinApp(L"DunkaiEDU")
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CAppApp ����

CAppApp theApp;


// CAppApp ��ʼ��

BOOL CAppApp::InitInstance()
{
	//m_pszAppName = L"123456";//�����жϵ�ԭ��ͨ�����캯�����Σ�����������

	CWinApp::InitInstance();

	
	//SetRegistryKey(_T("DunkaiEDU"));  //ע�͵�����д�������ļ�

	CAppDlg dlg;
	m_pMainWnd = &dlg;//m_pMainWnd�����Ա����¼��������ָ��
	dlg.DoModal();
	
	//AfxGetMainWnd();			//��ȡ������
	//AfxGetInstanceHandle();	//���ص���ʵ����� m_hInstance
	//AfxGetApp()				//theApp�Ķ���ָ��
	//AfxMessageBox()
	//AfxGetAppName();			//����m_pszAppName

	//theApp.m_lpCmdLine;

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return TRUE;
}


//Preǰ��

BOOL CAppApp::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���

	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN))
	{
		return TRUE;
	}

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_DOWN)
	{
		AfxMessageBox(L"����");
	}

	return CWinApp::PreTranslateMessage(pMsg);
}
