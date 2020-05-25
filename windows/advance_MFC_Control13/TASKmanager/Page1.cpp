// Page1.cpp : 实现文件
//

#include "stdafx.h"
#include "TaskManager.h"
#include "Page1.h"
#include "afxdialogex.h"


// CPage1 对话框

IMPLEMENT_DYNAMIC(CPage1, CDialogEx)

CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage1::IDD, pParent)
{

}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CPage1, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CPage1 消息处理程序


BOOL CPage1::OnEraseBkgnd(CDC* pDC)
{
	//获取对话框的客户区大小
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(&rect,RGB(255, 255, 255));

	//return CDialogEx::OnEraseBkgnd(pDC);//绘制了一个灰色的背景
	return TRUE;
}


BOOL CPage1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_list.InsertColumn(0, L"编号", LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, L"窗口名", LVCFMT_LEFT, 200);
	m_list.InsertColumn(2, L"窗口句柄", LVCFMT_LEFT, 100);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CPage1::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_list.GetSafeHwnd())
	{
		//获取窗口的大小
		CRect rect;
		GetClientRect(&rect);
		m_list.MoveWindow(&rect);
	}
}
