
// WindowDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Window.h"
#include "WindowDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWindowDlg 对话框



CWindowDlg::CWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWindowDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWindowDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_TEST1, &CWindowDlg::OnBnClickedBtnTest1)
	ON_BN_CLICKED(IDC_BTN_TEST2, &CWindowDlg::OnBnClickedBtnTest2)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BTN_HELLO, &CWindowDlg::OnBnClickedBtnHello)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CWindowDlg 消息处理程序

BOOL CWindowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//加载位图
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);

	//为按钮设置图片 或者 设置图标
	CButton* pButton = (CButton*)GetDlgItem(IDC_BTN_TEST1);
	//pButton->MoveWindow(0, 0, 100, 100);
	//pButton->SetBitmap((HBITMAP)bmp.m_hObject);
	//pButton->SetIcon(m_hIcon);

	SetDlgItemText(IDC_EDIT2, L"HelloWorld");

	//SetDlgItemText(IDC_STATIC_SHOW, L"123456");

	CComboBox* pCombBox = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pCombBox->AddString(L"菲律宾");
	pCombBox->InsertString(1, L"越南");
	pCombBox->DeleteString(2);

	pCombBox->SetCurSel(0);


	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	pListBox->AddString(L"C++");
	pListBox->AddString(L"Python");
	pListBox->AddString(L"Java");
	pListBox->AddString(L"前端");
	pListBox->AddString(L"安卓");
	pListBox->AddString(L"iOS");

	CSliderCtrl* pSlider = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
	pSlider->SetRange(0, 100);
	pSlider->SetPos(50);

	pSlider->GetPos();

	//获取列表控件
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);

	pListCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	pListCtrl->InsertColumn(0, L"编号", LVCFMT_LEFT,100);
	pListCtrl->InsertColumn(1, L"姓名", LVCFMT_LEFT,200);
	pListCtrl->InsertColumn(2, L"性别", LVCFMT_LEFT,150);

	pListCtrl->InsertItem(0, L"1");
	pListCtrl->SetItemText(0, 1, L"张三");
	pListCtrl->SetItemText(0, 2, L"男");

	pListCtrl->InsertItem(1, L"2");
	pListCtrl->SetItemText(1, 1, L"李四");
	pListCtrl->SetItemText(1, 2, L"女");

	CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
	//CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);

	m_spin.Create(WS_CHILD | WS_VISIBLE | UDS_SETBUDDYINT | UDS_NOTHOUSANDS | UDS_WRAP, CRect(0, 0, 20, 50), this, 1029);


	m_spin.SetBuddy(pEdit3);
	m_spin.SetRange32(0, 1000);
	m_spin.SetPos(50);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWindowDlg::OnPaint()
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
HCURSOR CWindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWindowDlg::OnBnClickedBtnTest1()
{
	MessageBox(L"提示1");
}


void CWindowDlg::OnBnClickedBtnTest2()
{
	//GetDlgItem(IDC_BTN_TEST2)->EnableWindow(FALSE);

	//CDateTimeCtrl* pDateTimeCtrl = (CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1);
	//CTime time;
	//pDateTimeCtrl->GetTime(time);

	//CIPAddressCtrl* pIPAddressCtrl = (CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1);
	//CString strIPAddress;
	//pIPAddressCtrl->GetWindowText(strIPAddress);

	//MessageBox(strIPAddress);

	//SetWindowText(time.Format(L"%Y-%m-%d %H:%M:%S"));

	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);
	//int nSel = pListCtrl->GetSelectionMark();//虚线选中

	POSITION pos = pListCtrl->GetFirstSelectedItemPosition();
	int nSel = pListCtrl->GetNextSelectedItem(pos);

	if (nSel < 0)
	{
		MessageBox(L"清先选中在修改");
		return;
	}

	pListCtrl->SetItemText(nSel, 0, L"5");
	pListCtrl->SetItemText(nSel, 1, L"王五");
	pListCtrl->SetItemText(nSel, 2, L"女");

	pListCtrl->GetItemCount();
	pListCtrl->DeleteAllItems();


	//pListCtrl->DeleteItem(nSel);
}


int CWindowDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	//第一种方法
	m_btnTest.Create(L"Hello", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(20, 100, 100, 160), this, IDC_BTN_HELLO);

	//第二种方法
	//人 = 躯体(m_btnTest) + 灵魂(hWnd)
	//HWND hWnd = ::CreateWindow(L"Button", L"Hello", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 20, 100,100, 60, m_hWnd, (HMENU)IDC_BTN_HELLO, AfxGetInstanceHandle(), NULL);
	//m_btnTest.Attach(hWnd);

	//m_edit.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_WANTRETURN | WS_VSCROLL, CRect(0, 180, 400, 300), this, 1026);

	m_check.Create(L"单选", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, CRect(250, 300,280, 320), this, 1027);


	return 0;
}

void CWindowDlg::OnBnClickedBtnHello()
{
	MessageBox(L"Hello");

	//m_btnTest.SetWindowText(L"点击");
}

void CWindowDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	//m_btnTest.Detach();
}
