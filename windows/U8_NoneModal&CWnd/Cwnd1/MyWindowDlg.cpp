
// MyWindowDlg.cpp ???
//????????? CtestMFCDlg <= CDialogEx <= CDialog <= CWnd <= CCmdTarget <= CObject
#include "stdafx.h"
#include "MyWindow.h"
#include "MyWindowDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyWindowDlg 



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
END_MESSAGE_MAP()


// CMyWindowDlg 

BOOL CMyWindowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		



	return TRUE;  
}


void CMyWindowDlg::OnPaint()
{
	//ÊÇ²»ÊÇ×îÐ¡»¯
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

	
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


HCURSOR CMyWindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//只是窗口创建 控件还没有 m_hWnd 是窗口核心 它为空 窗口没有
int CMyWindowDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	/*
	CWnd* pTestBtn = GetDlgItem(IDC_BTN_TEST);
	if (pTestBtn->m_hWnd) //这样不安全
	{		
	}
	*/

	return 0;
}


void CMyWindowDlg::OnBnClickedButton2()
{   //用来创建子控件的
	CWnd *pWnd = new CWnd;//这样可以延长生命周期 或者成员变量
	pWnd->Create(L"BUTTON", L"补习班", WS_BORDER | BS_PUSHBUTTON, CRect(200, 200, 300, 230), this, 1001);
	pWnd->ShowWindow(SW_SHOW);

}


void CMyWindowDlg::OnBnClickedButton3()
{
	//创建通用窗口类型
	WNDCLASS wc = {0};
	wc.hbrBackground = CreateSolidBrush(RGB(255, 0, 0));
	wc.hInstance = AfxGetInstanceHandle();
	wc.lpfnWndProc = ::DefWindowProc;
	wc.lpszClassName = L"DunKai";
	wc.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wc);

	CWnd* pWnd = new CWnd;
	pWnd->CreateEx(WS_EX_ACCEPTFILES, L"DunKai", L"¶Ù¿ª½ÌÓý", WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX,
		20, 20, 500, 400, m_hWnd, NULL, 0);
	pWnd->ShowWindow(SW_SHOW);

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
	this->GetWindowText(str);

	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	pWnd->GetWindowText(str);//测试按钮的文本
	MessageBox(str);
}


void CMyWindowDlg::OnBnClickedButton6()
{
	//SetWindowText(L"窗口标题");

	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	pWnd->SetWindowText(L"顿开教育");
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
	//DestroyWindow(); 销毁窗口
	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	pWnd->DestroyWindow();//销毁控件
}


void CMyWindowDlg::OnBnClickedButton10()
{
	//CenterWindow();
	CWnd* pWnd = GetDlgItem(IDC_BTN_TEST);
	pWnd->CenterWindow();
}


void CMyWindowDlg::OnBnClickedButton11()
{
	//查找主窗口不能查找控件
	CWnd* pWnd = FindWindow(L"Notepad", NULL);
	if (pWnd != NULL)//找到了
	{
		pWnd->SendMessage(WM_CLOSE, 0, 0);
	}
}


void CMyWindowDlg::OnBnClickedButton12()
{
	//FindWindowEx 查找子控件
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
		FlashWindow(TRUE);       //闪烁
		Sleep(500);              //毫秒
		i++;
	}
	
}


void CMyWindowDlg::OnBnClickedButton14() //闪烁
{
	/*FLASHWINFO fi;
	fi.cbSize = sizeof(FLASHWINFO);
	fi.dwFlags = FLASHW_ALL | FLASHW_TIMER;
	fi.dwTimeout = 500;*/
	FlashWindowEx(FLASHW_ALL | FLASHW_TIMER, 4, 500);
}


void CMyWindowDlg::OnBnClickedButton15() //qq 屏幕截图软件
{
	CWnd* pDesktopWnd = GetDesktopWindow();//桌面也是窗口spy++
	HWND hWnd = pDesktopWnd->m_hWnd;
}


void CMyWindowDlg::OnBnClickedButton16() //窗口风格
{
	CString str;

	DWORD dwStyle = this->GetStyle();//DWORD无符号long

	if (dwStyle & WS_CAPTION)
	{
		str = str + L"包含标题栏";
	}
	if (dwStyle & WS_SYSMENU)
	{
		str = str + L"包含系统菜单";
	}
	if (dwStyle & WS_MINIMIZEBOX)
	{
		str = str + L"最小化框";
	}
	if (dwStyle & WS_MAXIMIZEBOX)
	{
		str = str + L"包含最大化框";
	}

	SetWindowText(str);
}


void CMyWindowDlg::OnBnClickedButton17()//modifystyle 修改风格
{
	DWORD dwStyle = this->GetStyle();

	ModifyStyle(WS_MAXIMIZEBOX, 0);
}


void CMyWindowDlg::OnBnClickedButton18()
{
	DWORD dwExStyle = GetExStyle();

	if (dwExStyle & WS_EX_ACCEPTFILES)
	{
		MessageBox(L"ÄÜ½ÓÊÜÎÄ¼þ");
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
		MessageBox(L"ÊÇ");
	}
}


void CMyWindowDlg::OnBnClickedButton21()
{
	if (IsIconic())
	{
		MessageBox(L"ÊÇ");
	}
	else
	{
		MessageBox(L"²»ÊÇ");
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
	//»ñÈ¡´°¿ÚµÄÇøÓò×ø±ê
	CRect rect;
	GetWindowRect(&rect);

	CString str;
	str.Format(L"(%d,%d,%d,%d)", rect.left, rect.top, rect.right,rect.bottom);
	SetWindowText(str);

	//´°¿ÚµÄ¿í¸ß
	rect.Width();
	rect.Height();
}


void CMyWindowDlg::OnBnClickedButton26()
{
	//»ñÈ¡¿Í»§ÇøµÄÇøÓò×ø±ê
	CRect rect;
	GetClientRect(&rect);

	CString str;
	str.Format(L"(%d,%d,%d,%d)", rect.left, rect.top, rect.right, rect.bottom);
	SetWindowText(str);

	//¿Í»§ÇøµÄ¿í¸ß
	rect.Width();
	rect.Height();
}


void CMyWindowDlg::OnBnClickedButton27()
{
	//获取按钮的屏幕坐标系
	CWnd* pWnd  = GetDlgItem(IDC_BUTTON27);
	CRect rect;
	//屏幕坐标系转化为客户坐标系，我想知道按钮在客户区的坐标是多少
	pWnd->GetWindowRect(&rect);

	ScreenToClient(&rect);
	//将客户区转换为屏幕坐标系
	this->ClientToScreen(&rect);

}


void CMyWindowDlg::OnBnClickedButton28()//抖一抖
{
	//CWnd* pWnd = GetDlgItem(IDC_BUTTON27);
	//pWnd->MoveWindow(0, 0, 200, 100, TRUE);//基于屏幕坐标系（父亲）
	//获取软件坐标
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


void CMyWindowDlg::OnBnClickedButton30()//开始移动
{
	
	SetTimer(1, 200, NULL);
}


void CMyWindowDlg::OnBnClickedButton31()//结束移动
{
	KillTimer(1);
}


void CMyWindowDlg::OnTimer(UINT_PTR nIDEvent)//走 通过类向导自动添加
{
	switch (nIDEvent)
	{
	case 1:
		{
			  CWnd* pWnd = GetDlgItem(IDC_BUTTON29);
			 
			  CRect rect;
			  pWnd->GetWindowRect(&rect);//按钮基于客户区的坐标系的获取 ，还有按钮的宽和高不变！（屏幕坐标系）
			  ScreenToClient(&rect);
			  int nWidth = rect.Width();
			  int nHeight = rect.Height();

			  rect.left += 10;
			  rect.right += 10;
			 // rect.right = rect.left + nWidth;

			
			  CRect rt;
			  GetClientRect(&rt);

			  if (rect.left > rt.right)//获取软件客户区的宽和高 不要超出屏幕边缘
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
