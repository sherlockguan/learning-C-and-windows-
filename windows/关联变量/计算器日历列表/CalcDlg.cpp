
// CalcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalcDlg 对话框


//最先开始执行
CCalcDlg::CCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalcDlg::IDD, pParent)
	, m_num1(20)
	, m_num2(50)
	, m_result(0)
	, m_strText(_T(""))
	, m_strcombobox(_T("中国"))
	, m_bLanqiu(FALSE)
	, m_strListBox(_T("123"))
	, m_sex(2)
	, m_age(0)
	, m_time(2020,1,1,0,0,0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

//数值交换
void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{

	//SetDlgItemInt(IDC_EDIT1, m_num1);
	//m_num1 = GetDlgItemInt(IDC_EDIT1);

	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDX_Text(pDX, IDC_EDIT3, m_result);
	DDX_Text(pDX, IDC_EDIT4, m_strText);
	DDX_CBString(pDX, IDC_COMBO1, m_strcombobox);
	DDX_Check(pDX, IDC_CHECK1, m_bLanqiu);
	DDX_LBString(pDX, IDC_LIST1, m_strListBox);
	DDX_Radio(pDX, IDC_RADIO1, m_sex);
	DDX_Text(pDX, IDC_EDIT5, m_age);		//数据交换

	DDV_MinMaxInt(pDX, m_age, 20, 120);		//数据验证

	DDX_Control(pDX, IDC_EDIT6, m_edit);
	DDX_Control(pDX, IDC_CHECK3, m_check);
	DDX_Control(pDX, IDC_COMBO2, m_comboBox);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_PROGRESS1, m_progressCtrl);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_MONTHCALENDAR1, m_MonthCalCtrl);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_time);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_dateTimeCtrl);
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CALC, &CCalcDlg::OnBnClickedBtnCalc)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalcDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCalcDlg 消息处理程序

//OnInitDialog初始化函数内部，调用了DoDataExchange函数
BOOL CCalcDlg::OnInitDialog()
{
	//m_strcombobox = L"中国";

	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_edit.SetWindowText(L"这是显示文本");
	//m_edit.GetWindowText()

	m_check.SetCheck(1);


	//控件型关联变量 不需要UpdateData

	m_comboBox.InsertString(0, L"中国");
	m_comboBox.InsertString(1, L"日本");
	m_comboBox.InsertString(2, L"韩国");
	m_comboBox.SetCurSel(1);

	m_slider.SetRange(0, 300);
	m_slider.SetPos(140);
	

	m_progressCtrl.SetRange(0, 300);
	m_progressCtrl.SetPos(140);

	m_list.InsertColumn(0, L"姓名", LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, L"性别", LVCFMT_LEFT, 200);

	CTime time(2020, 4, 1,0,0,0);
	m_MonthCalCtrl.SetCurSel(time);
	CTime t = CTime::GetCurrentTime();
	m_MonthCalCtrl.SetRange(&time, &t);



	//总结：
	//数值型关联变量和控件型关联变量
	//1、如何选择使用哪一种类型的变量？
	//答案：根据我们的需求来，如果你是操作它的数值，只要关心数值，不关心控件的样式、风格，可以选择数值型关联变量
	//如果要关心控件的风格，样式等，要操作控件，需要建立控件型关联变量

	//2、一种控件能不能同时关联两个类型的变量呢？
	//答案：可以，

	//3、数值型关联变量与控件型关联变量能够互相转化？能够互相获取值？比如：只有数值型关联变量能否获取控件型关联变量，
	//或者 只有控件型关联变量能否获取数值型关联变量
	//答案：只有数值型关联变量，是不能得到控件型关联变量的，同时也不能得到控件的窗口指针
	//但是，拥有控件型关联变量，一般能够获取到控件中的数值，比如，又有窗口指针，GetWindowText
	//控件型能处理数值，数值型不能处理控件

	//4、数值型关联变量需要UpdateData,控件型关联变量不需要调用UpdateData

	//5、需要注意的函数
	//DoDataExchange
	//DDX函数：关联函数
	//DDV函数：数值验证函数

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalcDlg::OnPaint()
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
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//数值型关联变量
void CCalcDlg::OnBnClickedBtnCalc()
{
	/*
	int num1 = GetDlgItemInt(IDC_EDIT1);
	int num2 = GetDlgItemInt(IDC_EDIT2);

	int result = num1 + num2;
	SetDlgItemInt(IDC_EDIT3, result);
	*/

	UpdateData(TRUE);	//TRUE:将控件里面的数值刷新保存到关联变量中

	//m_result = m_num1 + m_num2;
	//m_strText = L"顿开教育";

	if (m_bLanqiu)
	{
		MessageBox(L"选中了");
	}
	else
	{
		MessageBox(L"没中了");
	}

	UpdateData(FALSE);	//FALSE:将关联变量中的值刷新显示到控件中显示
}


void CCalcDlg::OnBnClickedButton2()
{
	//CString str;
	//m_edit.GetWindowText(str);

	//MessageBox(str);

	COleDateTime time;
	m_dateTimeCtrl.GetTime(time);

	SetWindowText(time.Format(L"%H:%M:%S"));
}
