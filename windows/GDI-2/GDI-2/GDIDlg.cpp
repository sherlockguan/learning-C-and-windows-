//һ��GDI
//GDI��ͼ���� Graphics Device Interface , ������Windows API
//ͼ��=���Կ������ֳ��̣��������ṩһ����ͬ�ӿ� =��ͳһ

//��ͼ��Ϣ��WM_PAINT

//����HDC
//��ͼ������ڰ�ı�ǣ��ڰ��ID��
//���ھ��=��


//HANDLE void*     ָ��
//HWND��HINSTANCE  �ṹ��ָ��

//�����ǲ���ָ��ȥ����

//����DC
//Device Context (�豸������)
//�ڰ壬����Ϳ



// GDIDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GDI.h"
#include "GDIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDIDlg �Ի���



CGDIDlg::CGDIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGDIDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGDIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGDIDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CGDIDlg ��Ϣ�������

BOOL CGDIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGDIDlg::OnPaint()
{
	//CDC��
	//��MFC����C++�����ʽ��װ�˶���GDI�ӿڣ�CDC��
	//���ࣺCPaintDC��CClientDC��CWindowDC

	CPaintDC dc(this);

	////����
	////dc.MoveTo(20, 20);		//�ƶ����ߵ����,�����ָ����㣬(0,0)
	//dc.LineTo(100, 100);		//�ƶ����ߵ��յ㣬�µ�����Ϊ�ˣ���100,100��
	//dc.LineTo(400, 200);
	//
	//dc.MoveTo(100, 200);		//�µ����
	//dc.LineTo(200, 300);
	/*for (int i = 0; i < 5;i++)
	{
		dc.MoveTo(10, i * 10 + 10);
		dc.LineTo(200, i * 10 + 10);
	}*/

	///������
	//dc.Rectangle(0, 0, 100, 100);
	//dc.Rectangle(10, 150, 200, 200);

	//��Բ/��Բ
	//dc.Ellipse(100, 100, 200, 200);
	//dc.Ellipse(100, 100, 500, 300);

	//��Բ�Ǿ���
	//dc.RoundRect(50, 50, 300, 200,50,15);

	//��ά����
	//dc.Draw3dRect(50, 50, 400, 200, RGB(255, 0, 0), RGB(0, 255, 0));

	//���ƾ��α�Ե
	//CRect rect = { 50, 50, 400, 200};
	//dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);

	//����Ш��(��յ�)
	//CRect rect = { 50, 50, 400, 200 };
	//dc.Rectangle(rect);
	//dc.Pie(&rect, CPoint(10, 10), CPoint(300, 250));

	//����
	/*
	dc.SetPixel(CPoint(10, 10), RGB(255, 0, 0));
	dc.SetPixel(CPoint(300, 250), RGB(255, 0, 0));

	dc.MoveTo(CPoint(10, 10));
	dc.LineTo(rect.CenterPoint());
	dc.LineTo(CPoint(300, 250));
	*/
	
	//��Բ��(�Ƿ�յ�)
	//CRect rect = { 50, 50, 400, 200 };
	//dc.Arc(&rect, CPoint(10, 10), CPoint(300, 250));

	//����
	//CRect rect = { 50, 50, 400, 200 };
	//dc.Chord(&rect, CPoint(10, 10), CPoint(300, 250));

	
	//���ߣ�������һ��������㣩
	//dc.MoveTo(200, 200);
	//CRect rect = { 50, 50, 400, 200 };
	//dc.ArcTo(&rect, CPoint(10, 10), CPoint(300, 250));

	//������Σ��������
	//CPoint pt[3] = {CPoint(10,10), CPoint(10,100), CPoint(100,100)};
	//dc.Polygon(pt, 3);

	//CPoint pt[10] = {CPoint(102,5), CPoint(124,69),CPoint(197,72), CPoint(139,110),CPoint(161,174),
	//	CPoint(102, 137), CPoint(40, 174), CPoint(63, 111), CPoint(5, 72), CPoint(80,69)
	//};

	//dc.Polygon(pt, 10);

	//�������(�Ƿ�յ�����)
	//dc.Polyline(pt, 10);

	//dc.PolylineTo(pt, 10);

	//����������
	//dc.PolyBezier(pt, 10);

	//�������
	//CString str = L"Hello �ٿ�����";
	//dc.SetBkColor(RGB(255, 255, 0));
	//dc.SetBkMode(TRANSPARENT);
	//dc.SetTextColor(RGB(255, 0, 0));
	//dc.TextOut(10, 10, str);

	//��ȡ�ͻ�����С
	//CRect rect;
	//GetClientRect(&rect);
	//dc.DrawText(str, &rect, DT_BOTTOM | DT_SINGLELINE);

	//��ͼͼ��
	//dc.DrawIcon(CPoint(50, 50), m_hIcon);
	//::DrawIconEx(dc.m_hDC, 10, 10, m_hIcon, 20, 20, 0, NULL, DI_NORMAL);

	//���ƿ��
	//CRect rect = { 30, 30, 120, 80 };
	//CBrush brush(RGB(255,0,0));
	//dc.FrameRect(&rect, &brush);

	//��ת��ɫ
	//CRect rect = { 30, 30, 120, 80 };
	
	//CBrush brush(RGB(255, 0, 0));//��ɫ RGB(), 0-255
	//dc.SelectObject(&brush);
	//dc.Ellipse(30, 30, 120, 80);
	//dc.InvertRect(&rect);

	//���ƽ������
	//CRect rect = { 30, 30, 120, 80 };
	//dc.DrawFocusRect(&rect);

	//��� (����������)
	//CRect rect = { 30, 30, 120, 80 };
	//CBrush brush(RGB(255, 0, 0));
	//dc.FillRect(&rect, &brush);

	//dc.FillSolidRect(&rect, RGB(255, 0, 255));

	
	//GDI����
	//CGdiObject�࣬ͨ��GDI������
	//HGDIOBJ ͨ��GDI���

	//1�����ʶ���
	//CPen

	//CPen p1;//Ĭ�ϵĻ��ʣ���ɫ��1�����ؿ�ȣ�ʵ��
	//CPen p2(PS_DASHDOT, 1, RGB(255,0,0));
	//dc.SelectObject(&p2);

	//��ȡ���ʵĽṹ
	//LOGPEN logPen;
	//p2.GetLogPen(&logPen);

	//CPen p3;
	//p3.CreatePen(PS_SOLID, 10, RGB(255, 255, 0));
	//dc.SelectObject(&p3);
	//dc.Rectangle(20, 20, 200, 100);

	//CPen p4;
	//LOGPEN lp = { PS_SOLID, {5, 0}, RGB(255,0,255) };
	//p4.CreatePenIndirect(&lp);
	//dc.SelectObject(&p4);
	//dc.Rectangle(20, 20, 200, 100);	

	//ͨ�����ʶ����ȡ���ʾ��
	//HPEN hPen = (HPEN)p4.GetSafeHandle();
	//HPEN hPen = (HPEN)p4.m_hObject;

	//ͨ�����ʾ����ȡ���ʶ���
	//Win32������ʽ
	//HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 192, 255));
	//CPen* pPen = CPen::FromHandle(hPen);
	//CPen* pOldPen  = dc.SelectObject(pPen);//�ɵıʣ�Ĭ�ϻ���
	//dc.Rectangle(20, 20, 200, 100);

	//dc.SelectObject(pOldPen);
	//dc.Rectangle(20, 220, 400, 300);

	///CPen p(PS_SOLID, 3, RGB(255,0,255));
	//dc.SelectObject(&p);

	//2����ˢ�������һ����վ��Σ�
	//CBrush b1(RGB(255,100,100));
	//dc.SelectObject(&b1);
	//dc.Rectangle(0, 0, 200, 100);

	//CRect rect = { 50, 50, 400, 200 };
	//dc.Arc(&rect, CPoint(10, 10), CPoint(300, 250));//����һ��������򣬲������

	//CBrush b2(HS_VERTICAL, RGB(255, 0, 0));

	//CBitmap bmp;
	//bmp.LoadBitmap(IDB_BITMAP1);

	//CBrush b3(&bmp);

	//CBrush b4;
	//b4.CreateSolidBrush(RGB(255, 0, 0));

	//dc.SelectObject(&b4);
	//dc.Rectangle(300, 100, 500, 300);

	//��ȡ��ˢ�Ľṹ
	//LOGBRUSH lb;
	//b4.GetLogBrush(&lb);

	//CBrush b5;
	//LOGBRUSH lb = { BS_SOLID ,RGB(255,255,0),0};
	//b5.CreateBrushIndirect(&lb);
	//dc.SelectObject(&b5);
	//dc.Rectangle(300, 100, 500, 300);

	//ͨ����ˢ�����ȡ��ˢ���
	//HBRUSH hBrush =  (HBRUSH)b5.m_hObject;
	//HBRUSH hBrush = (HBRUSH)b5.GetSafeHandle();

	//ͨ����ˢ������Ի�ȡ��ˢ����
	//Win32��ʽ
	//HBRUSH hBrush = ::CreateSolidBrush(RGB(255, 0, 0));
	//CBrush *pBrush = CBrush::FromHandle(hBrush);

	//�ջ��ʣ��ջ�ˢ
	//CBrush b1(NULL_BRUSH);
	//dc.SelectObject(&b1);

	//HPEN hNullPen = (HPEN)::GetStockObject(NULL_PEN);
	//HBRUSH hNullBrush = (HBRUSH)::GetStockObject(GRAY_BRUSH);
	//dc.SelectObject(hNullPen);
	//dc.SelectObject(hNullBrush);

	//dc.Rectangle(20, 20, 300, 200);

	//���ߡ�

	//3��λͼ���� CBitmap
	//CBitmap bmp;
	//bmp.LoadBitmap(IDB_BITMAP2);

	////��ȡͼƬ����Ϣ
	////����LOGPEN, LOGBRUSH
	//BITMAP logBmp;
	//bmp.GetBitmap(&logBmp);

	////�����ڴ�DC
	//CDC memDC;
	//memDC.CreateCompatibleDC(&dc);
	//memDC.SelectObject(&bmp);

	////��ȡ�����ͻ��˵Ŀ��
	//CRect rect;
	//GetClientRect(&rect);
	////ԭ������ͼ
	////dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

	////������ͼ(������������)
	//dc.SetStretchBltMode(HALFTONE);
	//dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, logBmp.bmWidth, logBmp.bmHeight, SRCCOPY);

	////����λͼ
	//CBitmap bmp;
	//bmp.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());//Ĭ�Ϻ�ɫ

	////�����ڴ�DC
	//CDC memDC;
	//memDC.CreateCompatibleDC(&dc);
	//memDC.SelectObject(bmp);
	//memDC.FillSolidRect(&rect, RGB(255,255,255));

	//CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	//memDC.SelectObject(&pen);
	//CBrush brush(RGB(255,255,0));
	//memDC.SelectObject(&brush);
	//memDC.Rectangle(10, 10, 200, 100);

	////��λͼ����õ�λͼ����
	//HBITMAP hBmp = (HBITMAP)LoadImage(AfxGetInstanceHandle(), L"./res/fengjing.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	//CBitmap* pBmp = CBitmap::FromHandle(hBmp);

	////�����ڴ�DC
	//CDC memDC;
	//memDC.CreateCompatibleDC(&dc);
	//memDC.SelectObject(pBmp);
	//dc.BitBlt(0, 0, 400, 300, &memDC, 0, 0, SRCCOPY);

	//��λͼ����õ�λͼ���
	//(HBITMAP)bmp.m_hObject;

	////����ͼƬ
	//CImage img;
	//img.Attach(bmp);
	//img.Save(L"1.bmp");
	//img.Detach();


	//4���������
	//dc.SetBkMode(TRANSPARENT);
	////CFont��
	//CFont font1, font2, font3, font4, font5,font6;
	//font1.CreatePointFont(140, L"����");
	//dc.SelectObject(&font1);
	//dc.TextOut(10, 20, L"��ɳ�ٿ������Ƽ����޹�˾");

	//font2.CreatePointFont(160, L"����");
	//dc.SelectObject(&font2);
	//dc.TextOut(10, 50, L"��ɳ�ٿ������Ƽ����޹�˾");

	//font3.CreateFont(16, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, L"����");
	//dc.SelectObject(&font3);
	//dc.TextOut(10, 80, L"��ɳ�ٿ������Ƽ����޹�˾");

	//font4.CreateFont(16, 0, -30,0, FW_NORMAL,FALSE, FALSE, TRUE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, L"����");
	//dc.SelectObject(&font4);
	//dc.TextOut(10, 110, L"��ɳ�ٿ������Ƽ����޹�˾");

	//LOGFONT logFont;
	//font1.GetLogFont(&logFont);
	//logFont.lfUnderline = TRUE;
	//logFont.lfItalic = TRUE;
	//wcscpy(logFont.lfFaceName ,L"����");

	//font5.CreateFontIndirect(&logFont);
	//dc.SelectObject(&font5);
	//dc.TextOut(10, 140, L"��ɳ�ٿ������Ƽ����޹�˾");

	//GetFont();
	//SetFont();

	//font5.CreateFontDire

	//5���������
	CRgn rgn1;
	rgn1.CreateRectRgn(10, 10, 200, 100);
	//CBrush b1(RGB(255, 0, 255));
	//dc.FillRgn(&rgn1, &b1);

	CRgn rgn2;
	rgn2.CreateEllipticRgn(150, 50, 300, 200);
	//CBrush b2(RGB(255, 255, 0));
	//dc.FillRgn(&rgn2, &b2);

	rgn1.CombineRgn(&rgn1, &rgn2, RGN_XOR);//���߶��У�RGN_AND , ��������RGN_OR
	CBrush b2(RGB(255, 255, 0));
	dc.FillRgn(&rgn1, &b2);

	//���ô���Ϊ�����򴰿�
	SetWindowRgn(rgn1, TRUE);


	//CRgn rgn3;
	//rgn3.CreateRectRgn(310, 10, 920, 500);
	//dc.FillRgn(&rgn3, &b2);

	//dc.SelectObject(&rgn3);
	//dc.SelectObject(&b2);
	//dc.Rectangle(0, 20, 450, 400);//������Χ���ǿ��Բ����ģ��������򣬾Ͳ��ܲ���

	CDialogEx::OnPaint();	
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGDIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



LRESULT CGDIDlg::OnNcHitTest(CPoint point)
{
	LRESULT result = CDialogEx::OnNcHitTest(point);

	if (result == HTCLIENT)
		result =  HTCAPTION;

	return result;
}
