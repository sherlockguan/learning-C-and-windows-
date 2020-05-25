
// TaskManagerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TaskManager.h"
#include "TaskManagerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTaskManagerDlg �Ի���



CTaskManagerDlg::CTaskManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTaskManagerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTaskManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

BEGIN_MESSAGE_MAP(CTaskManagerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CTaskManagerDlg::OnSelchangeTab)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CTaskManagerDlg ��Ϣ�������

BOOL CTaskManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	m_tab.InsertItem(0, L"����");
	m_tab.InsertItem(1, L"����");

	m_page1.Create(IDD_PAGE1, &m_tab);
	m_page2.Create(IDD_PAGE2, &m_tab);

	//��ȡTab�Ĵ�С
	CRect rect;
	m_tab.GetClientRect(&rect);
	rect.top += 22;
	rect.left += 1;
	rect.right -= 3;
	rect.bottom -= 2;

	m_page1.MoveWindow(&rect);
	m_page2.MoveWindow(&rect);

	m_page1.ShowWindow(SW_SHOW);
	m_page2.ShowWindow(SW_HIDE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTaskManagerDlg::OnPaint()
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
HCURSOR CTaskManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTaskManagerDlg::OnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	int nSel = m_tab.GetCurSel();
	switch (nSel)
	{
	case 0:
		m_page1.ShowWindow(SW_SHOW);
		m_page2.ShowWindow(SW_HIDE);
		break;
	case 1:
		m_page1.ShowWindow(SW_HIDE);
		m_page2.ShowWindow(SW_SHOW);
		break;
	}

	*pResult = 0;
}


void CTaskManagerDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_tab.GetSafeHwnd())
	{
		m_tab.MoveWindow(10, 10, cx - 20, cy - 20);

		//��ȡTab�Ĵ�С
		CRect rect;
		m_tab.GetClientRect(&rect);
		rect.top += 22;
		rect.left += 1;
		rect.right -= 3;
		rect.bottom -= 2;

		m_page1.MoveWindow(&rect);
		m_page2.MoveWindow(&rect);
	}

}
