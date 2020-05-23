
// DemoDlg.cpp : ÊµÏÖÎÄ¼þ
//注意头文件包含顺序

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoDlg ¶Ô»°¿ò



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

	// ÉèÖÃ´Ë¶Ô»°¿òµÄÍ¼±ê¡£  µ±Ó¦ÓÃ³ÌÐòÖ÷´°¿Ú²»ÊÇ¶Ô»°¿òÊ±£¬¿ò¼Ü½«×Ô¶¯
	//  Ö´ÐÐ´Ë²Ù×÷
	SetIcon(m_hIcon, TRUE);			// ÉèÖÃ´óÍ¼±ê
	SetIcon(m_hIcon, FALSE);		// ÉèÖÃÐ¡Í¼±ê

	//Win32µ±ÖÐÊµÏÖ·ÇÄ£Ì¬¶Ô»°¿ò CreateDialog

	return TRUE;  // ³ý·Ç½«½¹µãÉèÖÃµ½¿Ø¼þ£¬·ñÔò·µ»Ø TRUE
}

// Èç¹ûÏò¶Ô»°¿òÌí¼Ó×îÐ¡»¯°´Å¥£¬ÔòÐèÒªÏÂÃæµÄ´úÂë
//  À´»æÖÆ¸ÃÍ¼±ê¡£  ¶ÔÓÚÊ¹ÓÃÎÄµµ/ÊÓÍ¼Ä£ÐÍµÄ MFC Ó¦ÓÃ³ÌÐò£¬
//  Õâ½«ÓÉ¿ò¼Ü×Ô¶¯Íê³É¡£

void CDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ÓÃÓÚ»æÖÆµÄÉè±¸ÉÏÏÂÎÄ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ê¹Í¼±êÔÚ¹¤×÷Çø¾ØÐÎÖÐ¾ÓÖÐ
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// »æÖÆÍ¼±ê
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//µ±ÓÃ»§ÍÏ¶¯×îÐ¡»¯´°¿ÚÊ±ÏµÍ³µ÷ÓÃ´Ëº¯ÊýÈ¡µÃ¹â±ê
//ÏÔÊ¾¡£
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDemoDlg::OnBnClickedBtnChat()
{
	//CChatDlg dlg;//¾Ö²¿±äÁ¿

	//µÚÒ»ÖÖ·½Ê½£ºnew
	//CChatDlg *pDlg = new CChatDlg;

	//pDlg->Create(IDD_CHAT_DLG, this);
	//pDlg->ShowWindow(SW_SHOW);

	//µÚ¶þÖÖ·½Ê½£º³ÉÔ±±äÁ¿ 第二种方式成员变量延长生命周期
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
