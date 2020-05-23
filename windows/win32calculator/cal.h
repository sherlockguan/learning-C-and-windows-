#include <Windows.h>
#include "resource.h"
#include <stdio.h>
//结构化编程， 所有头文件都放在这里



wchar_t szResultText[100];		//结果文本 宽字符串
wchar_t szShowText[100];		//显示文本
wchar_t szTemp[100];			//中间变量

float num1;				
float num2;					
float result;				

char symbol;		

HINSTANCE g_hInstance;

//对话框处理函数声明
BOOL CALLBACK MainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//对话框初始化函数声明
void OnInitDialog(HWND hWnd);
//清零按钮函数声明
void OnBtnClear(HWND hWnd);

void OnBack(HWND hWnd);

void OnBtn0(HWND hWnd);

void OnBtn1(HWND hWnd);

void OnBtn2(HWND hWnd);

void OnBtn3(HWND hWnd);

void OnBtn4(HWND hWnd);

void OnBtn5(HWND hWnd);

void OnBtn6(HWND hWnd);

void OnBtn7(HWND hWnd);

void OnBtn8(HWND hWnd);

void OnBtn9(HWND hWnd);

void OnBtnDot(HWND hWnd);

void OnBtnAdd(HWND hWnd);

void OnBtnSub(HWND hWnd);

void OnBtnMul(HWND hWnd);

void OnBtnChu(HWND hWnd);

void OnBtnEqual(HWND hWnd);
//加减乘除做好 字符串连接和运算符判断

//去掉多余的小数位
wchar_t* RemoveDecimal(wchar_t* szResultText);
