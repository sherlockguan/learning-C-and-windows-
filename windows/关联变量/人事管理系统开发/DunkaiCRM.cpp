
// DunkaiCRM.cpp : ����Ӧ�ó��������Ϊ��
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


// CDunkaiCRMApp ����

CDunkaiCRMApp::CDunkaiCRMApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CDunkaiCRMApp ����

CDunkaiCRMApp theApp;


// CDunkaiCRMApp ��ʼ��

BOOL CDunkaiCRMApp::InitInstance()
{
	CWinApp::InitInstance();

	//��¼����
	CLoginDlg loginDlg;
	if (IDCANCEL == loginDlg.DoModal())
		return TRUE;

	//������
	CDunkaiCRMDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

