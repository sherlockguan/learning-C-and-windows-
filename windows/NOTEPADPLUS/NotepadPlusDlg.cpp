
// NotepadPlusDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "NotepadPlus.h"
#include "NotepadPlusDlg.h"
#include "afxdialogex.h"
#include "mychar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepadPlusDlg �Ի���



CNotepadPlusDlg::CNotepadPlusDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNotepadPlusDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNotepadPlusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNotepadPlusDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CNotepadPlusDlg::OnBnClickedOk)
	//ON_BN_CLICKED(IDC_BTN_SELECT, &CNotepadPlusDlg::OnBnClickedBtnSelect)
	ON_COMMAND(IDM_OPEN, &CNotepadPlusDlg::OnOpen)
	ON_COMMAND(IDM_SAVE_AS, &CNotepadPlusDlg::OnSaveAs)
END_MESSAGE_MAP()


// CNotepadPlusDlg ��Ϣ�������

BOOL CNotepadPlusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CNotepadPlusDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CNotepadPlusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNotepadPlusDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}

//���ѡ��ť
void CNotepadPlusDlg::OnBnClickedBtnSelect()
{
	//CFileDialog => CCommandDialog => CDialog => CWnd
	//����ѡ���ļ��еģ�ֻ��ѡ���ļ�
	//��һ����������ʾ�ļ��Ի�������ͣ���(TRUE)�������Ϊ(FALSE)
	/*
	CFileDialog dlg(TRUE, L"txt", L"hello", OFN_ALLOWMULTISELECT, L"�ı��ļ�(*.txt)|*.txt|ͼƬ�ļ�(*.png)|*.png|PPT�ļ�(*.ppt)|*.ppt|�����ļ�(*.*)|*.*||", this);
	if (IDCANCEL == dlg.DoModal())
	{
		return;
	}
	*/

	//CString strFilePath= dlg.GetPathName();
	//CString strFilename = dlg.GetFileName();
	//CString strFileExt = dlg.GetFileExt();
	//CString strFileTitle = dlg.GetFileTitle();
	//SetDlgItemText(IDC_EDIT1, strFilePath);

	//��ѡ
	/*
	POSITION pos = dlg.GetStartPosition();
	while (pos)
	{
		CString str = dlg.GetNextPathName(pos);
		MessageBox(str);
	}
	*/

	//ѡ���ļ��е�
	/*
	CFolderPickerDialog dlg;
	if (IDCANCEL == dlg.DoModal())
		return;
	CString str = dlg.GetPathName();
	SetDlgItemText(IDC_EDIT1, str);
	*/
}

//��
void CNotepadPlusDlg::OnOpen()
{
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
	if (IDCANCEL == dlg.DoModal())
		return;

	m_strFilePath = dlg.GetPathName();

	//Win32��C����д�ģ�ֻ��MFC����C++д��
	CFile file;
	if (FALSE == file.Open(m_strFilePath, CFile::modeRead))
	{
		MessageBox(L"���ļ�ʧ��", L"��ܰ��ʾ", MB_OK);
		return;
	}


	//ѭ����ȡ
	int nLength = file.GetLength();
	char *szContent = new char[nLength + 1];
	memset(szContent, 0, file.GetLength() + 1);

	char buf[101];
	memset(buf, 0, sizeof(char)* 101);

	while (file.Read(buf, 1))
	{
		strcat(szContent, buf);
	}

	file.Close();

	Tchar t;
	wchar_t* p = t.AnsiToUnicode(szContent);

	//���ı��������õ��ؼ���
	SetDlgItemText(IDC_EDIT2, p);

}

//���Ϊ
void CNotepadPlusDlg::OnSaveAs()
{
	CFileDialog dlg(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
	if (IDCANCEL == dlg.DoModal())
		return;

	m_strFilePath = dlg.GetPathName();

	//��ȡ�ؼ��е��ı�
	CString strContent;
	GetDlgItemText(IDC_EDIT2, strContent);

	//д���ļ�
	CFile file;
	if (FALSE == file.Open(m_strFilePath, CFile::modeCreate | CFile::modeWrite))
	{
		MessageBox(L"���ļ�ʧ��", L"��ܰ��ʾ", MB_OK);
		return;
	}

	//��ȡ�ļ�����
	file.GetLength(); //�����ֽ���
	//�����ļ�ָ��λ��
	//���ȥ��ȡ�ļ������һ�Σ����ǲ�֪���ļ��ж��
	//fseek����
	//���ļ����Ŷ���ÿ��ȡһ���ֽڣ�fseekһ�Σ�\r\n
	//���ȥ
	//file.Seek(100);

	Tchar t;
	char* utf8 = t.UnicodeToUtf8(strContent.GetBuffer());

	//д��
	file.Write(utf8, strlen(utf8));

	//�ر��ļ�
	file.Close();
}
