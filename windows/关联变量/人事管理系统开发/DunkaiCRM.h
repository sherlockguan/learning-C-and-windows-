
// DunkaiCRM.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDunkaiCRMApp: 
// �йش����ʵ�֣������ DunkaiCRM.cpp
//

class CDunkaiCRMApp : public CWinApp
{
public:
	CDunkaiCRMApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDunkaiCRMApp theApp;