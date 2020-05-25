
// WndDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Wnd.h"
#include "WndDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWndDlg �Ի���



CWndDlg::CWndDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWndDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWndDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_GET, &CWndDlg::OnBnClickedBtnGet)
	ON_BN_CLICKED(IDC_BTN_CALC, &CWndDlg::OnBnClickedBtnCalc)
END_MESSAGE_MAP()


// CWndDlg ��Ϣ�������

BOOL CWndDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//��ȡ�б�ؼ�
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
	pList->InsertColumn(0, L"���", LVCFMT_LEFT, 150);
	pList->InsertColumn(1, L"���ڱ���", LVCFMT_LEFT, 150);
	pList->InsertColumn(2, L"���ھ��", LVCFMT_LEFT, 150);
	pList->InsertColumn(3, L"�ؼ�ID", LVCFMT_LEFT, 150);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CWndDlg::OnPaint()
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
HCURSOR CWndDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//��ȡ����
void CWndDlg::OnBnClickedBtnGet()
{
	//��ȡ�б�ؼ�
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);

	CWnd* pWnd;// = GetDesktopWindow();
	pWnd = this->GetWindow(GW_CHILD)->GetWindow(GW_HWNDFIRST);

	int n = 0;
	while (pWnd != NULL)
	{
		CString str;
		str.Format(L"%d", n + 1);
		pList->InsertItem(n, str);


		pWnd->GetWindowText(str);
		pList->SetItemText(n, 1, str);

		str.Format(L"0X%X", pWnd->m_hWnd);
		pList->SetItemText(n, 2, str);

		str.Format(L"%d", pWnd->GetDlgCtrlID());
		pList->SetItemText(n, 3, str);

		pWnd = pWnd->GetNextWindow();
		n++;
	}
	
}


void CWndDlg::OnBnClickedBtnCalc()
{
	//��ȡ�ı����е�ֵ
	//GetDlgItemInt
	//GetDlgItemText
	BOOL b;
	int num1 = GetDlgItemInt(IDC_EDIT1, &b);
	int num2 = GetDlgItemInt(IDC_EDIT2);

	SetDlgItemInt(IDC_EDIT3, num1 + num2);
}
