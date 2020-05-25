
// FMSDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FMS.h"
#include "FMSDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFMSDlg 对话框



CFMSDlg::CFMSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFMSDlg::IDD, pParent)
	, m_strCurrentPath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_tree);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Text(pDX, IDC_FILE_PATH, m_strCurrentPath);
}

BEGIN_MESSAGE_MAP(CFMSDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_TREE, &CFMSDlg::OnDblclkTree)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CFMSDlg::OnDblclkList)
	ON_BN_CLICKED(IDC_BTN_GOTO, &CFMSDlg::OnBnClickedBtnGoto)
END_MESSAGE_MAP()


// CFMSDlg 消息处理程序

BOOL CFMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, L"名称", LVCFMT_LEFT, 200);
	m_list.InsertColumn(1, L"类型", LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, L"大小", LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, L"最后修改时间", LVCFMT_LEFT, 200);
	m_list.InsertColumn(4, L"最后访问时间", LVCFMT_LEFT, 200);

	HTREEITEM hRoot = m_tree.InsertItem(L"我的电脑");

	//获取可利用的磁盘信息
	//DWORD dwDrives =  GetLogicalDrives();


	DWORD dwLength = GetLogicalDriveStrings(0, NULL);
	wchar_t *buffer = new wchar_t[dwLength];
	GetLogicalDriveStrings(dwLength, buffer);
	//C:\\0D:\\0
	for (int i = 0; i < dwLength / 4; i++)
	{
		CString str = buffer + i * 4;
		m_tree.InsertItem(str, hRoot);
	}

	delete[] buffer;


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFMSDlg::OnPaint()
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
HCURSOR CFMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFMSDlg::OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	//判断当前选择的是不是根节点
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if (hItem == m_tree.GetRootItem())
	{
		return;
	}

	//获取双击的这一项的文本
	//CString strFilename = m_tree.GetItemText(hItem);	

	CString strFilename = GetTreePath();
	strFilename = TrimPath(strFilename);

	Find(strFilename, TRUE, hItem);

	m_strCurrentPath = strFilename;
	UpdateData(FALSE);

	

	*pResult = 0;
}

//查找所有文件
void CFMSDlg::Find(CString strPath, BOOL bOneOrTwo, HTREEITEM hParentItem)
{
	m_list.DeleteAllItems();

	//C:\\*.*

	CString strFindPath;
	strFindPath.Format(L"%s\\*.*", strPath);

	CFileFind finder;//可以查找具体的一个文件(绝对路径)，也可以查找所有文件(通配符)
	BOOL bFind = finder.FindFile(strFindPath);
	int i = 0;
	while (bFind)
	{
		bFind = finder.FindNextFile();

		//不显示隐藏文件和不显示系统文件
		if (finder.IsHidden())
			continue;

		if (finder.IsDots())
			continue;

		//获取文件名
		CString strFilename = finder.GetFileName();		
		SHFILEINFO shFi = {0};
		CString str = L"D:\\Program Files\\Plants.Vs.Zombies";
		SHGetFileInfo(str, FILE_ATTRIBUTE_NORMAL | FILE_ATTRIBUTE_DIRECTORY, &shFi, sizeof(shFi), SHGFI_ICON | SHGFI_TYPENAME);

		m_list.InsertItem(i, strFilename);
		//如果是两个控件
		if (bOneOrTwo)
		{
			m_tree.InsertItem(strFilename, hParentItem);
		}

		//判断是不是文件夹
		if (TRUE == finder.IsDirectory())
		{
			m_list.SetItemText(i, 1, L"文件夹");
		}
		else
		{
			m_list.SetItemText(i, 1, shFi.szTypeName);
		}
			
		
		//获取文件大小
		ULONGLONG nFileSize = finder.GetLength();
		wchar_t szFileSize[50];
		StrFormatByteSize(nFileSize, szFileSize, 50);
		m_list.SetItemText(i, 2, szFileSize);

		//获取时间
		CTime time;
		finder.GetLastWriteTime(time);
		m_list.SetItemText(i, 3, time.Format(L"%Y-%m-%d %H:%m:%S"));

		finder.GetLastAccessTime(time);
		m_list.SetItemText(i, 4, time.Format(L"%Y-%m-%d %H:%m:%S"));

		
		
		i++;
	}
}

void CFMSDlg::OnDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	//获取选中行
	POSITION pos =  m_list.GetFirstSelectedItemPosition();
	int nSel = m_list.GetNextSelectedItem(pos);
	if (nSel < 0)
		return;

	//获取文件名
	CString strFilename = m_list.GetItemText(nSel, 0);

	//连接起来
	m_strCurrentPath = m_strCurrentPath + L"\\" +  strFilename;
	UpdateData(FALSE);

	Find(m_strCurrentPath, FALSE, NULL);

	*pResult = 0;
}


void CFMSDlg::OnBnClickedBtnGoto()
{
	UpdateData(TRUE);
	Find(m_strCurrentPath, FALSE , NULL);
}

CString CFMSDlg::GetTreePath()
{
	CString strPath;

	//获取当前节点
	HTREEITEM  hCurrentItem = m_tree.GetSelectedItem();

	while (hCurrentItem != m_tree.GetRootItem())
	{
		CString strItemText = m_tree.GetItemText(hCurrentItem);

		strPath = strItemText + "\\" + strPath;

		hCurrentItem = m_tree.GetParentItem(hCurrentItem);
	}

	return strPath;
}

CString CFMSDlg::TrimPath(CString strPath)
{
	if (strPath[strPath.GetLength() - 1] == '\\')
		strPath.Delete(strPath.GetLength() - 1);

	return strPath;
}