
// DunkaiCRMDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DunkaiCRM.h"
#include "DunkaiCRMDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDunkaiCRMDlg 对话框



CDunkaiCRMDlg::CDunkaiCRMDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDunkaiCRMDlg::IDD, pParent)
	, m_nWorkNum(0)
	, m_strName(_T(""))
	, m_nSex(0)
	, m_nAge(0)
	, m_nHeight(0)
	, m_fWeight(0)
	, m_strJob(_T(""))
	, m_bPaoniu(FALSE)
	, m_bPashan(FALSE)
	, m_bKSing(FALSE)
	, m_bGame(FALSE)
	, m_joinTime(COleDateTime::GetCurrentTime())
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDunkaiCRMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WORK_NUM, m_nWorkNum);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Radio(pDX, IDC_RADIO1, m_nSex);
	DDX_Text(pDX, IDC_EDIT2, m_nAge);
	DDX_Text(pDX, IDC_EDIT3, m_nHeight);
	DDX_Text(pDX, IDC_EDIT4, m_fWeight);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
	DDX_Text(pDX, IDC_EDIT5, m_strJob);
	DDX_Check(pDX, IDC_CHECK1, m_bPaoniu);
	DDX_Check(pDX, IDC_CHECK2, m_bPashan);
	DDX_Check(pDX, IDC_CHECK3, m_bKSing);
	DDX_Check(pDX, IDC_CHECK4, m_bGame);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_joinTime);
	DDX_Control(pDX, IDC_HEAD, m_pHeadCtrl);
	DDX_Control(pDX, IDC_LIST, m_list);
}

BEGIN_MESSAGE_MAP(CDunkaiCRMDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CDunkaiCRMDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_ADD, &CDunkaiCRMDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BUTN_DEL, &CDunkaiCRMDlg::OnBnClickedButnDel)
	ON_BN_CLICKED(IDC_BTN_MODIFY, &CDunkaiCRMDlg::OnBnClickedBtnModify)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CDunkaiCRMDlg::OnBnClickedBtnSave)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CDunkaiCRMDlg::OnDblclkList)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDunkaiCRMDlg 消息处理程序

BOOL CDunkaiCRMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, L"工号", LVCFMT_LEFT, 80);
	m_list.InsertColumn(1, L"姓名", LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, L"性别", LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, L"年龄", LVCFMT_LEFT, 100);
	m_list.InsertColumn(4, L"身高", LVCFMT_LEFT, 100);
	m_list.InsertColumn(5, L"体重", LVCFMT_LEFT, 100);
	m_list.InsertColumn(6, L"部门", LVCFMT_LEFT, 100);
	m_list.InsertColumn(7, L"职位", LVCFMT_LEFT, 100);
	m_list.InsertColumn(8, L"兴趣爱好", LVCFMT_LEFT, 100);
	m_list.InsertColumn(9, L"入职时间", LVCFMT_LEFT, 100);

	m_ComboBox.AddString(L"C++部门");
	m_ComboBox.AddString(L"Java部门");
	m_ComboBox.AddString(L"Python部门");
	m_ComboBox.AddString(L"iOS部门");
	m_ComboBox.AddString(L"前端部门");
	m_ComboBox.AddString(L"大数据部门");
	m_ComboBox.AddString(L"人事部门");
	m_ComboBox.AddString(L"行政部门");
	m_ComboBox.AddString(L"财务部门");
	m_ComboBox.SetCurSel(0);

	//读取文件，加载数据
	CFile file;
	if (FALSE == file.Open(L"./em.dat", CFile::modeRead))
		return TRUE;

	//循环读取文件
	Employer em;
	int i = 0;
	while (file.Read(&em, sizeof(em)))
	{
		CString str;
		str.Format(L"%d", em.worknum);
		m_list.InsertItem(i, str);
		m_list.SetItemText(i, 1, em.name);
		i++;
	}



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDunkaiCRMDlg::OnPaint()
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
HCURSOR CDunkaiCRMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDunkaiCRMDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}

//添加
void CDunkaiCRMDlg::OnBnClickedBtnAdd()
{
	UpdateData(TRUE);

	if (m_nWorkNum == 0 || m_strName.IsEmpty())
	{
		MessageBox(L"请填写工号或姓名",L"温馨提示");
		return;
	}

	//获取列表总行数
	int nCount = m_list.GetItemCount();

	CString str;
	str.Format(L"%d", m_nWorkNum);

	m_list.InsertItem(nCount, str);//工号
	m_list.SetItemText(nCount, 1, m_strName);//姓名
	m_list.SetItemText(nCount, 2, (m_nSex == 0 ? L"男" : (m_nSex == 1 ? L"女" : L"Gay")));//性别
	
	str.Format(L"%d", m_nAge);
	m_list.SetItemText(nCount, 3, str);//年龄

	str.Format(L"%d", m_nHeight);
	m_list.SetItemText(nCount, 4, str);//身高

	str.Format(L"%.2f", m_fWeight);
	m_list.SetItemText(nCount, 5, str);//体重

	m_ComboBox.GetWindowText(str);
	m_list.SetItemText(nCount, 6, str);//部门

	m_list.SetItemText(nCount, 7, m_strJob);//职位

	//兴趣爱好
	CString strXingqu;
	if (m_bPaoniu)
		strXingqu += L"泡妞;";
	if (m_bPashan)
		strXingqu += L"爬山;";
	if (m_bKSing)
		strXingqu += L"K歌;";
	if (m_bGame)
		strXingqu += L"玩游戏;";
	m_list.SetItemText(nCount, 8, strXingqu);

	//入职时间
	m_list.SetItemText(nCount, 9, m_joinTime.Format(L"%Y-%m-%d"));
}


void CDunkaiCRMDlg::OnBnClickedButnDel()
{
	//如果选择没
	while (1)
	{
		POSITION pos = m_list.GetFirstSelectedItemPosition();
		if (pos == NULL)
			break;
		int nSel = m_list.GetNextSelectedItem(pos);
		m_list.DeleteItem(nSel);
	}	
}

//修改
void CDunkaiCRMDlg::OnBnClickedBtnModify()
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nSel = m_list.GetNextSelectedItem(pos);
	if (nSel < 0)
	{
		MessageBox(L"请选中后在修改");
		return;
	}


	UpdateData(TRUE);
	if (m_nWorkNum == 0 || m_strName.IsEmpty())
	{
		MessageBox(L"请填写工号或姓名", L"温馨提示");
		return;
	}

	CString str;
	str.Format(L"%d", m_nWorkNum);

	m_list.SetItemText(nSel, 0, str);//工号
	m_list.SetItemText(nSel, 1, m_strName);//姓名
	m_list.SetItemText(nSel, 2, (m_nSex == 0 ? L"男" : (m_nSex == 1 ? L"女" : L"Gay")));//性别

	str.Format(L"%d", m_nAge);
	m_list.SetItemText(nSel, 3, str);//年龄

	str.Format(L"%d", m_nHeight);
	m_list.SetItemText(nSel, 4, str);//身高

	str.Format(L"%.2f", m_fWeight);
	m_list.SetItemText(nSel, 5, str);//体重

	m_ComboBox.GetWindowText(str);
	m_list.SetItemText(nSel, 6, str);//部门

	m_list.SetItemText(nSel, 7, m_strJob);//职位

	//兴趣爱好
	CString strXingqu;
	if (m_bPaoniu)
		strXingqu += L"泡妞;";
	if (m_bPashan)
		strXingqu += L"爬山;";
	if (m_bKSing)
		strXingqu += L"K歌;";
	if (m_bGame)
		strXingqu += L"玩游戏;";
	m_list.SetItemText(nSel, 8, strXingqu);

	//入职时间
	m_list.SetItemText(nSel, 9, m_joinTime.Format(L"%Y-%m-%d"));
}

//保存
void CDunkaiCRMDlg::OnBnClickedBtnSave()
{
	//打开文件
	CFile file;
	if (FALSE == file.Open(L"./em.dat", CFile::modeCreate | CFile::modeWrite))
	{
		MessageBox(L"打开文件失败");
		return;
	}

	int nCount = m_list.GetItemCount();

	for (int i = 0; i < nCount;i++)
	{
		Employer em = {0};

		em.worknum = _wtoi(m_list.GetItemText(i, 0));//工号
		wcscpy(em.name, m_list.GetItemText(i, 0));//姓名
		//剩下的各位同学补充


		file.Write(&em, sizeof(em));
	}

	file.Close();
}


void CDunkaiCRMDlg::OnDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nSel = m_list.GetNextSelectedItem(pos);
	if (nSel < 0)
		return;

	CString str;
	//从列表中读取数据还原到控件
	m_nWorkNum = _wtoi(m_list.GetItemText(nSel, 0));//工号
	m_strName = m_list.GetItemText(nSel, 1);//姓名
	str = m_list.GetItemText(nSel, 2);//性别
	if (str == L"男")
		m_nSex = 0;
	else if (str == L"女")
		m_nSex = 1;
	else if (str == L"Gay")
		m_nSex = 2;

	m_nAge = _wtoi(m_list.GetItemText(nSel, 3));//年龄
	m_nHeight = _wtoi(m_list.GetItemText(nSel, 4));//身高
	m_fWeight = _wtof(m_list.GetItemText(nSel, 5));//体重
	CString strDeparment = m_list.GetItemText(nSel, 6); //部门
	m_ComboBox.SetWindowText(strDeparment);
	//职位
	m_strJob = m_list.GetItemText(nSel, 7);
	//兴趣爱好
	m_bPaoniu = FALSE, m_bPashan = FALSE, m_bKSing = FALSE, m_bGame = FALSE;
	CString strXingqu = m_list.GetItemText(nSel, 8);
	if (strXingqu.Find(L"泡妞") != -1)
	{
		m_bPaoniu = TRUE;
	}
	if (strXingqu.Find(L"爬山") != -1)
	{
		m_bPashan = TRUE;
	}
	if (strXingqu.Find(L"K歌") != -1)
	{
		m_bKSing = TRUE;
	}
	if (strXingqu.Find(L"游戏") != -1)
	{
		m_bGame = TRUE;
	}

	//入职时间
	CString strTime = m_list.GetItemText(nSel, 9);
	if (strTime.IsEmpty())
		m_joinTime = COleDateTime::GetCurrentTime();
	else
		m_joinTime.ParseDateTime(strTime);
	
	UpdateData(FALSE);

	*pResult = 0;
}


void CDunkaiCRMDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	OnBnClickedBtnSave();
}
