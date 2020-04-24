
#include"stdafx.h"
#include"MainDlg.h"
CMainDlg::CMainDlg():CDialog(IDD)
{
	m_hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_LOGO));
}
BOOL CMainDlg::OnInitDialog()//初始化的虚函数
{//标题：
	SetWindowText(L"This is MFC Dialog program");
	//设置图标
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	return TRUE;
}