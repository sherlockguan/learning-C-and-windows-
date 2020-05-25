
// CalcDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "afxdtctl.h"
#include "ATLComTime.h"


// CCalcDlg 对话框
class CCalcDlg : public CDialogEx
{
// 构造
public:
	CCalcDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALC_DIALOG };

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
	afx_msg void OnBnClickedBtnCalc();
	// 数值1
	int m_num1;
	int m_num2;
	int m_result;
	CString m_strText;
	CString m_strcombobox;
	BOOL m_bLanqiu;
	CString m_strListBox;
	int m_sex;
	int m_age;
	CEdit m_edit;
	CButton m_check;
	CComboBox m_comboBox;
	afx_msg void OnBnClickedButton2();
	CSliderCtrl m_slider;
	CProgressCtrl m_progressCtrl;
	CListCtrl m_list;
	CMonthCalCtrl m_MonthCalCtrl;
	COleDateTime m_time;
	CDateTimeCtrl m_dateTimeCtrl;
};
