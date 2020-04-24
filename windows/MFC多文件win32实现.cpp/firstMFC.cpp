#include  "stdafx.h"//公用的先包含
#include "FirstMFC.h"
#include  "MainDlg.h"

BOOL CMyApp::InitInstance()//派生的目的就是重写入口虚函数
{
		CMainDlg dlg;
		dlg.DoModal();
		return TRUE;
}

CMyApp theApp;//全局的派生类对象



//单文件的写法==>大工程拆分为多文件，声明和实现在头源里面一一对应
/*
#include<afxwin.h>
#include<resource.h>
class CMainDlg:public CDialog    
{
private:
	enum{IDD = IDD_MAIN_DLG};
public:
	CMaindlg():	CDialog(IDD)  //多文件实现 CMainDlg::CMainDlg():CDialog(IDD)
	{

	}

class CMyApp:public CWinApp
{
public:
	BOOL InitInstance() //相当于main函数
	{

		CMainDlg dlg;
		dlg.DoModal();

		return TRUE;

	}
}
CMyApp theApp;



*/