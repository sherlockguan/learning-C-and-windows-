// ChatDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Demo.h"
#include "ChatDlg.h"
#include "afxdialogex.h"


// CChatDlg �Ի���

IMPLEMENT_DYNAMIC(CChatDlg, CDialogEx)

CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChatDlg::IDD, pParent)
{

}

CChatDlg::~CChatDlg()
{
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChatDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CChatDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CChatDlg ��Ϣ�������


void CChatDlg::PostNcDestroy()
{
	//delete this; //��������new

	CDialogEx::PostNcDestroy();
}


void CChatDlg::OnBnClickedCancel()
{
	EndDialog(IDOK);

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
}
