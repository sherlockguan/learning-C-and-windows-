
// MFCCalc.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������



class CMFCCalcApp : public CWinApp
{
public:
	CMFCCalcApp();


public:
	virtual BOOL InitInstance();



	DECLARE_MESSAGE_MAP()
};

extern CMFCCalcApp theApp;