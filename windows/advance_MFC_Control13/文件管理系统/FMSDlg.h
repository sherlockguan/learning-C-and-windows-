
// FMSDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CFMSDlg �Ի���
class CFMSDlg : public CDialogEx
{
// ����
public:
	CFMSDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_FMS_DIALOG };

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
	CTreeCtrl m_tree;
	CListCtrl m_list;
	CString m_strCurrentPath;
	afx_msg void OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);
	void Find(CString strPath, BOOL bOneOrTwo, HTREEITEM hParentItem);			//���������ļ�
	afx_msg void OnDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
	CString GetTreePath();
	afx_msg void OnBnClickedBtnGoto();
	CString TrimPath(CString strPath);
};
