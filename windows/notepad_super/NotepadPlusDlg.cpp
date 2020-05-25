
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



//注册WM_FINDREPLACE消息
const UINT WM_FINDREPLACE = RegisterWindowMessage(FINDMSGSTRING);



// CNotepadPlusDlg 对话框



CNotepadPlusDlg::CNotepadPlusDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNotepadPlusDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_newColor = RGB(0,0,0);//黑色
	m_strFaceName = L"宋体";
	m_nFontSize = 140;
	m_bFind = TRUE;
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
	ON_COMMAND(IDM_COLOR, &CNotepadPlusDlg::OnColor)
	ON_WM_CTLCOLOR()
	ON_COMMAND(IDM_FONT, &CNotepadPlusDlg::OnFont)
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_COMMAND(IDM_FIND, &CNotepadPlusDlg::OnFind)
	ON_COMMAND(IDM_REPLACE, &CNotepadPlusDlg::OnReplace)
	ON_REGISTERED_MESSAGE(WM_FINDREPLACE, &CNotepadPlusDlg::OnFindRepleace)
END_MESSAGE_MAP()


// CNotepadPlusDlg 消息处理程序

BOOL CNotepadPlusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//Position
	int left = theApp.GetProfileInt(L"Position", L"left", 0);
	int top = theApp.GetProfileInt(L"Position", L"top", 0);
	int right = theApp.GetProfileInt(L"Position", L"right", 0);
	int bottom = theApp.GetProfileInt(L"Position", L"bottom", 0);

	MoveWindow(left, top, right-left, bottom-top);

	//字体
	CString strFaceName = theApp.GetProfileString(L"Font", L"facename", L"宋体");
	int size = theApp.GetProfileInt(L"Font", L"size", 140);

	static CFont font;
	font.CreatePointFont(size, strFaceName);
	//给编辑控件设置字体
	GetDlgItem(IDC_EDIT2)->SetFont(&font);

	//颜色
	m_newColor = theApp.GetProfileInt(L"Color", L"color", RGB(0,0,0));




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

//颜色
void CNotepadPlusDlg::OnColor()
{
	COLORREF color=RGB(255,0,0); //红绿蓝 0->255, 黑色：0,0,0 白色：255,255,255 ， 红色:255,0,0

	CColorDialog dlg(color);	
	if (IDCANCEL == dlg.DoModal())
		return;

	//获取颜色
	m_newColor = dlg.GetColor();

	//刷新一下颜色，重绘一下
	Invalidate(TRUE);//TRUE:连同背景也刷新，FALSE:只刷新前景
}

//WM_CTLCOLOR消息
HBRUSH CNotepadPlusDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_EDIT2:
		pDC->SetTextColor(m_newColor);//
		break;
	}


	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

//字体
void CNotepadPlusDlg::OnFont()
{
	CFontDialog dlg;
	if (IDCANCEL == dlg.DoModal())
		return;

	m_strFaceName = dlg.GetFaceName();
	m_nFontSize = dlg.GetSize();

	//创建字体
	
	CFont font;
	font.CreatePointFont(m_nFontSize, m_strFaceName);
	//给编辑控件设置字体
	GetDlgItem(IDC_EDIT2)->SetFont(&font);
}

//WM_SIZE发生在什么时候：窗口大小变化的时候，窗口一创建，大小也会发生变化，控件还没有，控件没有创建
void CNotepadPlusDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	CWnd* pEdit = GetDlgItem(IDC_EDIT2);
	if (pEdit)
	{
		pEdit->MoveWindow(0, 0, cx, cy, FALSE);
		pEdit->SetFocus();
	}
}


void CNotepadPlusDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	//获取窗口的宽和高
	CRect rect;
	GetWindowRect(&rect);

	//Position
	theApp.WriteProfileInt(L"Position", L"left", rect.left);
	theApp.WriteProfileInt(L"Position", L"top", rect.top);
	theApp.WriteProfileInt(L"Position", L"right", rect.right);
	theApp.WriteProfileInt(L"Position", L"bottom", rect.bottom);

	//字体
	theApp.WriteProfileString(L"Font", L"facename", m_strFaceName);
	theApp.WriteProfileInt(L"Font", L"size", m_nFontSize);

	//颜色
	theApp.WriteProfileInt(L"Color", L"color", m_newColor);
}

//查找
void CNotepadPlusDlg::OnFind()
{
	CFindReplaceDialog *pFindDialog = new CFindReplaceDialog;//自动释放
	pFindDialog->Create(TRUE, NULL, NULL);
	pFindDialog->ShowWindow(SW_SHOW);

	m_bFind = TRUE;
}

//替换
void CNotepadPlusDlg::OnReplace()
{
	CFindReplaceDialog *pFindDialog = new CFindReplaceDialog;//自动释放
	pFindDialog->Create(FALSE, NULL, NULL);
	pFindDialog->ShowWindow(SW_SHOW);

	m_bFind = FALSE;
}

//查找、替换响应函数
LRESULT CNotepadPlusDlg::OnFindRepleace(WPARAM wParam, LPARAM lParam)
{
	//获取窗口指针
	CFindReplaceDialog* pFindReplaceDlg =  CFindReplaceDialog::GetNotifier(lParam);
	if (pFindReplaceDlg == NULL)
		return 0;

	

	CString strFindString, strRepleaceString;

	BOOL isSearchDown = pFindReplaceDlg->SearchDown();			//判断是否是向上还是向下查找
	BOOL isMatchCase =  pFindReplaceDlg->MatchCase();			//判断是否是匹配大小写
	BOOL isMatchWholeWord =  pFindReplaceDlg->MatchWholeWord();	//判断是否是全字匹配

	strFindString = pFindReplaceDlg->GetFindString();			//获取查找字符串
	strRepleaceString = pFindReplaceDlg->GetReplaceString();	//获取替换字符串

	CString strContent;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit->GetWindowText(strContent);

	//光标的起点和终点
	//int nLength = strContent.GetLength();
	int nStartIndex = 0, nEndIndex = 0;

	//查找
	if (m_bFind == TRUE)
	{
		//销毁对话框
		if (pFindReplaceDlg->IsTerminating())
		{
			pFindReplaceDlg->DestroyWindow();
			pFindReplaceDlg = NULL;
			return 0;
		}

		//向下查找
		if (isSearchDown)
		{
			//获取光标的位置
			pEdit->GetSel(nStartIndex, nEndIndex);

			//字符串的查找
			nStartIndex = strContent.Find(strFindString, nEndIndex);
			//如果没有找到，从头开始找
			if (nStartIndex == -1)
			{
				nStartIndex = strContent.Find(strFindString, 0);

				//第二找，还是找不到
				if (nStartIndex == -1)
				{
					CString str;
					str.Format(L"找不到\"%s\"", strFindString);
					MessageBox(str, L"超级记事本", MB_OK | MB_ICONINFORMATION);
					return 0;
				}
				else//第二次，找到了
				{
					pEdit->SetSel(nStartIndex, nStartIndex + strFindString.GetLength());
					pEdit->SetFocus();
				}
			}
			else//找到了，标记
			{
				pEdit->SetSel(nStartIndex, nStartIndex + strFindString.GetLength());
				pEdit->SetFocus();
			}
		}
		else//向上查找
		{
			CString strReverseContent = strContent.MakeReverse();//翻转文本
			CString strReverseFindString =  strFindString.MakeReverse();//翻转查找字符串
			//原来光标的位置
			pEdit->GetSel(nStartIndex, nEndIndex);

			//查找
			nStartIndex = strReverseContent.Find(strReverseFindString, strContent.GetLength() - nStartIndex);
			
			//没找到
			if (nStartIndex == -1)
			{
				//第二次查找
				nStartIndex = strReverseContent.Find(strReverseFindString, 0);

				if (nStartIndex == -1)
				{
					CString str;
					str.Format(L"找不到\"%s\"", strFindString.MakeReverse());
					MessageBox(str, L"超级记事本", MB_OK | MB_ICONINFORMATION);
					return 0;
				}
				else
				{
					nEndIndex = strContent.GetLength() - nStartIndex - 1;

					pEdit->SetSel(nEndIndex + 1 - strFindString.GetLength(), nEndIndex + 1);
					pEdit->SetFocus();
				}
			}
			else//找到了,标记
			{
				nEndIndex = strContent.GetLength() - nStartIndex - 1;

				pEdit->SetSel(nEndIndex + 1 - strFindString.GetLength(), nEndIndex + 1);
				pEdit->SetFocus();
			}
		}

	}
	else//替换
	{
		//替换下一个
		if (pFindReplaceDlg->FindNext())
		{
			pEdit->GetSel(nStartIndex, nEndIndex);
			nStartIndex =  strContent.Find(strFindString, nEndIndex);

			//没找到
			if (nStartIndex == -1)
			{
				nStartIndex = strContent.Find(strFindString, 0);
				if (nStartIndex == -1)
				{
					CString str;
					str.Format(L"找不到\"%s\"", strFindString.MakeReverse());
					MessageBox(str, L"超级记事本", MB_OK | MB_ICONINFORMATION);
					return 0;
				}
				else//找到了
				{
					pEdit->SetSel(nStartIndex, nStartIndex + strFindString.GetLength());
					pEdit->SetFocus();
				}
			}
			else//找到了
			{
				pEdit->SetSel(nStartIndex, nStartIndex + strFindString.GetLength());
				pEdit->SetFocus();
			}
		}
		//替换当前
		if (pFindReplaceDlg->ReplaceCurrent())
		{
			nStartIndex = strContent.Find(strFindString, nEndIndex);
			if (nStartIndex == -1)
			{
				CString str;
				str.Format(L"找不到\"%s\"", strFindString.MakeReverse());
				MessageBox(str, L"超级记事本", MB_OK | MB_ICONINFORMATION);
				return 0;
			}
			else//找到了
			{
				pEdit->GetSel(nStartIndex, nEndIndex);
				//截取前面的文本
				CString strLeft = strContent.Left(nStartIndex);
				//截取后面的文本
				CString strRight = strContent.Right(strContent.GetLength() - nEndIndex);
				CString strNew = strLeft + strRepleaceString + strRight;
				pEdit->SetWindowText(strNew);
			}
		}

		//替换全部
		if (pFindReplaceDlg->ReplaceAll())
		{
			strContent.Replace(strFindString, strRepleaceString);
			pEdit->SetWindowText(strContent);
		}
	}


	return 0;
}