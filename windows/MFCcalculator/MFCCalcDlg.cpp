
// MFCCalcDlg.cpp 
//

#include "stdafx.h"
#include "MFCCalc.h"
#include "MFCCalcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCalcDlg 



CMFCCalcDlg::CMFCCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCCalcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_num1 = 0;
	m_result = 0;
	m_symbol = 0;
}

void CMFCCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCCalcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCCalcDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_1, &CMFCCalcDlg::OnBnClickedBtn1)
	ON_BN_CLICKED(IDC_BTN_2, &CMFCCalcDlg::OnBnClickedBtn2)
	ON_BN_CLICKED(IDC_BTN_3, &CMFCCalcDlg::OnBnClickedBtn3)
	ON_BN_CLICKED(IDC_BTN_4, &CMFCCalcDlg::OnBnClickedBtn4)
	ON_BN_CLICKED(IDC_BTN_5, &CMFCCalcDlg::OnBnClickedBtn5)
	ON_BN_CLICKED(IDC_BTN_6, &CMFCCalcDlg::OnBnClickedBtn6)
	ON_BN_CLICKED(IDC_BTN_7, &CMFCCalcDlg::OnBnClickedBtn7)
	ON_BN_CLICKED(IDC_BTN_8, &CMFCCalcDlg::OnBnClickedBtn8)
	ON_BN_CLICKED(IDC_BTN_9, &CMFCCalcDlg::OnBnClickedBtn9)
	ON_BN_CLICKED(IDC_BTN_0, &CMFCCalcDlg::OnBnClickedBtn0)
	ON_BN_CLICKED(IDC_BTN_BACK, &CMFCCalcDlg::OnBnClickedBtnBack)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CMFCCalcDlg::OnBnClickedBtnClear)
	ON_BN_CLICKED(IDC_BTN_ADD, &CMFCCalcDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_SUB, &CMFCCalcDlg::OnBnClickedBtnSub)
	ON_BN_CLICKED(IDC_BTN_MUL, &CMFCCalcDlg::OnBnClickedBtnMul)
	ON_BN_CLICKED(IDC_BTN_CHU, &CMFCCalcDlg::OnBnClickedBtnChu)
	ON_BN_CLICKED(IDC_BTN_EQUAL, &CMFCCalcDlg::OnBnClickedBtnEqual)
	ON_BN_CLICKED(IDC_BTN_DOT, &CMFCCalcDlg::OnBnClickedBtnDot)
	ON_BN_CLICKED(IDC_BTN_PN, &CMFCCalcDlg::OnBnClickedBtnPn)
END_MESSAGE_MAP()




BOOL CMFCCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);

	SetDlgItemText(IDC_STATIC_RESULT, L"0");

	return TRUE;  
}



void CMFCCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CMFCCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCalcDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CMFCCalcDlg::OnBnClickedBtn1()
{
	m_strResult += L"1";
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
}


void CMFCCalcDlg::OnBnClickedBtn2()
{
	m_strResult += L"2";
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
}


void CMFCCalcDlg::OnBnClickedBtn3()
{
	m_strResult += L"3";
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
}


void CMFCCalcDlg::OnBnClickedBtn4()
{
	m_strResult += L"4";
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
}


void CMFCCalcDlg::OnBnClickedBtn5()
{
	m_strResult += L"5";
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
}


void CMFCCalcDlg::OnBnClickedBtn6()
{
	m_strResult += L"6";
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
}


void CMFCCalcDlg::OnBnClickedBtn7()
{
	m_strResult += L"7";
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
}


void CMFCCalcDlg::OnBnClickedBtn8()
{
	m_strResult += L"8";
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
}


void CMFCCalcDlg::OnBnClickedBtn9()
{
	m_strResult += L"9";
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
}


void CMFCCalcDlg::OnBnClickedBtn0()
{
	m_strResult += L"0";
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
}


void CMFCCalcDlg::OnBnClickedBtnBack()
{
	if (m_strResult.IsEmpty())
	{
		SetDlgItemText(IDC_STATIC_RESULT, L"0");
	}
	else if (m_strResult.GetLength() == 1)
	{
		m_strResult = m_strResult.Left(m_strResult.GetLength() - 1);
		SetDlgItemText(IDC_STATIC_RESULT, L"0");
	}
	else
	{
		m_strResult = m_strResult.Left(m_strResult.GetLength() - 1);
		SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
	}
	
}


void CMFCCalcDlg::OnBnClickedBtnClear()
{
	m_strResult.Empty();
	m_strShow.Empty();
	m_strText.Empty();
	m_num1 = 0;
	m_result = 0;
	m_symbol = 0;

	SetDlgItemText(IDC_STATIC_RESULT, L"0");
	SetDlgItemText(IDC_STATIC_SHOW, L"0");
}

//加
void CMFCCalcDlg::OnBnClickedBtnAdd()
{
	//原来的结果等于
	if (m_strResult.IsEmpty())
	{
		m_num1 = _wtof(m_strText);
	}
	else
	{
		m_num1 = _wtof(m_strResult);
	}
	


	if (m_symbol == 0)
	{
		m_result = m_num1;
	}
	else
	{
		switch (m_symbol)
		{
		case '+':
			m_result = m_result + m_num1;
			break;
		case '-':
			m_result = m_result - m_num1;
			break;
		case '*':
			m_result = m_result * m_num1;
			break;
		case '/':
		{
					if (m_num1 == 0)
					{
						//设置文本
						SetDlgItemText(IDC_STATIC_RESULT, L"除数不能为0");
						m_strResult.Empty();
						m_strShow.Empty();
						m_strText.Empty();
						m_result = 0;
						m_num1 = 0;
						m_symbol = 0;
						return;
					}
					m_result = m_result / m_num1;//
					break;
		}

		}
	}

	//上面显示连续操作文本
	if (m_strResult.IsEmpty())
	{
		m_strShow += m_strText + L"+";
	}
	else
	{
		m_strShow += m_strResult + L"+";
	}
	
	SetDlgItemText(IDC_STATIC_SHOW, m_strShow);
	//下面显示结果
	//下面显示结果
	

	CString str;
	str.Format(L"%lf", m_result);
	SetDlgItemText(IDC_STATIC_RESULT, str);

	m_symbol = '+';

	m_strResult.Empty();

}

//减
void CMFCCalcDlg::OnBnClickedBtnSub()
{
	//原来的结果等于
	if (m_strResult.IsEmpty())
	{
		m_num1 = _wtof(m_strText);
	}
	else
	{
		m_num1 = _wtof(m_strResult);
	}

	if (m_symbol == 0)
	{
		m_result = m_num1;
	}
	else
	{
		switch (m_symbol)
		{
		case '+':
			m_result = m_result + m_num1;
			break;
		case '-':
			m_result = m_result - m_num1;
			break;
		case '*':
			m_result = m_result * m_num1;
			break;
		case '/':
		{
					if (m_num1 == 0)
					{
						//设置文本
						SetDlgItemText(IDC_STATIC_RESULT, L"除数不能为0");
						m_strResult.Empty();
						m_strShow.Empty();
						m_strText.Empty();
						m_result = 0;
						m_num1 = 0;
						m_symbol = 0;
						return;
					}
					m_result = m_result / m_num1;//
					break;
		}

		}
	}

	//上面显示连续操作文本
	if (m_strResult.IsEmpty())
	{
		m_strShow += m_strText + L"-";
	}
	else
	{
		m_strShow += m_strResult + L"-";
	}

	SetDlgItemText(IDC_STATIC_SHOW, m_strShow);
	////下面显示结果
	//if (m_symbol == 0)
	//{
	//	m_result = m_num1;
	//}
	//else
	//{
	//	m_result = m_result - m_num1;
	//}

	CString str;
	str.Format(L"%lf", m_result);
	SetDlgItemText(IDC_STATIC_RESULT, str);

	m_symbol = '-';

	m_strResult.Empty();
}

//乘
void CMFCCalcDlg::OnBnClickedBtnMul()
{
	//原来的结果等于
	if (m_strResult.IsEmpty())
	{
		m_num1 = _wtof(m_strText);
	}
	else
	{
		m_num1 = _wtof(m_strResult);
	}


	if (m_symbol == 0)
	{
		m_result = m_num1;
	}
	else
	{
		switch (m_symbol)
		{
		case '+':
			m_result = m_result + m_num1;
			break;
		case '-':
			m_result = m_result - m_num1;
			break;
		case '*':
			m_result = m_result * m_num1;
			break;
		case '/':
		{
					if (m_num1 == 0)
					{
						//设置文本
						SetDlgItemText(IDC_STATIC_RESULT, L"除数不能为0");
						m_strResult.Empty();
						m_strShow.Empty();
						m_strText.Empty();
						m_result = 0;
						m_num1 = 0;
						m_symbol = 0;
						return;
					}
					m_result = m_result / m_num1;//
					break;
		}

		}
	}

	//上面显示连续操作文本
	if (m_strResult.IsEmpty())
	{
		m_strShow += m_strText + L"*";
	}
	else
	{
		m_strShow += m_strResult + L"*";
	}

	SetDlgItemText(IDC_STATIC_SHOW, m_strShow);
	SetDlgItemText(IDC_STATIC_SHOW, m_strShow);
	//下面显示结果


	CString str;
	str.Format(L"%lf", m_result);
	SetDlgItemText(IDC_STATIC_RESULT, str);

	m_symbol = '*';

	m_strResult.Empty();
}

//除
void CMFCCalcDlg::OnBnClickedBtnChu()
{
	//原来的结果等于
	if (m_strResult.IsEmpty())
	{
		m_num1 = _wtof(m_strText);
	}
	else
	{
		m_num1 = _wtof(m_strResult);
	}


	if (m_symbol == 0)
	{
		m_result = m_num1;
	}
	else
	{
		switch (m_symbol)
		{
		case '+':
			m_result = m_result + m_num1;
			break;
		case '-':
			m_result = m_result - m_num1;
			break;
		case '*':
			m_result = m_result * m_num1;
			break;
		case '/':
		{
			if (m_num1 == 0)
			{
				//设置文本
				SetDlgItemText(IDC_STATIC_RESULT, L"除数不能为0");
				m_strResult.Empty();
				m_strShow.Empty();
				m_strText.Empty();
				m_result = 0;
				m_num1 = 0;
				m_symbol = 0;
				return;
			}
			m_result = m_result / m_num1;//
			break;
		}
			
		}
	}

	//上面显示连续操作文本
	if (m_strResult.IsEmpty())
	{
		m_strShow += m_strText + L"/";
	}
	else
	{
		m_strShow += m_strResult + L"/";
	}

	SetDlgItemText(IDC_STATIC_SHOW, m_strShow);
	//下面显示结果


	CString str;
	str.Format(L"%lf", m_result);
	SetDlgItemText(IDC_STATIC_RESULT, str);

	m_symbol = '/';

	m_strResult.Empty();
}

//等于
void CMFCCalcDlg::OnBnClickedBtnEqual()
{
	//原来的结果等于
	m_num1 = _wtof(m_strResult);

	switch (m_symbol)
	{
	case '+':
		m_result = m_result + m_num1;
		break;
	case '-':
		m_result = m_result - m_num1;
		break;
	case '*':
		m_result = m_result * m_num1;
		break;
	case '/':
		{
			if (m_num1 == 0)
			{
				//设置文本
				SetDlgItemText(IDC_STATIC_RESULT, L"除数不能为0");
				m_strResult.Empty();
				m_strShow.Empty();
				m_strText.Empty();
				m_result = 0;
				m_num1 = 0;
				m_symbol = 0;
				return;
			}
			m_result = m_result / m_num1;//
			break;
		}
	case 0:
		m_result = m_num1;
		break;
	}

	CString str;
	str.Format(L"%lf", m_result);
	SetDlgItemText(IDC_STATIC_RESULT, str);

	m_strText = m_strResult = str;
	m_strResult.Empty();
	m_symbol = 0;
}

//小数点
void CMFCCalcDlg::OnBnClickedBtnDot()
{
	if (m_strResult.Find(L".") != -1)
		return;

	m_strResult += L".";
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
}

//正负
void CMFCCalcDlg::OnBnClickedBtnPn()
{
	if (m_strText.IsEmpty())
	{
		m_num1 = _wtof(m_strResult);
	}
	else
	{
		m_num1 = _wtof(m_strText);
	}
	m_num1 = -m_num1;
	m_strResult.Format(L"%lf", m_num1);	
	SetDlgItemText(IDC_STATIC_RESULT, m_strResult);
	m_symbol = 0;
}
