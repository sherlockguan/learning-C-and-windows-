//MFC 自动创建的工程
#pragma once

#ifndef __AFXWIN_H__
	#error "错误"
#endif

#include "resource.h"	



class CGDIApp : public CWinApp
{
public:
	CGDIApp();


public:
	virtual BOOL InitInstance();



	DECLARE_MESSAGE_MAP()
};

extern CGDIApp theApp;
