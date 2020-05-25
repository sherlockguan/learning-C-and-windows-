
// NotepadPlusDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CNotepadPlusDlg 对话框
class CNotepadPlusDlg : public CDialogEx
{
// 构造
public:
	CNotepadPlusDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_NOTEPADPLUS_DIALOG };

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
	CRichEditCtrl m_richEdit;
	afx_msg void OnBnClickedBtnSend();
	CString m_strSendMsg;
	CEdit m_edit;
};
