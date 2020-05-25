
// DunkaiCRMDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "ATLComTime.h"
#include "afxcmn.h"


// CDunkaiCRMDlg 对话框
class CDunkaiCRMDlg : public CDialogEx
{
// 构造
public:
	CDunkaiCRMDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DUNKAICRM_DIALOG };

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
	afx_msg void OnBnClickedOk();
	UINT m_nWorkNum;
	CString m_strName;
	int m_nSex;
	UINT m_nAge;
	UINT m_nHeight;
	float m_fWeight;
	CComboBox m_ComboBox;
	CString m_strJob;
	BOOL m_bPaoniu;
	BOOL m_bPashan;
	BOOL m_bKSing;
	BOOL m_bGame;
	COleDateTime m_joinTime;
	CStatic m_pHeadCtrl;
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedButnDel();
	afx_msg void OnBnClickedBtnModify();
	afx_msg void OnBnClickedBtnSave();
	CListCtrl m_list;
	afx_msg void OnDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
};
