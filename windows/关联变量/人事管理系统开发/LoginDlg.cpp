// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DunkaiCRM.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg �Ի���

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


// CLoginDlg ��Ϣ�������

//��¼
void CLoginDlg::OnBnClickedBtnLogin()
{
	UpdateData(TRUE);

	if (m_strUsername.IsEmpty() || m_strPassword.IsEmpty())
	{
		MessageBox(L"�������û���������", L"��ܰ��ʾ");
		return;
	}

	if (m_strUsername == L"admin" && m_strPassword == L"123456")
	{
		EndDialog(IDOK);//�ر�
	}
	else
	{
		MessageBox(L"�û������������", L"��ܰ��ʾ");
		m_strPassword.Empty();
		UpdateData(FALSE);

		//��������Ľ���
		GetDlgItem(IDC_PASSWORD)->SetFocus();

		return;
	}
}

//ע��
void CLoginDlg::OnBnClickedBtnRegister()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
