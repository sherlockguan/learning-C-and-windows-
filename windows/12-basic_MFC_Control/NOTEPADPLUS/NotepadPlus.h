
// NotepadPlus.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNotepadPlusApp: 
// �йش����ʵ�֣������ NotepadPlus.cpp
//

class CNotepadPlusApp : public CWinApp
{
public:
	CNotepadPlusApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNotepadPlusApp theApp;