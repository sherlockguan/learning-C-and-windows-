
// NotepadPlusDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "NotepadPlus.h"
#include "NotepadPlusDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepadPlusDlg 对话框



CNotepadPlusDlg::CNotepadPlusDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNotepadPlusDlg::IDD, pParent)
	, m_strSendMsg(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNotepadPlusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT21, m_richEdit);
	DDX_Text(pDX, IDC_EDIT1, m_strSendMsg);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CNotepadPlusDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEND, &CNotepadPlusDlg::OnBnClickedBtnSend)
END_MESSAGE_MAP()


// CNotepadPlusDlg 消息处理程序

BOOL CNotepadPlusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CNotepadPlusDlg::OnPaint()
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
HCURSOR CNotepadPlusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//发送
void CNotepadPlusDlg::OnBnClickedBtnSend()
{
	UpdateData(TRUE);

	if (m_strSendMsg.IsEmpty())
	{
		MessageBox(L"不能发送空消息");
		return;
	}

	CHARFORMAT cf = {0};
	cf.cbSize = sizeof(CHARFORMAT);
	cf.dwMask = CFM_BOLD | CFM_COLOR | CFM_FACE | CFM_ITALIC | CFM_SIZE | CFM_STRIKEOUT | CFM_UNDERLINE;
	cf.dwEffects = CFE_BOLD;
	cf.yHeight = 200;
	cf.crTextColor = RGB(0,0,0);
	wcscpy(cf.szFaceName, _T("黑体"));
	m_richEdit.SetWordCharFormat(cf);

	//获取文本长度
	int nLength = m_richEdit.GetWindowTextLength();
	m_richEdit.SetSel(nLength, -1);

	CTime t = CTime::GetCurrentTime();
	CString str;
	str.Format(L"%s 里奇老师\r\n", t.Format(L"%H:%M:%S"));
	m_richEdit.ReplaceSel(str);

	CHARFORMAT cf2 = { 0 };
	cf2.cbSize = sizeof(CHARFORMAT);
	cf2.dwMask = CFM_BOLD | CFM_COLOR | CFM_FACE | CFM_ITALIC | CFM_SIZE | CFM_STRIKEOUT | CFM_UNDERLINE;
	cf2.dwEffects = CFE_ITALIC | CFE_UNDERLINE;
	cf2.yHeight = 200;
	cf2.crTextColor = RGB(255, 0, 0);
	wcscpy(cf2.szFaceName, _T("宋体"));
	m_richEdit.SetWordCharFormat(cf2);
	nLength = m_richEdit.GetWindowTextLength();
	m_richEdit.SetSel(nLength, -1);
	m_richEdit.ReplaceSel(m_strSendMsg+L"\r\n");

	
	long dwStyle = ::GetWindowLong(m_edit.m_hWnd, GWL_STYLE);
	dwStyle = dwStyle | WS_VSCROLL | ES_WANTRETURN;

	if (dwStyle & WS_VSCROLL)
	{
		int n = 0;
	}

	::SetWindowLong(m_edit.m_hWnd, GWL_STYLE, dwStyle);
	

	//m_edit.ModifyStyle(0, WS_VSCROLL|ES_WANTRETURN);
}
