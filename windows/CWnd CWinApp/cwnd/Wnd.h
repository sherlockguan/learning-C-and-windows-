
// Wnd.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWndApp: 
// �йش����ʵ�֣������ Wnd.cpp
//

//CWinAppӦ�ó��������

class CWndApp : public CWinApp
{
public:
	CWndApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWndApp theApp;