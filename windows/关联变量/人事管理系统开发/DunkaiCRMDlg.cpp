
// DunkaiCRMDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DunkaiCRM.h"
#include "DunkaiCRMDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDunkaiCRMDlg �Ի���



CDunkaiCRMDlg::CDunkaiCRMDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDunkaiCRMDlg::IDD, pParent)
	, m_nWorkNum(0)
	, m_strName(_T(""))
	, m_nSex(0)
	, m_nAge(0)
	, m_nHeight(0)
	, m_fWeight(0)
	, m_strJob(_T(""))
	, m_bPaoniu(FALSE)
	, m_bPashan(FALSE)
	, m_bKSing(FALSE)
	, m_bGame(FALSE)
	, m_joinTime(COleDateTime::GetCurrentTime())
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDunkaiCRMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WORK_NUM, m_nWorkNum);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Radio(pDX, IDC_RADIO1, m_nSex);
	DDX_Text(pDX, IDC_EDIT2, m_nAge);
	DDX_Text(pDX, IDC_EDIT3, m_nHeight);
	DDX_Text(pDX, IDC_EDIT4, m_fWeight);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
	DDX_Text(pDX, IDC_EDIT5, m_strJob);
	DDX_Check(pDX, IDC_CHECK1, m_bPaoniu);
	DDX_Check(pDX, IDC_CHECK2, m_bPashan);
	DDX_Check(pDX, IDC_CHECK3, m_bKSing);
	DDX_Check(pDX, IDC_CHECK4, m_bGame);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_joinTime);
	DDX_Control(pDX, IDC_HEAD, m_pHeadCtrl);
	DDX_Control(pDX, IDC_LIST, m_list);
}

BEGIN_MESSAGE_MAP(CDunkaiCRMDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CDunkaiCRMDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_ADD, &CDunkaiCRMDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BUTN_DEL, &CDunkaiCRMDlg::OnBnClickedButnDel)
	ON_BN_CLICKED(IDC_BTN_MODIFY, &CDunkaiCRMDlg::OnBnClickedBtnModify)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CDunkaiCRMDlg::OnBnClickedBtnSave)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CDunkaiCRMDlg::OnDblclkList)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDunkaiCRMDlg ��Ϣ�������

BOOL CDunkaiCRMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, L"����", LVCFMT_LEFT, 80);
	m_list.InsertColumn(1, L"����", LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, L"�Ա�", LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, L"����", LVCFMT_LEFT, 100);
	m_list.InsertColumn(4, L"���", LVCFMT_LEFT, 100);
	m_list.InsertColumn(5, L"����", LVCFMT_LEFT, 100);
	m_list.InsertColumn(6, L"����", LVCFMT_LEFT, 100);
	m_list.InsertColumn(7, L"ְλ", LVCFMT_LEFT, 100);
	m_list.InsertColumn(8, L"��Ȥ����", LVCFMT_LEFT, 100);
	m_list.InsertColumn(9, L"��ְʱ��", LVCFMT_LEFT, 100);

	m_ComboBox.AddString(L"C++����");
	m_ComboBox.AddString(L"Java����");
	m_ComboBox.AddString(L"Python����");
	m_ComboBox.AddString(L"iOS����");
	m_ComboBox.AddString(L"ǰ�˲���");
	m_ComboBox.AddString(L"�����ݲ���");
	m_ComboBox.AddString(L"���²���");
	m_ComboBox.AddString(L"��������");
	m_ComboBox.AddString(L"������");
	m_ComboBox.SetCurSel(0);

	//��ȡ�ļ�����������
	CFile file;
	if (FALSE == file.Open(L"./em.dat", CFile::modeRead))
		return TRUE;

	//ѭ����ȡ�ļ�
	Employer em;
	int i = 0;
	while (file.Read(&em, sizeof(em)))
	{
		CString str;
		str.Format(L"%d", em.worknum);
		m_list.InsertItem(i, str);
		m_list.SetItemText(i, 1, em.name);
		i++;
	}



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDunkaiCRMDlg::OnPaint()
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
HCURSOR CDunkaiCRMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDunkaiCRMDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}

//���
void CDunkaiCRMDlg::OnBnClickedBtnAdd()
{
	UpdateData(TRUE);

	if (m_nWorkNum == 0 || m_strName.IsEmpty())
	{
		MessageBox(L"����д���Ż�����",L"��ܰ��ʾ");
		return;
	}

	//��ȡ�б�������
	int nCount = m_list.GetItemCount();

	CString str;
	str.Format(L"%d", m_nWorkNum);

	m_list.InsertItem(nCount, str);//����
	m_list.SetItemText(nCount, 1, m_strName);//����
	m_list.SetItemText(nCount, 2, (m_nSex == 0 ? L"��" : (m_nSex == 1 ? L"Ů" : L"Gay")));//�Ա�
	
	str.Format(L"%d", m_nAge);
	m_list.SetItemText(nCount, 3, str);//����

	str.Format(L"%d", m_nHeight);
	m_list.SetItemText(nCount, 4, str);//���

	str.Format(L"%.2f", m_fWeight);
	m_list.SetItemText(nCount, 5, str);//����

	m_ComboBox.GetWindowText(str);
	m_list.SetItemText(nCount, 6, str);//����

	m_list.SetItemText(nCount, 7, m_strJob);//ְλ

	//��Ȥ����
	CString strXingqu;
	if (m_bPaoniu)
		strXingqu += L"���;";
	if (m_bPashan)
		strXingqu += L"��ɽ;";
	if (m_bKSing)
		strXingqu += L"K��;";
	if (m_bGame)
		strXingqu += L"����Ϸ;";
	m_list.SetItemText(nCount, 8, strXingqu);

	//��ְʱ��
	m_list.SetItemText(nCount, 9, m_joinTime.Format(L"%Y-%m-%d"));
}


void CDunkaiCRMDlg::OnBnClickedButnDel()
{
	//���ѡ��û
	while (1)
	{
		POSITION pos = m_list.GetFirstSelectedItemPosition();
		if (pos == NULL)
			break;
		int nSel = m_list.GetNextSelectedItem(pos);
		m_list.DeleteItem(nSel);
	}	
}

//�޸�
void CDunkaiCRMDlg::OnBnClickedBtnModify()
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nSel = m_list.GetNextSelectedItem(pos);
	if (nSel < 0)
	{
		MessageBox(L"��ѡ�к����޸�");
		return;
	}


	UpdateData(TRUE);
	if (m_nWorkNum == 0 || m_strName.IsEmpty())
	{
		MessageBox(L"����д���Ż�����", L"��ܰ��ʾ");
		return;
	}

	CString str;
	str.Format(L"%d", m_nWorkNum);

	m_list.SetItemText(nSel, 0, str);//����
	m_list.SetItemText(nSel, 1, m_strName);//����
	m_list.SetItemText(nSel, 2, (m_nSex == 0 ? L"��" : (m_nSex == 1 ? L"Ů" : L"Gay")));//�Ա�

	str.Format(L"%d", m_nAge);
	m_list.SetItemText(nSel, 3, str);//����

	str.Format(L"%d", m_nHeight);
	m_list.SetItemText(nSel, 4, str);//���

	str.Format(L"%.2f", m_fWeight);
	m_list.SetItemText(nSel, 5, str);//����

	m_ComboBox.GetWindowText(str);
	m_list.SetItemText(nSel, 6, str);//����

	m_list.SetItemText(nSel, 7, m_strJob);//ְλ

	//��Ȥ����
	CString strXingqu;
	if (m_bPaoniu)
		strXingqu += L"���;";
	if (m_bPashan)
		strXingqu += L"��ɽ;";
	if (m_bKSing)
		strXingqu += L"K��;";
	if (m_bGame)
		strXingqu += L"����Ϸ;";
	m_list.SetItemText(nSel, 8, strXingqu);

	//��ְʱ��
	m_list.SetItemText(nSel, 9, m_joinTime.Format(L"%Y-%m-%d"));
}

//����
void CDunkaiCRMDlg::OnBnClickedBtnSave()
{
	//���ļ�
	CFile file;
	if (FALSE == file.Open(L"./em.dat", CFile::modeCreate | CFile::modeWrite))
	{
		MessageBox(L"���ļ�ʧ��");
		return;
	}

	int nCount = m_list.GetItemCount();

	for (int i = 0; i < nCount;i++)
	{
		Employer em = {0};

		em.worknum = _wtoi(m_list.GetItemText(i, 0));//����
		wcscpy(em.name, m_list.GetItemText(i, 0));//����
		//ʣ�µĸ�λͬѧ����


		file.Write(&em, sizeof(em));
	}

	file.Close();
}


void CDunkaiCRMDlg::OnDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nSel = m_list.GetNextSelectedItem(pos);
	if (nSel < 0)
		return;

	CString str;
	//���б��ж�ȡ���ݻ�ԭ���ؼ�
	m_nWorkNum = _wtoi(m_list.GetItemText(nSel, 0));//����
	m_strName = m_list.GetItemText(nSel, 1);//����
	str = m_list.GetItemText(nSel, 2);//�Ա�
	if (str == L"��")
		m_nSex = 0;
	else if (str == L"Ů")
		m_nSex = 1;
	else if (str == L"Gay")
		m_nSex = 2;

	m_nAge = _wtoi(m_list.GetItemText(nSel, 3));//����
	m_nHeight = _wtoi(m_list.GetItemText(nSel, 4));//���
	m_fWeight = _wtof(m_list.GetItemText(nSel, 5));//����
	CString strDeparment = m_list.GetItemText(nSel, 6); //����
	m_ComboBox.SetWindowText(strDeparment);
	//ְλ
	m_strJob = m_list.GetItemText(nSel, 7);
	//��Ȥ����
	m_bPaoniu = FALSE, m_bPashan = FALSE, m_bKSing = FALSE, m_bGame = FALSE;
	CString strXingqu = m_list.GetItemText(nSel, 8);
	if (strXingqu.Find(L"���") != -1)
	{
		m_bPaoniu = TRUE;
	}
	if (strXingqu.Find(L"��ɽ") != -1)
	{
		m_bPashan = TRUE;
	}
	if (strXingqu.Find(L"K��") != -1)
	{
		m_bKSing = TRUE;
	}
	if (strXingqu.Find(L"��Ϸ") != -1)
	{
		m_bGame = TRUE;
	}

	//��ְʱ��
	CString strTime = m_list.GetItemText(nSel, 9);
	if (strTime.IsEmpty())
		m_joinTime = COleDateTime::GetCurrentTime();
	else
		m_joinTime.ParseDateTime(strTime);
	
	UpdateData(FALSE);

	*pResult = 0;
}


void CDunkaiCRMDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	OnBnClickedBtnSave();
}
