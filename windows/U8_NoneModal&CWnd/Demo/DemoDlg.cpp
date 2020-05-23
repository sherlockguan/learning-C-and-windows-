
// DemoDlg.cpp :
//注意头文件包含顺序

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoDlg



CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CHAT, &CDemoDlg::OnBnClickedBtnChat)
	ON_BN_CLICKED(IDC_BTN_SHOW, &CDemoDlg::OnBnClickedBtnShow)
END_MESSAGE_MAP()


// CDemoDlg ÏûÏ¢´¦Àí³ÌÐò

BOOL CDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		

	//Win32

	return TRUE;  
}

void CDemoDlg::OnPaint()
{
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


HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDemoDlg::OnBnClickedBtnChat()
{
	//CChatDlg dlg;

	//CChatDlg *pDlg = new CChatDlg;

	//pDlg->Create(IDD_CHAT_DLG, this);
	//pDlg->ShowWindow(SW_SHOW);

	// 第二种方式成员变量延长生命周期
	if (m_chatDlg.m_hWnd == NULL)
	{
		m_chatDlg.Create(IDD_CHAT_DLG, this);
	}	
	else
	{
		m_chatDlg.DestroyWindow();//·ÇÄ£Ì¬¶Ô»°¿òÏú»Ù
		m_chatDlg.Create(IDD_CHAT_DLG, this);
	}
	m_chatDlg.ShowWindow(SW_SHOW);
}


void CDemoDlg::OnBnClickedBtnShow()
{
	if (m_chatDlg.m_hWnd != NULL)
		m_chatDlg.ShowWindow(SW_SHOW);
}
