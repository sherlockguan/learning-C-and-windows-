
// TaskManagerDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "Page1.h"
#include "Page2.h"


// CTaskManagerDlg 对话框
class CTaskManagerDlg : public CDialogEx
{
// 构造
public:
	CTaskManagerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TASKMANAGER_DIALOG };

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
	CTabCtrl m_tab;
	CPage1 m_page1;
	CPage2 m_page2;
	afx_msg void OnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
