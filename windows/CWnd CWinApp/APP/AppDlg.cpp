
// AppDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "App.h"
#include "AppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAppDlg �Ի���



CAppDlg::CAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAppDlg::IDD, pParent)
{
	//m_hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE( IDR_MAINFRAME));
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAppDlg::OnBnClickedButton1)
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CAppDlg ��Ϣ�������

BOOL CAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���

	//��ȡע���
	int left = theApp.GetProfileInt(L"Position", L"left", 0);
	int right = theApp.GetProfileInt(L"Position", L"right", 0);
	int top = theApp.GetProfileInt(L"Position", L"top", 0);
	int bottom = theApp.GetProfileInt(L"Position", L"bottom", 0);
	MoveWindow(left, top, right-left, bottom-top, TRUE);


	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	CString str;


	SetDlgItemText(IDC_EDIT1, theApp.m_pszAppName);

	str.Format(L"%x", theApp.m_hInstance);
	SetDlgItemText(IDC_EDIT2, str);

	str.Format(L"%x", 0);
	SetDlgItemText(IDC_EDIT3, str);

	SetDlgItemText(IDC_EDIT4, theApp.m_lpCmdLine);

	str.Format(L"%x", theApp.m_nCmdShow);
	SetDlgItemText(IDC_EDIT5, str);

	SetDlgItemText(IDC_EDIT6, theApp.m_bHelpMode?L"TRUE":L"FALSE");

	str.Format(L"%x", theApp.m_pActiveWnd);
	SetDlgItemText(IDC_EDIT7, str);

	SetDlgItemText(IDC_EDIT8, theApp.m_pszExeName);
	SetDlgItemText(IDC_EDIT9, theApp.m_pszHelpFilePath);
	SetDlgItemText(IDC_EDIT10, theApp.m_pszProfileName);
	SetDlgItemText(IDC_EDIT11, theApp.m_pszRegistryKey);
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAppDlg::OnBnClickedButton1()
{
	AfxMessageBox(L"��ʾ");
}


void CAppDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	//��ȡ���ڵĴ�С������
	CRect rect;
	GetWindowRect(&rect);

	//д�������ļ�����ע���
	theApp.WriteProfileInt(L"Position", L"left", rect.left);
	theApp.WriteProfileInt(L"Position", L"top", rect.top);
	theApp.WriteProfileInt(L"Position", L"right", rect.right);
	theApp.WriteProfileInt(L"Position", L"bottom", rect.bottom);

	CString str;
	GetWindowText(str);

	theApp.WriteProfileString(L"Other", L"title", str);
	

}


void CAppDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ



	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}
