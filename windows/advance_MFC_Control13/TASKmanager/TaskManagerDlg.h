
// TaskManagerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "Page1.h"
#include "Page2.h"


// CTaskManagerDlg �Ի���
class CTaskManagerDlg : public CDialogEx
{
// ����
public:
	CTaskManagerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TASKMANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CPage1 m_page1;
	CPage2 m_page2;
	afx_msg void OnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
