
// WindowDlg.h : ͷ�ļ�
//

#pragma once
#include "MyButton.h"

// CWindowDlg �Ի���
class CWindowDlg : public CDialogEx
{
// ����
public:
	CWindowDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_WINDOW_DIALOG };

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
	CMyButton m_btnTest;						//���԰�ť
	CEdit m_edit;
	CButton   m_check;							//��ѡ��ť
	CSpinButtonCtrl m_spin;
	afx_msg void OnBnClickedBtnTest1();
	afx_msg void OnBnClickedBtnTest2();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void OnBnClickedBtnHello();
	afx_msg void OnDestroy();
};
