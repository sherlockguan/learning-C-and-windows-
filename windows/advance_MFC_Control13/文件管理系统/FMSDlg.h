
// FMSDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CFMSDlg 对话框
class CFMSDlg : public CDialogEx
{
// 构造
public:
	CFMSDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FMS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_tree;
	CListCtrl m_list;
	CString m_strCurrentPath;
	afx_msg void OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);
	void Find(CString strPath, BOOL bOneOrTwo, HTREEITEM hParentItem);			//查找所有文件
	afx_msg void OnDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
	CString GetTreePath();
	afx_msg void OnBnClickedBtnGoto();
	CString TrimPath(CString strPath);
};
