
// NotepadPlusDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


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
	CRichEditCtrl m_richEdit;
	afx_msg void OnBnClickedBtnSend();
	CString m_strSendMsg;
	CEdit m_edit;
};
