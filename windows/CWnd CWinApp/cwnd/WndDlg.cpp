
// WndDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Wnd.h"
#include "WndDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWndDlg 对话框



CWndDlg::CWndDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWndDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWndDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_GET, &CWndDlg::OnBnClickedBtnGet)
	ON_BN_CLICKED(IDC_BTN_CALC, &CWndDlg::OnBnClickedBtnCalc)
END_MESSAGE_MAP()


// CWndDlg 消息处理程序

BOOL CWndDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//获取列表控件
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
	pList->InsertColumn(0, L"编号", LVCFMT_LEFT, 150);
	pList->InsertColumn(1, L"窗口标题", LVCFMT_LEFT, 150);
	pList->InsertColumn(2, L"窗口句柄", LVCFMT_LEFT, 150);
	pList->InsertColumn(3, L"控件ID", LVCFMT_LEFT, 150);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWndDlg::OnPaint()
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
HCURSOR CWndDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//获取窗口
void CWndDlg::OnBnClickedBtnGet()
{
	//获取列表控件
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);

	CWnd* pWnd;// = GetDesktopWindow();
	pWnd = this->GetWindow(GW_CHILD)->GetWindow(GW_HWNDFIRST);

	int n = 0;
	while (pWnd != NULL)
	{
		CString str;
		str.Format(L"%d", n + 1);
		pList->InsertItem(n, str);


		pWnd->GetWindowText(str);
		pList->SetItemText(n, 1, str);

		str.Format(L"0X%X", pWnd->m_hWnd);
		pList->SetItemText(n, 2, str);

		str.Format(L"%d", pWnd->GetDlgCtrlID());
		pList->SetItemText(n, 3, str);

		pWnd = pWnd->GetNextWindow();
		n++;
	}
	
}


void CWndDlg::OnBnClickedBtnCalc()
{
	//获取文本框中的值
	//GetDlgItemInt
	//GetDlgItemText
	BOOL b;
	int num1 = GetDlgItemInt(IDC_EDIT1, &b);
	int num2 = GetDlgItemInt(IDC_EDIT2);

	SetDlgItemInt(IDC_EDIT3, num1 + num2);
}
