#include "Calc.h"

int WINAPI  WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	g_hInstance = hInstance;


	//弹出一个模态对话框 ，添加一个Dialog资源
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN_DLG), NULL, MainProc);


	return 0;
}

//对话框处理函数
BOOL CALLBACK MainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		OnInitDialog(hWnd);
		break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))//WM_COMMAND 的ID
		{
		case IDC_BTN_CLEAR: //清零的按钮
			OnBtnClear(hWnd);
			break;
		case IDC_BTN_BACK://后退一步清除
			OnBack(hWnd);
			break;
		case IDC_BTN_0://0
			OnBtn0(hWnd);
			break;
		case IDC_BTN_1://1
			OnBtn1(hWnd);
			break;
		case IDC_BTN_2://2
			OnBtn2(hWnd);
			break;
		case IDC_BTN_3://3
			OnBtn3(hWnd);
			break;
		case IDC_BTN_4://4
			OnBtn4(hWnd);
			break;
		case IDC_BTN_5://5
			OnBtn5(hWnd);
			break;
		case IDC_BTN_6://6
			OnBtn6(hWnd);
			break;
		case IDC_BTN_7://7
			OnBtn7(hWnd);
			break;
		case IDC_BTN_8://8
			OnBtn8(hWnd);
			break;
		case IDC_BTN_9://9
			OnBtn9(hWnd);
			break;
		case IDC_BTN_DOT://9
			OnBtnDot(hWnd);
			break;
		case IDC_BTN_ADD://加
			OnBtnAdd(hWnd);
			break;
		case IDC_BTN_SUB://减法
			OnBtnSub(hWnd);
			break;
		case IDC_BTN_MUL://乘
			OnBtnMul(hWnd);
			break;
		case IDC_BTN_CHU://除法
			OnBtnChu(hWnd);
			break;
		case IDC_BTN_EQUAL:
			OnBtnEqual(hWnd);
			break;
		}
		break;
	}
	case WM_CLOSE:
		EndDialog(hWnd,IDCANCEL);
		return TRUE;
	}

	return FALSE;//系统默认处理
}
//对话框初始化处理函数
void OnInitDialog(HWND hWnd)
{
	
	HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_ICON1));
	SendMessage(hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
	SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

	//初始化显示文本
	SetDlgItemText(hWnd,IDC_STATIC_RESULT, L"0");
	//字体设置
	HFONT hFont = CreateFont(
		40,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		L"Arial");


	HWND hResultStatic = GetDlgItem(hWnd,IDC_STATIC_RESULT);
	SendMessage(hResultStatic, WM_SETFONT, (WPARAM)hFont, NULL);
}

//清除按钮的函数实现
void OnBtnClear(HWND hWnd)
{  //设置初始化显示文本
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, L"0");
	SetDlgItemText(hWnd, IDC_STATIC_SHOW, L"0");
	
	memset(szShowText, 0, sizeof(szShowText));
	memset(szResultText, 0, sizeof(szResultText));
	num1 = 0;
	num2 = 0;
	result = 0;
	symbol = 0;
}

//处理退格
void OnBack(HWND hWnd)
{
	//首先判断字符是否为空
	if (wcslen(szResultText) == 0)
	{
		//显示初始化文本
		SetDlgItemText(hWnd, IDC_STATIC_RESULT, L"0");
	}
	else if (wcslen(szResultText) == 1)
	{
		szResultText[wcslen(szResultText) - 1] = L'\0';//清最后一位
		
		SetDlgItemText(hWnd, IDC_STATIC_RESULT, L"0");
	}
	else
	{
		szResultText[wcslen(szResultText) - 1] = L'\0';
		
		SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
	}
}


void OnBtnDot(HWND hWnd)
{
	wcscat(szResultText, L".");
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
}

//0的处理函数
void OnBtn0(HWND hWnd)
{
	
	wcscat(szResultText, L"0");
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
}


void OnBtn1(HWND hWnd)
{
	
	wcscat(szResultText, L"1");
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
}


void OnBtn2(HWND hWnd)
{
	
	wcscat(szResultText, L"2");
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
}


void OnBtn3(HWND hWnd)
{
	wcscat(szResultText, L"3");
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
}


void OnBtn4(HWND hWnd)
{
	
	wcscat(szResultText, L"4");

	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
}


void OnBtn5(HWND hWnd)
{
	
	wcscat(szResultText, L"5");

	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
}


void OnBtn6(HWND hWnd)
{
	wcscat(szResultText, L"6");
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
}


void OnBtn7(HWND hWnd)
{

	wcscat(szResultText, L"7");

	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
}


void OnBtn8(HWND hWnd)
{
	
	wcscat(szResultText, L"8");
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
}


void OnBtn9(HWND hWnd)
{
	//字符串连接
	wcscat(szResultText, L"9");
	//设置初始化文本
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szResultText);
}


void OnBtnAdd(HWND hWnd)
{
	
	if (wcslen(szResultText) != 0)
		num2 = _wtof(szResultText);
	else
		num2 = _wtof(szTemp);

	switch (symbol)
	{
	case '+':
		result = result + num2;
		break;
	case '-':
		result = result - num2;
		break;
	case '*':
		result = result * num2;
		break;
	case '/':
		result = result / num2;
		break;
	default:
		result = num2;
		break;
	}

	symbol = '+';

	
	if (wcslen(szResultText) != 0)
	{
		wcscat(szShowText, szResultText);
		wcscat(szShowText, L"+");//字符串连接
	}
	else
	{
		wcscat(szShowText, szTemp);
		wcscat(szShowText, L"+");
	}
	//显示初始化文本
	SetDlgItemText(hWnd, IDC_STATIC_SHOW, szShowText);
	//清除原来的结果
	memset(szResultText, 0, sizeof(szResultText));

	TCHAR szText[100];
	swprintf(szText, L"%f", result);
	RemoveDecimal(szText);
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szText);
}

void OnBtnSub(HWND hWnd)
{
	
	if (wcslen(szResultText) != 0)
		num2 = _wtof(szResultText);
	else
		num2 = _wtof(szTemp);

	switch (symbol)
	{
	case '+':
		result = result + num2;
		break;
	case '-':
		result = result - num2;
		break;
	case '*':
		result = result * num2;
		break;
	case '/':
		result = result / num2;
		break;
	default:
		result = num2;
		break;
	}

	symbol = '-';


	if (wcslen(szResultText) != 0)
	{
		wcscat(szShowText, szResultText);
		wcscat(szShowText, L"-");
	}
	else
	{
		wcscat(szShowText, szTemp);
		wcscat(szShowText, L"-");
	}
	
	SetDlgItemText(hWnd, IDC_STATIC_SHOW, szShowText);

	memset(szResultText, 0, sizeof(szResultText));

	TCHAR szText[100];
	swprintf(szText, L"%f", result);
	RemoveDecimal(szText);
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szText);
}


void OnBtnMul(HWND hWnd)
{
	
	if (wcslen(szResultText) != 0)
		num2 = _wtof(szResultText);
	else
		num2 = _wtof(szTemp);

	switch (symbol)
	{
	case '+':
		result = result + num2;
		break;
	case '-':
		result = result - num2;
		break;
	case '*':
		result = result * num2;
		break;
	case '/':
		result = result / num2;
		break;
	default:
		result = num2;
		break;
	}

	symbol = '*';

	
	if (wcslen(szResultText) != 0)
	{
		wcscat(szShowText, szResultText);
		wcscat(szShowText, L"*");
	}
	else
	{
		wcscat(szShowText, szTemp);
		wcscat(szShowText, L"*");
	}
	
	SetDlgItemText(hWnd, IDC_STATIC_SHOW, szShowText);


	memset(szResultText, 0, sizeof(szResultText));

	TCHAR szText[100];
	swprintf(szText, L"%f", result);
	RemoveDecimal(szText);
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szText);
}

void OnBtnChu(HWND hWnd)
{
	
	if (wcslen(szResultText)!=0)
		num2 = _wtof(szResultText);
	else
		num2 = _wtof(szTemp);

	switch (symbol)
	{
	case '+':
		result = result + num2;
		break;
	case '-':
		result = result - num2;
		break;
	case '*':
		result = result * num2;
		break;
	case '/':
		result = result / num2;
		break;
	default:
		result = num2;
		break;
	}

	symbol = '/';



	if (wcslen(szResultText) != 0)
	{
		wcscat(szShowText, szResultText);
		wcscat(szShowText, L"/");
	}
	else
	{
		wcscat(szShowText, szTemp);
		wcscat(szShowText, L"/");
	}

	SetDlgItemText(hWnd, IDC_STATIC_SHOW, szShowText);


	memset(szResultText, 0, sizeof(szResultText));

	TCHAR szText[100];
	swprintf(szText, L"%f", result);
	RemoveDecimal(szText);
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szText);
}


//等于处理函数
void OnBtnEqual(HWND hWnd)
{
	//清除
	memset(szShowText, 0, sizeof(szShowText));
	//初始化
	SetDlgItemText(hWnd, IDC_STATIC_SHOW, szShowText);

	//获取第一个数字
	num2 = _wtof(szResultText);

	switch (symbol)
	{
	case '+':
		result = result + num2;
		break;
	case '-':
		result = result - num2;
		break;
	case '*':
		result = result * num2;
		break;
	case '/':
		result = result / num2;
		break;
	}	

	TCHAR szText[100];
	swprintf(szText, L"%f", result);
	RemoveDecimal(szText);
	
	SetDlgItemText(hWnd, IDC_STATIC_RESULT, szText);
	//赋值给结果文本
	wcscpy(szResultText, szText);
	
	wcscpy(szTemp, szResultText);
	memset(szResultText, 0, sizeof(szResultText));
	//result = 0;

	
	symbol = 0;
}


wchar_t* RemoveDecimal(wchar_t* szResultText)
{
	//"123.0000000"
	for (int i = wcslen(szResultText) - 1; i >= 0; i--)
	{
		if (szResultText[i] == L'0')
		{
			szResultText[i] = L'\0';

			if (szResultText[i - 1] == L'.')
			{
				szResultText[i-1] = L'\0';
				break;
			}
		}
		else
		{
			break;
		}
	}

	return szResultText;
}
