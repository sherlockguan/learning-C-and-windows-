// Page1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TaskManager.h"
#include "Page1.h"
#include "afxdialogex.h"


// CPage1 �Ի���

IMPLEMENT_DYNAMIC(CPage1, CDialogEx)

CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage1::IDD, pParent)
{

}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CPage1, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CPage1 ��Ϣ�������


BOOL CPage1::OnEraseBkgnd(CDC* pDC)
{
	//��ȡ�Ի���Ŀͻ�����С
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(&rect,RGB(255, 255, 255));

	//return CDialogEx::OnEraseBkgnd(pDC);//������һ����ɫ�ı���
	return TRUE;
}


BOOL CPage1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_list.InsertColumn(0, L"���", LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, L"������", LVCFMT_LEFT, 200);
	m_list.InsertColumn(2, L"���ھ��", LVCFMT_LEFT, 100);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CPage1::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_list.GetSafeHwnd())
	{
		//��ȡ���ڵĴ�С
		CRect rect;
		GetClientRect(&rect);
		m_list.MoveWindow(&rect);
	}
}
