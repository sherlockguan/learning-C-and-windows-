
// MyWindowDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyWindow.h"
#include "MyWindowDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define IDM_NEW		1026


// CMyWindowDlg 对话框



CMyWindowDlg::CMyWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyWindowDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyWindowDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON2, &CMyWindowDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyWindowDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyWindowDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyWindowDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMyWindowDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMyWindowDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMyWindowDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMyWindowDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMyWindowDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMyWindowDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMyWindowDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMyWindowDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMyWindowDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMyWindowDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMyWindowDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMyWindowDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CMyWindowDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMyWindowDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CMyWindowDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CMyWindowDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CMyWindowDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CMyWindowDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CMyWindowDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CMyWindowDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CMyWindowDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CMyWindowDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON28, &CMyWindowDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON30, &CMyWindowDlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON31, &CMyWindowDlg::OnBnClickedButton31)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyWindowDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON32, &CMyWindowDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON33, &CMyWindowDlg::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON34, &CMyWindowDlg::OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON35, &CMyWindowDlg::OnBnClickedButton35)
	ON_BN_CLICKED(IDC_BUTTON36, &CMyWindowDlg::OnBnClickedButton36)
	ON_BN_CLICKED(IDC_BUTTON37, &CMyWindowDlg::OnBnClickedButton37)
	ON_BN_CLICKED(IDC_BUTTON38, &CMyWindowDlg::OnBnClickedButton38)
END_MESSAGE_MAP()


// CMyWindowDlg 消息处理程序

//控件已经创建好了，只不过还没显示
BOOL CMyWindowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	//CRgn rgn;
	//rgn.CreateEllipticRgn(0, 0, 100, 100);
	//SetWindowRgn(rgn, TRUE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyWindowDlg::OnPaint()
{
	//是不是最小化
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
HCURSOR CMyWindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//MFC当中：此时主窗口已经创建好了，但是窗口上面的控件还没创建好
int CMyWindowDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	/*
	CWnd* pTestBtn = GetDlgItem(IDC_BTN_TEST);
	if (pTestBtn->m_hWnd)
	{		
	}
	*/

	return 0;
}


void CMyWindowDlg::OnBnClickedButton2()
{
	//创建一个通用窗口吗？类似于CreateWindow ,用来创建子控件的
	CWnd *pWnd = new CWnd;
	pWnd->Create(L"BUTTON", L"顿开教育", WS_BORDER | BS_PUSHBUTTON, CRect(200, 200, 300, 230), this, 1001);
	pWnd->ShowWindow(SW_SHOW);

}


void CMyWindowDlg::OnBnClickedButton3()
{
	//1.创建通用窗口
	/*
	WNDCLASS wc = {0};
	wc.hbrBackground = CreateSolidBrush(RGB(255, 0, 0));
	wc.hInstance = AfxGetInstanceHandle();
	wc.lpfnWndProc = ::DefWindowProc;
	wc.lpszClassName = L"DunKai";
	wc.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wc);

	CWnd* pWnd = new CWnd;
	pWnd->CreateEx(WS_EX_ACCEPTFILES, L"DunKai", L"顿开教育", WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX,
		20, 20, 500, 400, m_hWnd, NULL, 0);
	pWnd->ShowWindow(SW_SHOW);
	*/

	//2.创建子控件
	CWnd *pWnd = new CWnd;
	pWnd->CreateEx(WS_EX_ACCEPTFILES, L"BUTTON", L"顿开教育", WS_CHILD|WS_BORDER | BS_PUSHBUTTON | WS_VISIBLE, CRect(200, 200, 300, 230), this, 1024);
	//pWnd->ShowWindow(SW_SHOW);

}


void CMyWindowDlg::OnBnClickedButton4()
{
	if (IDYES == MessageBox(L"弹出来", L"提示", MB_ICONERROR | MB_YESNO))
	{

	}
}


void CMyWindowDlg::OnBnClickedButton5()
{
	CString str;
	//this->GetWindowText(str);

	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	pWnd->GetWindowText(str);
	MessageBox(str);
}


void CMyWindowDlg::OnBnClickedButton6()
{
	//SetWindowText(L"顿开教育");

	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	pWnd->SetWindowText(L"长沙顿开教育科技有限公司");
}


void CMyWindowDlg::OnBnClickedButton7()
{
	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	int nLength = pWnd->GetWindowTextLength();
}


void CMyWindowDlg::OnBnClickedButton8()
{
	//CloseWindow();
	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	pWnd->CloseWindow();
}


void CMyWindowDlg::OnBnClickedButton9()
{
	//DestroyWindow();
	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	pWnd->DestroyWindow();
}


void CMyWindowDlg::OnBnClickedButton10()
{
	//CenterWindow();
	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	pWnd->CenterWindow();
}


void CMyWindowDlg::OnBnClickedButton11()
{
	//查找主窗口，不能查找子控件
	CWnd* pWnd = FindWindow(L"Notepad", NULL);
	if (pWnd != NULL)
	{
		pWnd->SendMessage(WM_CLOSE, 0, 0);
	}
}


void CMyWindowDlg::OnBnClickedButton12()
{
	//FindWindowEx能够查找窗口的子控件
	CWnd* pWnd = FindWindow(L"Notepad", NULL);
	if (pWnd != NULL)
	{
		CWnd* pEdit = FindWindowEx(pWnd->m_hWnd, NULL, L"Edit", NULL);
		if (pEdit != NULL)
		{
			pEdit->MoveWindow(100, 100, 200, 200);
		}
	}
}


void CMyWindowDlg::OnBnClickedButton13()
{
	int i = 0;
	while (i < 4)
	{
		FlashWindow(TRUE);
		Sleep(500);
		i++;
	}
	
}


void CMyWindowDlg::OnBnClickedButton14()
{
	/*FLASHWINFO fi;
	fi.cbSize = sizeof(FLASHWINFO);
	fi.dwFlags = FLASHW_ALL | FLASHW_TIMER;
	fi.dwTimeout = 500;*/
	FlashWindowEx(FLASHW_ALL | FLASHW_TIMER, 4, 500);
}


void CMyWindowDlg::OnBnClickedButton15()
{
	CWnd* pDesktopWnd = GetDesktopWindow();
	HWND hWnd = pDesktopWnd->m_hWnd;
}


void CMyWindowDlg::OnBnClickedButton16()
{
	CString str;

	DWORD dwStyle = this->GetStyle();

	if (dwStyle & WS_CAPTION)
	{
		str = str + L"包含标题栏；";
	}
	if (dwStyle & WS_SYSMENU)
	{
		str = str + L"包含系统菜单；";
	}
	if (dwStyle & WS_MINIMIZEBOX)
	{
		str = str + L"包含最小化框；";
	}
	if (dwStyle & WS_MAXIMIZEBOX)
	{
		str = str + L"包含最大化框；";
	}

	SetWindowText(str);
}


void CMyWindowDlg::OnBnClickedButton17()
{
	DWORD dwStyle = this->GetStyle();

	ModifyStyle(WS_MAXIMIZEBOX, 0);
}


void CMyWindowDlg::OnBnClickedButton18()
{
	DWORD dwExStyle = GetExStyle();

	if (dwExStyle & WS_EX_ACCEPTFILES)
	{
		MessageBox(L"能接受文件");
	}
}


void CMyWindowDlg::OnBnClickedButton19()
{
	//ModifyStyleEx(WS_EX_ACCEPTFILES, WS_EX_LAYERED, 0);
	//Windows API
	DWORD dwExStyle = GetWindowLong(m_hWnd, GWL_EXSTYLE);

	dwExStyle = dwExStyle & ~ WS_EX_ACCEPTFILES;
	dwExStyle = dwExStyle | WS_EX_LAYERED;

	SetWindowLong(m_hWnd, GWL_EXSTYLE, dwExStyle);

	SetLayeredWindowAttributes(0, 0,LWA_ALPHA);

}


void CMyWindowDlg::OnBnClickedButton20()
{
	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	if (TRUE == IsChild(pWnd))
	{
		MessageBox(L"是");
	}
}


void CMyWindowDlg::OnBnClickedButton21()
{
	if (IsIconic())
	{
		MessageBox(L"是");
	}
	else
	{
		MessageBox(L"不是");
	}
}


void CMyWindowDlg::OnBnClickedButton22()
{
	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);

	if (pWnd->IsWindowEnabled())
		pWnd->EnableWindow(FALSE);
	else
		pWnd->EnableWindow(TRUE);
}


void CMyWindowDlg::OnBnClickedButton23()
{
	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	if (pWnd->IsWindowVisible())
		pWnd->ShowWindow(SW_HIDE);
	else
		pWnd->ShowWindow(SW_SHOW);
}


void CMyWindowDlg::OnBnClickedButton24()
{
	if (IsZoomed())
	{
		ShowWindow(SW_NORMAL);
	}
	else
	{
		ShowWindow(SW_MAXIMIZE);
	}
}


void CMyWindowDlg::OnBnClickedButton25()
{
	//获取窗口的区域坐标
	CRect rect;
	GetWindowRect(&rect);

	CString str;
	str.Format(L"(%d,%d,%d,%d)", rect.left, rect.top, rect.right,rect.bottom);
	SetWindowText(str);

	//窗口的宽高
	rect.Width();
	rect.Height();
}


void CMyWindowDlg::OnBnClickedButton26()
{
	//获取客户区的区域坐标
	CRect rect;
	GetClientRect(&rect);

	CString str;
	str.Format(L"(%d,%d,%d,%d)", rect.left, rect.top, rect.right, rect.bottom);
	SetWindowText(str);

	//客户区的宽高
	rect.Width();
	rect.Height();
}


void CMyWindowDlg::OnBnClickedButton27()
{
	//获取按钮的屏幕坐标系下坐标
	CWnd* pWnd  = GetDlgItem(IDC_BUTTON27);
	CRect rect;
	pWnd->GetWindowRect(&rect);

	//获取按钮的客户区坐标系坐标
	//pWnd->GetClientRect(&rect);//基于按钮的坐标，原点是按钮的左上角

	//我想要知道按钮在客户区的坐标是多少？
	//坐标系的转化
	//将屏幕坐标系转化为客户区坐标系
	ScreenToClient(&rect);


	//将客户区坐标系转化为屏幕坐标系
	this->ClientToScreen(&rect);

}


void CMyWindowDlg::OnBnClickedButton28()
{
	//基于父窗口
	//CWnd* pWnd = GetDlgItem(IDC_BUTTON27);
	//pWnd->MoveWindow(0, 0, 200, 100, TRUE);

	//获取软件的坐标
	CRect rect;
	GetWindowRect(&rect);
	int nWidth = rect.Width();
	int nHeight = rect.Height();

	for (int i = 0; i < 3;i++)
	{
		rect.left -= 3;
		rect.top -= 3;
		rect.right -= 3;
		rect.bottom -= 3;
		MoveWindow(&rect);
		Sleep(50);

		rect.left += 3;
		rect.top += 3;
		rect.right += 3;
		rect.bottom += 3;
		MoveWindow(&rect);
		Sleep(50);
	}

}

//开始移动
void CMyWindowDlg::OnBnClickedButton30()
{
	//开启定时器
	SetTimer(1, 200, NULL);
}

//停止移动
void CMyWindowDlg::OnBnClickedButton31()
{
	KillTimer(1);
}


void CMyWindowDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case 1:
		{
			  CWnd* pWnd = GetDlgItem(IDC_BUTTON29);
			  //获取按钮基于客户区坐标，以及按钮的宽和高
			  CRect rect;
			  pWnd->GetWindowRect(&rect);
			  ScreenToClient(&rect);
			  int nWidth = rect.Width();
			  int nHeight = rect.Height();

			  rect.left += 10;
			  rect.right += 10;
			 // rect.right = rect.left + nWidth;

			  //获取软件的客户区坐标
			  CRect rt;
			  GetClientRect(&rt);

			  if (rect.left > rt.right)
			  {
				  rect.right = 0;
				  rect.left = rect.right - nWidth;
			  }

			  pWnd->MoveWindow(&rect);

		}
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CMyWindowDlg::OnBnClickedButton1()
{
	//SetWindowPos: 能够调整窗口的大小；改变窗口的Z顺序

	SetWindowPos(&wndTopMost, 0, 0, 300, 200, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER);
}


void CMyWindowDlg::OnBnClickedButton32()
{
	CWnd* pWnd = GetTopWindow();
	if (pWnd == NULL)
		return;

	pWnd->CloseWindow();
}


void CMyWindowDlg::OnBnClickedButton33()
{
	/*CWnd* pWnd = GetFocus();
	if (pWnd == NULL)
		return;

	pWnd->CloseWindow();

	GetDlgItem(IDC_BTN_TEST)->SetFocus();
	pWnd = GetFocus();
	if (pWnd == NULL)
		return;
	pWnd->CloseWindow();*/

	GetDlgItem(IDC_EDIT1)->SetFocus();
}


void CMyWindowDlg::OnBnClickedButton34()
{
	HICON hIcon = GetIcon(TRUE);
}


void CMyWindowDlg::OnBnClickedButton35()
{
	CMenu* pMenu = GetMenu();
	if (pMenu == NULL)
		return;

	CMenu* p = pMenu->GetSubMenu(0);
	p->AppendMenu(MF_STRING, IDM_NEW, L"新建");
}


void CMyWindowDlg::OnBnClickedButton36()
{
	CFont* pFont = GetFont();
	//获取字体的信息
	LOGFONT logFont;
	pFont->GetLogFont(&logFont);
	wcscpy(logFont.lfFaceName, L"楷体");
	//从新构造一个字体
	static CFont font;//局部变量
	font.CreateFontIndirect(&logFont);
	GetDlgItem(IDC_BTN_TEST)->SetFont(&font);
}


void CMyWindowDlg::OnBnClickedButton37()
{
	CWnd* pWnd = GetActiveWindow();

	pWnd->DestroyWindow();
}


void CMyWindowDlg::OnBnClickedButton38()
{
	SetActiveWindow();
}
