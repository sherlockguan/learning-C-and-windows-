
#pragma once

class CMFCCalcDlg : public CDialogEx
{

public:
	CMFCCalcDlg(CWnd* pParent = NULL);	

	enum { IDD = IDD_MFCCALC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	

protected:
	HICON m_hIcon;

	
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strResult;		//结果
	CString m_strShow;			//显示	
	CString m_strText;			//临时	
	char    m_symbol;				
	double  m_num1;
	double  m_result;		
	//没学关联变量 不做绑定
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn9();
	afx_msg void OnBnClickedBtn0();
	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnBnClickedBtnClear();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnSub();
	afx_msg void OnBnClickedBtnMul();
	afx_msg void OnBnClickedBtnChu();
	afx_msg void OnBnClickedBtnEqual();
	afx_msg void OnBnClickedBtnDot();
	afx_msg void OnBnClickedBtnPn();
};
