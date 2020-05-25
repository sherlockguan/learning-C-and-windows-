
// NotepadPlusDlg.h : ͷ�ļ�
//

#pragma once


// CNotepadPlusDlg �Ի���
class CNotepadPlusDlg : public CDialogEx
{
// ����
public:
	CNotepadPlusDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_NOTEPADPLUS_DIALOG };

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
	COLORREF m_newColor;
	CString  m_strFaceName;
	int      m_nFontSize;
	CString  m_strFilePath;	
	BOOL	 m_bFind;				//����
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
