#include "stdafx.h"
#include "MyButton.h"


CMyButton::CMyButton()
{
}


CMyButton::~CMyButton()
{
}

BEGIN_MESSAGE_MAP(CMyButton, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


void CMyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	this->SetWindowText(L"11111");

	CButton::OnMouseMove(nFlags, point);
}
