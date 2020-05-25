
// WindowDlg.h : 头文件
//

#pragma once
#include "MyButton.h"

// CWindowDlg 对话框
class CWindowDlg : public CDialogEx
{
// 构造
public:
	CWindowDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_WINDOW_DIALOG };

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
	CMyButton m_btnTest;						//测试按钮
	CEdit m_edit;
	CButton   m_check;							//单选按钮
	CSpinButtonCtrl m_spin;
	afx_msg void OnBnClickedBtnTest1();
	afx_msg void OnBnClickedBtnTest2();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void OnBnClickedBtnHello();
	afx_msg void OnDestroy();
};
