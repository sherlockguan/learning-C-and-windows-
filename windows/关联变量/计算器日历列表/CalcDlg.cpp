
// CalcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalcDlg �Ի���


//���ȿ�ʼִ��
CCalcDlg::CCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalcDlg::IDD, pParent)
	, m_num1(20)
	, m_num2(50)
	, m_result(0)
	, m_strText(_T(""))
	, m_strcombobox(_T("�й�"))
	, m_bLanqiu(FALSE)
	, m_strListBox(_T("123"))
	, m_sex(2)
	, m_age(0)
	, m_time(2020,1,1,0,0,0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

//��ֵ����
void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{

	//SetDlgItemInt(IDC_EDIT1, m_num1);
	//m_num1 = GetDlgItemInt(IDC_EDIT1);

	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDX_Text(pDX, IDC_EDIT3, m_result);
	DDX_Text(pDX, IDC_EDIT4, m_strText);
	DDX_CBString(pDX, IDC_COMBO1, m_strcombobox);
	DDX_Check(pDX, IDC_CHECK1, m_bLanqiu);
	DDX_LBString(pDX, IDC_LIST1, m_strListBox);
	DDX_Radio(pDX, IDC_RADIO1, m_sex);
	DDX_Text(pDX, IDC_EDIT5, m_age);		//���ݽ���

	DDV_MinMaxInt(pDX, m_age, 20, 120);		//������֤

	DDX_Control(pDX, IDC_EDIT6, m_edit);
	DDX_Control(pDX, IDC_CHECK3, m_check);
	DDX_Control(pDX, IDC_COMBO2, m_comboBox);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_PROGRESS1, m_progressCtrl);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_MONTHCALENDAR1, m_MonthCalCtrl);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_time);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_dateTimeCtrl);
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CALC, &CCalcDlg::OnBnClickedBtnCalc)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalcDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCalcDlg ��Ϣ�������

//OnInitDialog��ʼ�������ڲ���������DoDataExchange����
BOOL CCalcDlg::OnInitDialog()
{
	//m_strcombobox = L"�й�";

	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	m_edit.SetWindowText(L"������ʾ�ı�");
	//m_edit.GetWindowText()

	m_check.SetCheck(1);


	//�ؼ��͹������� ����ҪUpdateData

	m_comboBox.InsertString(0, L"�й�");
	m_comboBox.InsertString(1, L"�ձ�");
	m_comboBox.InsertString(2, L"����");
	m_comboBox.SetCurSel(1);

	m_slider.SetRange(0, 300);
	m_slider.SetPos(140);
	

	m_progressCtrl.SetRange(0, 300);
	m_progressCtrl.SetPos(140);

	m_list.InsertColumn(0, L"����", LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, L"�Ա�", LVCFMT_LEFT, 200);

	CTime time(2020, 4, 1,0,0,0);
	m_MonthCalCtrl.SetCurSel(time);
	CTime t = CTime::GetCurrentTime();
	m_MonthCalCtrl.SetRange(&time, &t);



	//�ܽ᣺
	//��ֵ�͹��������Ϳؼ��͹�������
	//1�����ѡ��ʹ����һ�����͵ı�����
	//�𰸣��������ǵ���������������ǲ���������ֵ��ֻҪ������ֵ�������Ŀؼ�����ʽ����񣬿���ѡ����ֵ�͹�������
	//���Ҫ���Ŀؼ��ķ����ʽ�ȣ�Ҫ�����ؼ�����Ҫ�����ؼ��͹�������

	//2��һ�ֿؼ��ܲ���ͬʱ�����������͵ı����أ�
	//�𰸣����ԣ�

	//3����ֵ�͹���������ؼ��͹��������ܹ�����ת�����ܹ������ȡֵ�����磺ֻ����ֵ�͹��������ܷ��ȡ�ؼ��͹���������
	//���� ֻ�пؼ��͹��������ܷ��ȡ��ֵ�͹�������
	//�𰸣�ֻ����ֵ�͹����������ǲ��ܵõ��ؼ��͹��������ģ�ͬʱҲ���ܵõ��ؼ��Ĵ���ָ��
	//���ǣ�ӵ�пؼ��͹���������һ���ܹ���ȡ���ؼ��е���ֵ�����磬���д���ָ�룬GetWindowText
	//�ؼ����ܴ�����ֵ����ֵ�Ͳ��ܴ���ؼ�

	//4����ֵ�͹���������ҪUpdateData,�ؼ��͹�����������Ҫ����UpdateData

	//5����Ҫע��ĺ���
	//DoDataExchange
	//DDX��������������
	//DDV��������ֵ��֤����

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalcDlg::OnPaint()
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
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//��ֵ�͹�������
void CCalcDlg::OnBnClickedBtnCalc()
{
	/*
	int num1 = GetDlgItemInt(IDC_EDIT1);
	int num2 = GetDlgItemInt(IDC_EDIT2);

	int result = num1 + num2;
	SetDlgItemInt(IDC_EDIT3, result);
	*/

	UpdateData(TRUE);	//TRUE:���ؼ��������ֵˢ�±��浽����������

	//m_result = m_num1 + m_num2;
	//m_strText = L"�ٿ�����";

	if (m_bLanqiu)
	{
		MessageBox(L"ѡ����");
	}
	else
	{
		MessageBox(L"û����");
	}

	UpdateData(FALSE);	//FALSE:�����������е�ֵˢ����ʾ���ؼ�����ʾ
}


void CCalcDlg::OnBnClickedButton2()
{
	//CString str;
	//m_edit.GetWindowText(str);

	//MessageBox(str);

	COleDateTime time;
	m_dateTimeCtrl.GetTime(time);

	SetWindowText(time.Format(L"%H:%M:%S"));
}
