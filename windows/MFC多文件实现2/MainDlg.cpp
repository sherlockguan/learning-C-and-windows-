
#include"stdafx.h"
#include"MainDlg.h"
#define TIME_TIMER 1//获取时间
#define ICON_TIMER 2//S设置图标的定时器
#define WM_TEST WM_USER+1 
//用户自定义消息 WM_USER以下的表示系统定义消息WM_USER以上的表示自定义消息
CMainDlg::CMainDlg():CDialog(IDD)
{
	m_hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_LOGO));
	m_hIcon1 = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
}
//WM_INITDIALOG:窗口已经创建好，控件也已经准备好了 只是还没有显示出来而已
BOOL CMainDlg::OnInitDialog()//初始化的虚函数
{//标题：
	//SetWindowText(L"This is MFC Dialog program");
	
	//MessageBox(L"This is WM_INIDIALOG msg");//阻断函数
	SetTimer(TIME_TIMER, 1000, NULL);
	SetTimer(ICON_TIMER, 500, NULL);
	return TRUE;
}
//下面两个开始结束消息映射宏 在CPP 中位置随意 顺序不能换
//开始消息映射 宏定义 
BEGIN_MESSAGE_MAP(CMainDlg, CDialog) //下面是宏替换 转到定义复制黏贴而来
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()

	ON_WM_SIZE()
	ON_MESSAGE(WM_TEST, &CMainDlg::OnTest)//自定义消息 不能通过类向导 必须手动填写
	//ON_BN_CLICKED(IDC_BTN_TEST, &CMainDlg::OnBtnTest)
END_MESSAGE_MAP()
//const AFX_MSGMAP* CMainDlg::GetMessageMap() const
//{ 
//	return GetThisMessageMap();
//} 
//const AFX_MSGMAP* PASCAL CMainDlg::GetThisMessageMap()
//{ 
//	typedef CMainDlg ThisClass;
//	typedef CDialog TheBaseClass;
//	static const AFX_MSGMAP_ENTRY _messageEntries[] = 
//	{
//	//ON_WM_CREATE()
//		{ WM_CREATE, 0, 0, 0, AfxSig_is, (AFX_PMSG)(AFX_PMSGW) (static_cast< int(AFX_MSG_CALL CWnd::*)(LPCREATESTRUCT) > (&ThisClass::OnCreate)) },
//	//ON_WM_CLOSE()
//		{ WM_CLOSE, 0, 0, 0, AfxSig_vv, 
//		(AFX_PMSG)(AFX_PMSGW) 
//		(static_cast< void (AFX_MSG_CALL CWnd::*)(void) > (&ThisClass::OnClose)) },
//	//ON_WM_DESTROY()
//		{ WM_DESTROY, 0, 0, 0, AfxSig_vv, (AFX_PMSG)(AFX_PMSGW) (static_cast< void (AFX_MSG_CALL CWnd::*)(void) > (&ThisClass::OnDestroy)) },
//	//ON_WM_PAINT()
//		{ WM_PAINT, 0, 0, 0, AfxSig_vv, (AFX_PMSG)(AFX_PMSGW) static_cast< void(AFX_MSG_CALL CWnd::*)(void) > (&ThisClass::OnPaint)) },
//	//ON_WM_LBUTTONDOWN()
//		{ WM_LBUTTONDOWN, 0, 0, 0, AfxSig_vwp, (AFX_PMSG)(AFX_PMSGW) (static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > (&ThisClass::OnLButtonDown)) },
//	//ON_WM_LBUTTONUP()
//		{ WM_LBUTTONUP, 0, 0, 0, AfxSig_vwp, (AFX_PMSG)(AFX_PMSGW) (static_cast<void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > (&ThisClass::OnLButtonUp)) },
//	//ON_WM_LBUTTONDBLCLK()
//		{ WM_LBUTTONDBLCLK, 0, 0, 0, AfxSig_vwp, (AFX_PMSG)(AFX_PMSGW) (static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, CPoint) > (&ThisClass::OnLButtonDblClk)) },
//	//ON_WM_MOUSEMOVE()
//		{ WM_MOUSEMOVE, 0, 0, 0, AfxSig_vwp,(AFX_PMSG)(AFX_PMSGW) (static_cast< void(AFX_MSG_CALL CWnd::*)(UINT, CPoint) > (&ThisClass::OnMouseMove)) },
//	//ON_WM_TIMER()
//		{ WM_TIMER, 0, 0, 0, AfxSig_v_up_v, (AFX_PMSG)(AFX_PMSGW) (static_cast< void (AFX_MSG_CALL CWnd::*)(UINT_PTR) > (&ThisClass::OnTimer)) },
//
//	//ON_WM_SIZE()
//		{ WM_SIZE, 0, 0, 0, AfxSig_vwii,(AFX_PMSG)(AFX_PMSGW) (static_cast< void (AFX_MSG_CALL CWnd::*)(UINT, int, int) > (&ThisClass::OnSize)) },
//
//	//ON_MESSAGE(WM_TEST, &CMainDlg::OnTest)//自定义消息 不能通过类向导 必须手动填写
//
//		{ WM_TEST, 0, 0, 0, AfxSig_lwl, (AFX_PMSG)(AFX_PMSGW)(static_cast< LRESULT(AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM) > (&CMainDlg::OnTest)) },
//
//
//	//ON_BN_CLICKED(IDC_BUTTON1, &CMainDlg::OnBtnTest)
// { WM_COMMAND, (WORD)BN_CLICKED, (WORD)IDC_BUTTON1, (WORD)IDC_BUTTON1, AfxSigCmd_v, (static_cast< AFX_PMSG > (&CMainDlg::OnBtnTest)) },
//
//	//END_MESSAGE_MAP()//结束消息映射
//	{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0} 
//	}; 
//	static const AFX_MSGMAP messageMap = 
//		{ 
//			&TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; 
//			
//		}	
//	return &messageMap;

//WM_CREATE :更早的消息 发生在窗口创建的时候
int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	SetWindowText(L"believe in myself");
	MessageBox(L"This is WM_CREATE msg");
	return CDialog::OnCreate(lpCreateStruct); //没有处理的话调用基类默认处理
}
void CMainDlg::OnClose()
{
	if (IDYES == MessageBox(L"you clicked the close button", L"HINT", MB_YESNO | MB_ICONERROR))
	{
		return CDialog::OnClose();//没有处理的话调用基类默认处理
	} //win32 也是调用EndDialog(IDCANCEL)
	else
	{
		ShowWindow(SW_MINIMIZE);//最小化窗口
		return;
	}
}
	//WM_DESTROY 消息处理函数 此时窗口不能再还原了 被清理了
void CMainDlg::OnDestroy()
{
	return CDialog::OnDestroy();
}

void CMainDlg::OnPaint()
{
	//绘图以后讲
	CPaintDC dc(this);
	dc.Rectangle(0, 0, 200, 100);
	return CDialog::OnPaint();

}
//vs 类向导:添加类 添加消息==>自动添加函数 如下
//UINT nFlags, CPoint point =》MFC 已经解析了做好了 Wparam按键 Lparam点坐标  的工作
void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	/*CString str;
	str.Format(L"mouse clicked at(%d,%d)", point.x, point.y);
	if (nFlags&MK_CONTROL)
	{
		str += L"pressed control button";
	}
	if (nFlags&MK_LBUTTON)
	{
		str += L"按了鼠标左键";
	}
	if (nFlags&MK_RBUTTON)
	{
		str += L"按了鼠标右键";
	}
	SetWindowText(str);*/
	//发出用户自定义消息
	SendMessage(WM_TEST, 45, 23);
	CDialog::OnLButtonDown(nFlags, point);
}


void CMainDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//MessageBox(L"Mouse has lifted");

	CDialog::OnLButtonUp(nFlags, point);
}


void CMainDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	SetWindowText(L"Mouse double clicked");
	CDialog::OnLButtonDblClk(nFlags, point);
}


void CMainDlg::OnMouseMove(UINT nFlags, CPoint point)//鼠标移动
{
	CString str;
	str.Format(L"mouse clicked at(%d,%d)", point.x, point.y);
	if (nFlags&MK_CONTROL)
	{
		str += L"pressed control button";
	}
	if (nFlags&MK_LBUTTON)
	{
		str += L"按了鼠标左键";
	}
	if (nFlags&MK_RBUTTON)
	{
		str += L"按了鼠标右键";
	}
	SetWindowText(str);

	CDialog::OnMouseMove(nFlags, point);
}
//WM_TIMER 定时器消息

void CMainDlg::OnTimer(UINT_PTR nIDEvent)
{ //1000毫秒 = 1秒
	//SetTimer(TIME_TIMER,1000,NULL);
	switch (nIDEvent)
	{
	case TIME_TIMER:
	{
		//获取当前时间
		CTime time = CTime::GetCurrentTime();
		SetWindowText(time.Format(L"TIME %Y %m %d %H %M %S"));
		break;
	}
	case ICON_TIMER:
		{
			static int  i = 0;
			if (i == 0)
			{
				//设置图标
				SetIcon(m_hIcon, TRUE);
				SetIcon(m_hIcon, FALSE);
				i = 1;
			}
			else
			{
				//设置图标
				SetIcon(m_hIcon1, TRUE);
				SetIcon(m_hIcon1, FALSE);
				i = 0;
			}
					   
			break;


		}
	}
	CDialog::OnTimer(nIDEvent);//无定义时系统默认处理
}

//WM_SIZE 窗口的大小发生变化
void CMainDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	SetWindowText(L"Window size changed");
	// TODO:  在此处添加消息处理程序代码
}
//删除创建消息映射 共有三处 注意 一起处理



//第二课：自定义消息 MFC 进程内部通讯的一种方式

LRESULT CMainDlg::OnTest(WPARAM wParam, LPARAM lParam)
{
	MessageBox(L"this is user_defined msg");
	return 0;
}
//虚函数不需要再写消息映射 虚函数实现多态，只要在子类重写 就能多态 不用写消息映射
//OnOk OnInitDialog OnCancel

void CMainDlg::OnOK()//MFC点击OK按钮 响应onok函数 内部调用EndDialog

{
	// 此函数可不写

	CDialog::OnOK();
}


void CMainDlg::OnCancel()
{
	// 可默认不写此函数

	CDialog::OnCancel();//如果写这个函数但是注释这行没法关闭
}


void CMainDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
}
