
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
	CString m_strFilePath;	
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnSelect();
	afx_msg void OnOpen();
	afx_msg void OnSaveAs();
};
