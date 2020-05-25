// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DunkaiCRM.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
	, m_strUsername(_T("admin"))
	, m_strPassword(_T("123456"))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, m_strUsername);
	DDX_Text(pDX, IDC_PASSWORD, m_strPassword);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_LOGIN, &CLoginDlg::OnBnClickedBtnLogin)
	ON_BN_CLICKED(IDC_BTN_REGISTER, &CLoginDlg::OnBnClickedBtnRegister)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序

//登录
void CLoginDlg::OnBnClickedBtnLogin()
{
	UpdateData(TRUE);

	if (m_strUsername.IsEmpty() || m_strPassword.IsEmpty())
	{
		MessageBox(L"请输入用户名或密码", L"温馨提示");
		return;
	}

	if (m_strUsername == L"admin" && m_strPassword == L"123456")
	{
		EndDialog(IDOK);//关闭
	}
	else
	{
		MessageBox(L"用户名或密码错误", L"温馨提示");
		m_strPassword.Empty();
		UpdateData(FALSE);

		//设置密码的焦点
		GetDlgItem(IDC_PASSWORD)->SetFocus();

		return;
	}
}

//注册
void CLoginDlg::OnBnClickedBtnRegister()
{
	// TODO:  在此添加控件通知处理程序代码
}
