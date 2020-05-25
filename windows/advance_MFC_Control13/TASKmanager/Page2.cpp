// Page2.cpp : 实现文件
//

#include "stdafx.h"
#include "TaskManager.h"
#include "Page2.h"
#include "afxdialogex.h"


// CPage2 对话框

IMPLEMENT_DYNAMIC(CPage2, CDialogEx)

CPage2::CPage2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage2::IDD, pParent)
{

}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage2, CDialogEx)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CPage2 消息处理程序


BOOL CPage2::OnEraseBkgnd(CDC* pDC)
{
	//获取对话框的客户区大小
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(&rect, RGB(255, 255, 255));

	//return CDialogEx::OnEraseBkgnd(pDC);//绘制了一个灰色的背景
	return TRUE;
}
