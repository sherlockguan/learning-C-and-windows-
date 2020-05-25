
// NotepadPlusDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "NotepadPlus.h"
#include "NotepadPlusDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepadPlusDlg �Ի���



CNotepadPlusDlg::CNotepadPlusDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNotepadPlusDlg::IDD, pParent)
	, m_strSendMsg(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNotepadPlusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT21, m_richEdit);
	DDX_Text(pDX, IDC_EDIT1, m_strSendMsg);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CNotepadPlusDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEND, &CNotepadPlusDlg::OnBnClickedBtnSend)
END_MESSAGE_MAP()


// CNotepadPlusDlg ��Ϣ�������

BOOL CNotepadPlusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CNotepadPlusDlg::OnPaint()
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
HCURSOR CNotepadPlusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//����
void CNotepadPlusDlg::OnBnClickedBtnSend()
{
	UpdateData(TRUE);

	if (m_strSendMsg.IsEmpty())
	{
		MessageBox(L"���ܷ��Ϳ���Ϣ");
		return;
	}

	CHARFORMAT cf = {0};
	cf.cbSize = sizeof(CHARFORMAT);
	cf.dwMask = CFM_BOLD | CFM_COLOR | CFM_FACE | CFM_ITALIC | CFM_SIZE | CFM_STRIKEOUT | CFM_UNDERLINE;
	cf.dwEffects = CFE_BOLD;
	cf.yHeight = 200;
	cf.crTextColor = RGB(0,0,0);
	wcscpy(cf.szFaceName, _T("����"));
	m_richEdit.SetWordCharFormat(cf);

	//��ȡ�ı�����
	int nLength = m_richEdit.GetWindowTextLength();
	m_richEdit.SetSel(nLength, -1);

	CTime t = CTime::GetCurrentTime();
	CString str;
	str.Format(L"%s ������ʦ\r\n", t.Format(L"%H:%M:%S"));
	m_richEdit.ReplaceSel(str);

	CHARFORMAT cf2 = { 0 };
	cf2.cbSize = sizeof(CHARFORMAT);
	cf2.dwMask = CFM_BOLD | CFM_COLOR | CFM_FACE | CFM_ITALIC | CFM_SIZE | CFM_STRIKEOUT | CFM_UNDERLINE;
	cf2.dwEffects = CFE_ITALIC | CFE_UNDERLINE;
	cf2.yHeight = 200;
	cf2.crTextColor = RGB(255, 0, 0);
	wcscpy(cf2.szFaceName, _T("����"));
	m_richEdit.SetWordCharFormat(cf2);
	nLength = m_richEdit.GetWindowTextLength();
	m_richEdit.SetSel(nLength, -1);
	m_richEdit.ReplaceSel(m_strSendMsg+L"\r\n");

	
	long dwStyle = ::GetWindowLong(m_edit.m_hWnd, GWL_STYLE);
	dwStyle = dwStyle | WS_VSCROLL | ES_WANTRETURN;

	if (dwStyle & WS_VSCROLL)
	{
		int n = 0;
	}

	::SetWindowLong(m_edit.m_hWnd, GWL_STYLE, dwStyle);
	

	//m_edit.ModifyStyle(0, WS_VSCROLL|ES_WANTRETURN);
}
