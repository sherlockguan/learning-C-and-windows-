
// TaskManagerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TaskManager.h"
#include "TaskManagerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTaskManagerDlg 对话框



CTaskManagerDlg::CTaskManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTaskManagerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTaskManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

BEGIN_MESSAGE_MAP(CTaskManagerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CTaskManagerDlg::OnSelchangeTab)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CTaskManagerDlg 消息处理程序

BOOL CTaskManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_tab.InsertItem(0, L"窗口");
	m_tab.InsertItem(1, L"进程");

	m_page1.Create(IDD_PAGE1, &m_tab);
	m_page2.Create(IDD_PAGE2, &m_tab);

	//获取Tab的大小
	CRect rect;
	m_tab.GetClientRect(&rect);
	rect.top += 22;
	rect.left += 1;
	rect.right -= 3;
	rect.bottom -= 2;

	m_page1.MoveWindow(&rect);
	m_page2.MoveWindow(&rect);

	m_page1.ShowWindow(SW_SHOW);
	m_page2.ShowWindow(SW_HIDE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTaskManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTaskManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTaskManagerDlg::OnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	int nSel = m_tab.GetCurSel();
	switch (nSel)
	{
	case 0:
		m_page1.ShowWindow(SW_SHOW);
		m_page2.ShowWindow(SW_HIDE);
		break;
	case 1:
		m_page1.ShowWindow(SW_HIDE);
		m_page2.ShowWindow(SW_SHOW);
		break;
	}

	*pResult = 0;
}


void CTaskManagerDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_tab.GetSafeHwnd())
	{
		m_tab.MoveWindow(10, 10, cx - 20, cy - 20);

		//获取Tab的大小
		CRect rect;
		m_tab.GetClientRect(&rect);
		rect.top += 22;
		rect.left += 1;
		rect.right -= 3;
		rect.bottom -= 2;

		m_page1.MoveWindow(&rect);
		m_page2.MoveWindow(&rect);
	}

}
