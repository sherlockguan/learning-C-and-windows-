
// FMSDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FMS.h"
#include "FMSDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFMSDlg �Ի���



CFMSDlg::CFMSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFMSDlg::IDD, pParent)
	, m_strCurrentPath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_tree);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Text(pDX, IDC_FILE_PATH, m_strCurrentPath);
}

BEGIN_MESSAGE_MAP(CFMSDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_TREE, &CFMSDlg::OnDblclkTree)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CFMSDlg::OnDblclkList)
	ON_BN_CLICKED(IDC_BTN_GOTO, &CFMSDlg::OnBnClickedBtnGoto)
END_MESSAGE_MAP()


// CFMSDlg ��Ϣ�������

BOOL CFMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, L"����", LVCFMT_LEFT, 200);
	m_list.InsertColumn(1, L"����", LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, L"��С", LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, L"����޸�ʱ��", LVCFMT_LEFT, 200);
	m_list.InsertColumn(4, L"������ʱ��", LVCFMT_LEFT, 200);

	HTREEITEM hRoot = m_tree.InsertItem(L"�ҵĵ���");

	//��ȡ�����õĴ�����Ϣ
	//DWORD dwDrives =  GetLogicalDrives();


	DWORD dwLength = GetLogicalDriveStrings(0, NULL);
	wchar_t *buffer = new wchar_t[dwLength];
	GetLogicalDriveStrings(dwLength, buffer);
	//C:\\0D:\\0
	for (int i = 0; i < dwLength / 4; i++)
	{
		CString str = buffer + i * 4;
		m_tree.InsertItem(str, hRoot);
	}

	delete[] buffer;


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFMSDlg::OnPaint()
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
HCURSOR CFMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFMSDlg::OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	//�жϵ�ǰѡ����ǲ��Ǹ��ڵ�
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if (hItem == m_tree.GetRootItem())
	{
		return;
	}

	//��ȡ˫������һ����ı�
	//CString strFilename = m_tree.GetItemText(hItem);	

	CString strFilename = GetTreePath();
	strFilename = TrimPath(strFilename);

	Find(strFilename, TRUE, hItem);

	m_strCurrentPath = strFilename;
	UpdateData(FALSE);

	

	*pResult = 0;
}

//���������ļ�
void CFMSDlg::Find(CString strPath, BOOL bOneOrTwo, HTREEITEM hParentItem)
{
	m_list.DeleteAllItems();

	//C:\\*.*

	CString strFindPath;
	strFindPath.Format(L"%s\\*.*", strPath);

	CFileFind finder;//���Բ��Ҿ����һ���ļ�(����·��)��Ҳ���Բ��������ļ�(ͨ���)
	BOOL bFind = finder.FindFile(strFindPath);
	int i = 0;
	while (bFind)
	{
		bFind = finder.FindNextFile();

		//����ʾ�����ļ��Ͳ���ʾϵͳ�ļ�
		if (finder.IsHidden())
			continue;

		if (finder.IsDots())
			continue;

		//��ȡ�ļ���
		CString strFilename = finder.GetFileName();		
		SHFILEINFO shFi = {0};
		CString str = L"D:\\Program Files\\Plants.Vs.Zombies";
		SHGetFileInfo(str, FILE_ATTRIBUTE_NORMAL | FILE_ATTRIBUTE_DIRECTORY, &shFi, sizeof(shFi), SHGFI_ICON | SHGFI_TYPENAME);

		m_list.InsertItem(i, strFilename);
		//����������ؼ�
		if (bOneOrTwo)
		{
			m_tree.InsertItem(strFilename, hParentItem);
		}

		//�ж��ǲ����ļ���
		if (TRUE == finder.IsDirectory())
		{
			m_list.SetItemText(i, 1, L"�ļ���");
		}
		else
		{
			m_list.SetItemText(i, 1, shFi.szTypeName);
		}
			
		
		//��ȡ�ļ���С
		ULONGLONG nFileSize = finder.GetLength();
		wchar_t szFileSize[50];
		StrFormatByteSize(nFileSize, szFileSize, 50);
		m_list.SetItemText(i, 2, szFileSize);

		//��ȡʱ��
		CTime time;
		finder.GetLastWriteTime(time);
		m_list.SetItemText(i, 3, time.Format(L"%Y-%m-%d %H:%m:%S"));

		finder.GetLastAccessTime(time);
		m_list.SetItemText(i, 4, time.Format(L"%Y-%m-%d %H:%m:%S"));

		
		
		i++;
	}
}

void CFMSDlg::OnDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	//��ȡѡ����
	POSITION pos =  m_list.GetFirstSelectedItemPosition();
	int nSel = m_list.GetNextSelectedItem(pos);
	if (nSel < 0)
		return;

	//��ȡ�ļ���
	CString strFilename = m_list.GetItemText(nSel, 0);

	//��������
	m_strCurrentPath = m_strCurrentPath + L"\\" +  strFilename;
	UpdateData(FALSE);

	Find(m_strCurrentPath, FALSE, NULL);

	*pResult = 0;
}


void CFMSDlg::OnBnClickedBtnGoto()
{
	UpdateData(TRUE);
	Find(m_strCurrentPath, FALSE , NULL);
}

CString CFMSDlg::GetTreePath()
{
	CString strPath;

	//��ȡ��ǰ�ڵ�
	HTREEITEM  hCurrentItem = m_tree.GetSelectedItem();

	while (hCurrentItem != m_tree.GetRootItem())
	{
		CString strItemText = m_tree.GetItemText(hCurrentItem);

		strPath = strItemText + "\\" + strPath;

		hCurrentItem = m_tree.GetParentItem(hCurrentItem);
	}

	return strPath;
}

CString CFMSDlg::TrimPath(CString strPath)
{
	if (strPath[strPath.GetLength() - 1] == '\\')
		strPath.Delete(strPath.GetLength() - 1);

	return strPath;
}