// ChatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Demo.h"
#include "ChatDlg.h"
#include "afxdialogex.h"


// CChatDlg 对话框

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


// CChatDlg 消息处理程序


void CChatDlg::PostNcDestroy()
{
	//delete this; //仅适用于new

	CDialogEx::PostNcDestroy();
}


void CChatDlg::OnBnClickedCancel()
{
	EndDialog(IDOK);

	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
}
