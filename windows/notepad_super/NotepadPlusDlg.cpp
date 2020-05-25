
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



//ע��WM_FINDREPLACE��Ϣ
const UINT WM_FINDREPLACE = RegisterWindowMessage(FINDMSGSTRING);



// CNotepadPlusDlg �Ի���



CNotepadPlusDlg::CNotepadPlusDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNotepadPlusDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_newColor = RGB(0,0,0);//��ɫ
	m_strFaceName = L"����";
	m_nFontSize = 140;
	m_bFind = TRUE;
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
	ON_COMMAND(IDM_COLOR, &CNotepadPlusDlg::OnColor)
	ON_WM_CTLCOLOR()
	ON_COMMAND(IDM_FONT, &CNotepadPlusDlg::OnFont)
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_COMMAND(IDM_FIND, &CNotepadPlusDlg::OnFind)
	ON_COMMAND(IDM_REPLACE, &CNotepadPlusDlg::OnReplace)
	ON_REGISTERED_MESSAGE(WM_FINDREPLACE, &CNotepadPlusDlg::OnFindRepleace)
END_MESSAGE_MAP()


// CNotepadPlusDlg ��Ϣ�������

BOOL CNotepadPlusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//Position
	int left = theApp.GetProfileInt(L"Position", L"left", 0);
	int top = theApp.GetProfileInt(L"Position", L"top", 0);
	int right = theApp.GetProfileInt(L"Position", L"right", 0);
	int bottom = theApp.GetProfileInt(L"Position", L"bottom", 0);

	MoveWindow(left, top, right-left, bottom-top);

	//����
	CString strFaceName = theApp.GetProfileString(L"Font", L"facename", L"����");
	int size = theApp.GetProfileInt(L"Font", L"size", 140);

	static CFont font;
	font.CreatePointFont(size, strFaceName);
	//���༭�ؼ���������
	GetDlgItem(IDC_EDIT2)->SetFont(&font);

	//��ɫ
	m_newColor = theApp.GetProfileInt(L"Color", L"color", RGB(0,0,0));




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

//��ɫ
void CNotepadPlusDlg::OnColor()
{
	COLORREF color=RGB(255,0,0); //������ 0->255, ��ɫ��0,0,0 ��ɫ��255,255,255 �� ��ɫ:255,0,0

	CColorDialog dlg(color);	
	if (IDCANCEL == dlg.DoModal())
		return;

	//��ȡ��ɫ
	m_newColor = dlg.GetColor();

	//ˢ��һ����ɫ���ػ�һ��
	Invalidate(TRUE);//TRUE:��ͬ����Ҳˢ�£�FALSE:ֻˢ��ǰ��
}

//WM_CTLCOLOR��Ϣ
HBRUSH CNotepadPlusDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_EDIT2:
		pDC->SetTextColor(m_newColor);//
		break;
	}


	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

//����
void CNotepadPlusDlg::OnFont()
{
	CFontDialog dlg;
	if (IDCANCEL == dlg.DoModal())
		return;

	m_strFaceName = dlg.GetFaceName();
	m_nFontSize = dlg.GetSize();

	//��������
	
	CFont font;
	font.CreatePointFont(m_nFontSize, m_strFaceName);
	//���༭�ؼ���������
	GetDlgItem(IDC_EDIT2)->SetFont(&font);
}

//WM_SIZE������ʲôʱ�򣺴��ڴ�С�仯��ʱ�򣬴���һ��������СҲ�ᷢ���仯���ؼ���û�У��ؼ�û�д���
void CNotepadPlusDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	CWnd* pEdit = GetDlgItem(IDC_EDIT2);
	if (pEdit)
	{
		pEdit->MoveWindow(0, 0, cx, cy, FALSE);
		pEdit->SetFocus();
	}
}


void CNotepadPlusDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	//��ȡ���ڵĿ�͸�
	CRect rect;
	GetWindowRect(&rect);

	//Position
	theApp.WriteProfileInt(L"Position", L"left", rect.left);
	theApp.WriteProfileInt(L"Position", L"top", rect.top);
	theApp.WriteProfileInt(L"Position", L"right", rect.right);
	theApp.WriteProfileInt(L"Position", L"bottom", rect.bottom);

	//����
	theApp.WriteProfileString(L"Font", L"facename", m_strFaceName);
	theApp.WriteProfileInt(L"Font", L"size", m_nFontSize);

	//��ɫ
	theApp.WriteProfileInt(L"Color", L"color", m_newColor);
}

//����
void CNotepadPlusDlg::OnFind()
{
	CFindReplaceDialog *pFindDialog = new CFindReplaceDialog;//�Զ��ͷ�
	pFindDialog->Create(TRUE, NULL, NULL);
	pFindDialog->ShowWindow(SW_SHOW);

	m_bFind = TRUE;
}

//�滻
void CNotepadPlusDlg::OnReplace()
{
	CFindReplaceDialog *pFindDialog = new CFindReplaceDialog;//�Զ��ͷ�
	pFindDialog->Create(FALSE, NULL, NULL);
	pFindDialog->ShowWindow(SW_SHOW);

	m_bFind = FALSE;
}

//���ҡ��滻��Ӧ����
LRESULT CNotepadPlusDlg::OnFindRepleace(WPARAM wParam, LPARAM lParam)
{
	//��ȡ����ָ��
	CFindReplaceDialog* pFindReplaceDlg =  CFindReplaceDialog::GetNotifier(lParam);
	if (pFindReplaceDlg == NULL)
		return 0;

	

	CString strFindString, strRepleaceString;

	BOOL isSearchDown = pFindReplaceDlg->SearchDown();			//�ж��Ƿ������ϻ������²���
	BOOL isMatchCase =  pFindReplaceDlg->MatchCase();			//�ж��Ƿ���ƥ���Сд
	BOOL isMatchWholeWord =  pFindReplaceDlg->MatchWholeWord();	//�ж��Ƿ���ȫ��ƥ��

	strFindString = pFindReplaceDlg->GetFindString();			//��ȡ�����ַ���
	strRepleaceString = pFindReplaceDlg->GetReplaceString();	//��ȡ�滻�ַ���

	CString strContent;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit->GetWindowText(strContent);

	//���������յ�
	//int nLength = strContent.GetLength();
	int nStartIndex = 0, nEndIndex = 0;

	//����
	if (m_bFind == TRUE)
	{
		//���ٶԻ���
		if (pFindReplaceDlg->IsTerminating())
		{
			pFindReplaceDlg->DestroyWindow();
			pFindReplaceDlg = NULL;
			return 0;
		}

		//���²���
		if (isSearchDown)
		{
			//��ȡ����λ��
			pEdit->GetSel(nStartIndex, nEndIndex);

			//�ַ����Ĳ���
			nStartIndex = strContent.Find(strFindString, nEndIndex);
			//���û���ҵ�����ͷ��ʼ��
			if (nStartIndex == -1)
			{
				nStartIndex = strContent.Find(strFindString, 0);

				//�ڶ��ң������Ҳ���
				if (nStartIndex == -1)
				{
					CString str;
					str.Format(L"�Ҳ���\"%s\"", strFindString);
					MessageBox(str, L"�������±�", MB_OK | MB_ICONINFORMATION);
					return 0;
				}
				else//�ڶ��Σ��ҵ���
				{
					pEdit->SetSel(nStartIndex, nStartIndex + strFindString.GetLength());
					pEdit->SetFocus();
				}
			}
			else//�ҵ��ˣ����
			{
				pEdit->SetSel(nStartIndex, nStartIndex + strFindString.GetLength());
				pEdit->SetFocus();
			}
		}
		else//���ϲ���
		{
			CString strReverseContent = strContent.MakeReverse();//��ת�ı�
			CString strReverseFindString =  strFindString.MakeReverse();//��ת�����ַ���
			//ԭ������λ��
			pEdit->GetSel(nStartIndex, nEndIndex);

			//����
			nStartIndex = strReverseContent.Find(strReverseFindString, strContent.GetLength() - nStartIndex);
			
			//û�ҵ�
			if (nStartIndex == -1)
			{
				//�ڶ��β���
				nStartIndex = strReverseContent.Find(strReverseFindString, 0);

				if (nStartIndex == -1)
				{
					CString str;
					str.Format(L"�Ҳ���\"%s\"", strFindString.MakeReverse());
					MessageBox(str, L"�������±�", MB_OK | MB_ICONINFORMATION);
					return 0;
				}
				else
				{
					nEndIndex = strContent.GetLength() - nStartIndex - 1;

					pEdit->SetSel(nEndIndex + 1 - strFindString.GetLength(), nEndIndex + 1);
					pEdit->SetFocus();
				}
			}
			else//�ҵ���,���
			{
				nEndIndex = strContent.GetLength() - nStartIndex - 1;

				pEdit->SetSel(nEndIndex + 1 - strFindString.GetLength(), nEndIndex + 1);
				pEdit->SetFocus();
			}
		}

	}
	else//�滻
	{
		//�滻��һ��
		if (pFindReplaceDlg->FindNext())
		{
			pEdit->GetSel(nStartIndex, nEndIndex);
			nStartIndex =  strContent.Find(strFindString, nEndIndex);

			//û�ҵ�
			if (nStartIndex == -1)
			{
				nStartIndex = strContent.Find(strFindString, 0);
				if (nStartIndex == -1)
				{
					CString str;
					str.Format(L"�Ҳ���\"%s\"", strFindString.MakeReverse());
					MessageBox(str, L"�������±�", MB_OK | MB_ICONINFORMATION);
					return 0;
				}
				else//�ҵ���
				{
					pEdit->SetSel(nStartIndex, nStartIndex + strFindString.GetLength());
					pEdit->SetFocus();
				}
			}
			else//�ҵ���
			{
				pEdit->SetSel(nStartIndex, nStartIndex + strFindString.GetLength());
				pEdit->SetFocus();
			}
		}
		//�滻��ǰ
		if (pFindReplaceDlg->ReplaceCurrent())
		{
			nStartIndex = strContent.Find(strFindString, nEndIndex);
			if (nStartIndex == -1)
			{
				CString str;
				str.Format(L"�Ҳ���\"%s\"", strFindString.MakeReverse());
				MessageBox(str, L"�������±�", MB_OK | MB_ICONINFORMATION);
				return 0;
			}
			else//�ҵ���
			{
				pEdit->GetSel(nStartIndex, nEndIndex);
				//��ȡǰ����ı�
				CString strLeft = strContent.Left(nStartIndex);
				//��ȡ������ı�
				CString strRight = strContent.Right(strContent.GetLength() - nEndIndex);
				CString strNew = strLeft + strRepleaceString + strRight;
				pEdit->SetWindowText(strNew);
			}
		}

		//�滻ȫ��
		if (pFindReplaceDlg->ReplaceAll())
		{
			strContent.Replace(strFindString, strRepleaceString);
			pEdit->SetWindowText(strContent);
		}
	}


	return 0;
}