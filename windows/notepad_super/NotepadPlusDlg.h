
// NotepadPlusDlg.h : 头文件
//

#pragma once


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
	COLORREF m_newColor;
	CString  m_strFaceName;
	int      m_nFontSize;
	CString  m_strFilePath;	
	BOOL	 m_bFind;				//查找
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnSelect();
	afx_msg void OnOpen();
	afx_msg void OnSaveAs();
	afx_msg void OnColor();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnFont();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnFind();
	afx_msg void OnReplace();
	LRESULT OnFindRepleace(WPARAM wParam, LPARAM lParam);


};
