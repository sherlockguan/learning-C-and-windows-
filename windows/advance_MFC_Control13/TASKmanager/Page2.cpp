// Page2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TaskManager.h"
#include "Page2.h"
#include "afxdialogex.h"


// CPage2 �Ի���

IMPLEMENT_DYNAMIC(CPage2, CDialogEx)

CPage2::CPage2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage2::IDD, pParent)
{

}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage2, CDialogEx)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CPage2 ��Ϣ�������


BOOL CPage2::OnEraseBkgnd(CDC* pDC)
{
	//��ȡ�Ի���Ŀͻ�����С
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(&rect, RGB(255, 255, 255));

	//return CDialogEx::OnEraseBkgnd(pDC);//������һ����ɫ�ı���
	return TRUE;
}
