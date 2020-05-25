
// AppDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "App.h"
#include "AppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAppDlg 对话框



CAppDlg::CAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAppDlg::IDD, pParent)
{
	//m_hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE( IDR_MAINFRAME));
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAppDlg::OnBnClickedButton1)
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CAppDlg 消息处理程序

BOOL CAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作

	//读取注册表
	int left = theApp.GetProfileInt(L"Position", L"left", 0);
	int right = theApp.GetProfileInt(L"Position", L"right", 0);
	int top = theApp.GetProfileInt(L"Position", L"top", 0);
	int bottom = theApp.GetProfileInt(L"Position", L"bottom", 0);
	MoveWindow(left, top, right-left, bottom-top, TRUE);


	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	CString str;


	SetDlgItemText(IDC_EDIT1, theApp.m_pszAppName);

	str.Format(L"%x", theApp.m_hInstance);
	SetDlgItemText(IDC_EDIT2, str);

	str.Format(L"%x", 0);
	SetDlgItemText(IDC_EDIT3, str);

	SetDlgItemText(IDC_EDIT4, theApp.m_lpCmdLine);

	str.Format(L"%x", theApp.m_nCmdShow);
	SetDlgItemText(IDC_EDIT5, str);

	SetDlgItemText(IDC_EDIT6, theApp.m_bHelpMode?L"TRUE":L"FALSE");

	str.Format(L"%x", theApp.m_pActiveWnd);
	SetDlgItemText(IDC_EDIT7, str);

	SetDlgItemText(IDC_EDIT8, theApp.m_pszExeName);
	SetDlgItemText(IDC_EDIT9, theApp.m_pszHelpFilePath);
	SetDlgItemText(IDC_EDIT10, theApp.m_pszProfileName);
	SetDlgItemText(IDC_EDIT11, theApp.m_pszRegistryKey);
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAppDlg::OnPaint()
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
HCURSOR CAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAppDlg::OnBnClickedButton1()
{
	AfxMessageBox(L"提示");
}


void CAppDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	//获取窗口的大小和坐标
	CRect rect;
	GetWindowRect(&rect);

	//写入配置文件或者注册表
	theApp.WriteProfileInt(L"Position", L"left", rect.left);
	theApp.WriteProfileInt(L"Position", L"top", rect.top);
	theApp.WriteProfileInt(L"Position", L"right", rect.right);
	theApp.WriteProfileInt(L"Position", L"bottom", rect.bottom);

	CString str;
	GetWindowText(str);

	theApp.WriteProfileString(L"Other", L"title", str);
	

}


void CAppDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值



	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}
