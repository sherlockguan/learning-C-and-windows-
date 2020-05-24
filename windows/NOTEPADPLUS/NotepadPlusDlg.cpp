
// NotepadPlusDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "NotepadPlus.h"
#include "NotepadPlusDlg.h"
#include "afxdialogex.h"
#include "mychar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepadPlusDlg 对话框



CNotepadPlusDlg::CNotepadPlusDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNotepadPlusDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNotepadPlusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNotepadPlusDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CNotepadPlusDlg::OnBnClickedOk)
	//ON_BN_CLICKED(IDC_BTN_SELECT, &CNotepadPlusDlg::OnBnClickedBtnSelect)
	ON_COMMAND(IDM_OPEN, &CNotepadPlusDlg::OnOpen)
	ON_COMMAND(IDM_SAVE_AS, &CNotepadPlusDlg::OnSaveAs)
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



void CNotepadPlusDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}

//点击选择按钮
void CNotepadPlusDlg::OnBnClickedBtnSelect()
{
	//CFileDialog => CCommandDialog => CDialog => CWnd
	//不能选择文件夹的，只能选择文件
	//第一个参数：表示文件对话框的类型，打开(TRUE)还是另存为(FALSE)
	/*
	CFileDialog dlg(TRUE, L"txt", L"hello", OFN_ALLOWMULTISELECT, L"文本文件(*.txt)|*.txt|图片文件(*.png)|*.png|PPT文件(*.ppt)|*.ppt|所有文件(*.*)|*.*||", this);
	if (IDCANCEL == dlg.DoModal())
	{
		return;
	}
	*/

	//CString strFilePath= dlg.GetPathName();
	//CString strFilename = dlg.GetFileName();
	//CString strFileExt = dlg.GetFileExt();
	//CString strFileTitle = dlg.GetFileTitle();
	//SetDlgItemText(IDC_EDIT1, strFilePath);

	//多选
	/*
	POSITION pos = dlg.GetStartPosition();
	while (pos)
	{
		CString str = dlg.GetNextPathName(pos);
		MessageBox(str);
	}
	*/

	//选择文件夹的
	/*
	CFolderPickerDialog dlg;
	if (IDCANCEL == dlg.DoModal())
		return;
	CString str = dlg.GetPathName();
	SetDlgItemText(IDC_EDIT1, str);
	*/
}

//打开
void CNotepadPlusDlg::OnOpen()
{
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	if (IDCANCEL == dlg.DoModal())
		return;

	m_strFilePath = dlg.GetPathName();

	//Win32是C语言写的，只有MFC才是C++写的
	CFile file;
	if (FALSE == file.Open(m_strFilePath, CFile::modeRead))
	{
		MessageBox(L"打开文件失败", L"温馨提示", MB_OK);
		return;
	}


	//循环读取
	int nLength = file.GetLength();
	char *szContent = new char[nLength + 1];
	memset(szContent, 0, file.GetLength() + 1);

	char buf[101];
	memset(buf, 0, sizeof(char)* 101);

	while (file.Read(buf, 1))
	{
		strcat(szContent, buf);
	}

	file.Close();

	Tchar t;
	wchar_t* p = t.AnsiToUnicode(szContent);

	//将文本数据设置到控件上
	SetDlgItemText(IDC_EDIT2, p);

}

//另存为
void CNotepadPlusDlg::OnSaveAs()
{
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	if (IDCANCEL == dlg.DoModal())
		return;

	m_strFilePath = dlg.GetPathName();

	//读取控件中的文本
	CString strContent;
	GetDlgItemText(IDC_EDIT2, strContent);

	//写入文件
	CFile file;
	if (FALSE == file.Open(m_strFilePath, CFile::modeCreate | CFile::modeWrite))
	{
		MessageBox(L"打开文件失败", L"温馨提示", MB_OK);
		return;
	}

	//获取文件长度
	file.GetLength(); //返回字节数
	//设置文件指针位置
	//如何去读取文件的最后一段，但是不知道文件有多大？
	//fseek函数
	//将文件反着读，每读取一个字节，fseek一次，\r\n
	//如何去
	//file.Seek(100);

	Tchar t;
	char* utf8 = t.UnicodeToUtf8(strContent.GetBuffer());

	//写入
	file.Write(utf8, strlen(utf8));

	//关闭文件
	file.Close();
}
