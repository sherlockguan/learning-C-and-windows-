//一、GDI
//GDI绘图技术 Graphics Device Interface , 类似于Windows API
//图像=》显卡（各种厂商），都会提供一个不同接口 =》统一

//绘图消息：WM_PAINT

//二、HDC
//绘图句柄（黑板的标记，黑板的ID）
//窗口句柄=》


//HANDLE void*     指针
//HWND，HINSTANCE  结构体指针

//都不是采用指针去传递

//三、DC
//Device Context (设备上下文)
//黑板，画、涂



// GDIDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GDI.h"
#include "GDIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDIDlg 对话框



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


// CGDIDlg 消息处理程序

BOOL CGDIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGDIDlg::OnPaint()
{
	//CDC类
	//由MFC，以C++类的形式封装了多有GDI接口，CDC类
	//子类：CPaintDC、CClientDC、CWindowDC

	CPaintDC dc(this);

	////画线
	////dc.MoveTo(20, 20);		//移动画线的起点,如果不指定起点，(0,0)
	//dc.LineTo(100, 100);		//移动画线的终点，新的起点变为了，（100,100）
	//dc.LineTo(400, 200);
	//
	//dc.MoveTo(100, 200);		//新的起点
	//dc.LineTo(200, 300);
	/*for (int i = 0; i < 5;i++)
	{
		dc.MoveTo(10, i * 10 + 10);
		dc.LineTo(200, i * 10 + 10);
	}*/

	///画矩形
	//dc.Rectangle(0, 0, 100, 100);
	//dc.Rectangle(10, 150, 200, 200);

	//画圆/椭圆
	//dc.Ellipse(100, 100, 200, 200);
	//dc.Ellipse(100, 100, 500, 300);

	//画圆角矩形
	//dc.RoundRect(50, 50, 300, 200,50,15);

	//三维矩形
	//dc.Draw3dRect(50, 50, 400, 200, RGB(255, 0, 0), RGB(0, 255, 0));

	//绘制矩形边缘
	//CRect rect = { 50, 50, 400, 200};
	//dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);

	//绘制楔形(封闭的)
	//CRect rect = { 50, 50, 400, 200 };
	//dc.Rectangle(rect);
	//dc.Pie(&rect, CPoint(10, 10), CPoint(300, 250));

	//画点
	/*
	dc.SetPixel(CPoint(10, 10), RGB(255, 0, 0));
	dc.SetPixel(CPoint(300, 250), RGB(255, 0, 0));

	dc.MoveTo(CPoint(10, 10));
	dc.LineTo(rect.CenterPoint());
	dc.LineTo(CPoint(300, 250));
	*/
	
	//画圆弧(非封闭的)
	//CRect rect = { 50, 50, 400, 200 };
	//dc.Arc(&rect, CPoint(10, 10), CPoint(300, 250));

	//画弦
	//CRect rect = { 50, 50, 400, 200 };
	//dc.Chord(&rect, CPoint(10, 10), CPoint(300, 250));

	
	//画线（连接上一个线条起点）
	//dc.MoveTo(200, 200);
	//CRect rect = { 50, 50, 400, 200 };
	//dc.ArcTo(&rect, CPoint(10, 10), CPoint(300, 250));

	//画多边形（封闭区域）
	//CPoint pt[3] = {CPoint(10,10), CPoint(10,100), CPoint(100,100)};
	//dc.Polygon(pt, 3);

	//CPoint pt[10] = {CPoint(102,5), CPoint(124,69),CPoint(197,72), CPoint(139,110),CPoint(161,174),
	//	CPoint(102, 137), CPoint(40, 174), CPoint(63, 111), CPoint(5, 72), CPoint(80,69)
	//};

	//dc.Polygon(pt, 10);

	//多变线条(非封闭的区域)
	//dc.Polyline(pt, 10);

	//dc.PolylineTo(pt, 10);

	//贝尔赛曲线
	//dc.PolyBezier(pt, 10);

	//输出文字
	//CString str = L"Hello 顿开教育";
	//dc.SetBkColor(RGB(255, 255, 0));
	//dc.SetBkMode(TRANSPARENT);
	//dc.SetTextColor(RGB(255, 0, 0));
	//dc.TextOut(10, 10, str);

	//获取客户区大小
	//CRect rect;
	//GetClientRect(&rect);
	//dc.DrawText(str, &rect, DT_BOTTOM | DT_SINGLELINE);

	//绘图图标
	//dc.DrawIcon(CPoint(50, 50), m_hIcon);
	//::DrawIconEx(dc.m_hDC, 10, 10, m_hIcon, 20, 20, 0, NULL, DI_NORMAL);

	//绘制框架
	//CRect rect = { 30, 30, 120, 80 };
	//CBrush brush(RGB(255,0,0));
	//dc.FrameRect(&rect, &brush);

	//翻转颜色
	//CRect rect = { 30, 30, 120, 80 };
	
	//CBrush brush(RGB(255, 0, 0));//红色 RGB(), 0-255
	//dc.SelectObject(&brush);
	//dc.Ellipse(30, 30, 120, 80);
	//dc.InvertRect(&rect);

	//绘制焦点矩形
	//CRect rect = { 30, 30, 120, 80 };
	//dc.DrawFocusRect(&rect);

	//填充 (不包含画笔)
	//CRect rect = { 30, 30, 120, 80 };
	//CBrush brush(RGB(255, 0, 0));
	//dc.FillRect(&rect, &brush);

	//dc.FillSolidRect(&rect, RGB(255, 0, 255));

	
	//GDI对象
	//CGdiObject类，通用GDI对象类
	//HGDIOBJ 通用GDI句柄

	//1、画笔对象
	//CPen

	//CPen p1;//默认的画笔，黑色，1个像素宽度，实线
	//CPen p2(PS_DASHDOT, 1, RGB(255,0,0));
	//dc.SelectObject(&p2);

	//获取画笔的结构
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

	//通过画笔对象获取画笔句柄
	//HPEN hPen = (HPEN)p4.GetSafeHandle();
	//HPEN hPen = (HPEN)p4.m_hObject;

	//通过画笔句柄获取画笔对象
	//Win32创建方式
	//HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 192, 255));
	//CPen* pPen = CPen::FromHandle(hPen);
	//CPen* pOldPen  = dc.SelectObject(pPen);//旧的笔，默认画笔
	//dc.Rectangle(20, 20, 200, 100);

	//dc.SelectObject(pOldPen);
	//dc.Rectangle(20, 220, 400, 300);

	///CPen p(PS_SOLID, 3, RGB(255,0,255));
	//dc.SelectObject(&p);

	//2、画刷对象（填充一个封闭矩形）
	//CBrush b1(RGB(255,100,100));
	//dc.SelectObject(&b1);
	//dc.Rectangle(0, 0, 200, 100);

	//CRect rect = { 50, 50, 400, 200 };
	//dc.Arc(&rect, CPoint(10, 10), CPoint(300, 250));//不是一个封闭区域，不能填充

	//CBrush b2(HS_VERTICAL, RGB(255, 0, 0));

	//CBitmap bmp;
	//bmp.LoadBitmap(IDB_BITMAP1);

	//CBrush b3(&bmp);

	//CBrush b4;
	//b4.CreateSolidBrush(RGB(255, 0, 0));

	//dc.SelectObject(&b4);
	//dc.Rectangle(300, 100, 500, 300);

	//获取画刷的结构
	//LOGBRUSH lb;
	//b4.GetLogBrush(&lb);

	//CBrush b5;
	//LOGBRUSH lb = { BS_SOLID ,RGB(255,255,0),0};
	//b5.CreateBrushIndirect(&lb);
	//dc.SelectObject(&b5);
	//dc.Rectangle(300, 100, 500, 300);

	//通过画刷对象获取画刷句柄
	//HBRUSH hBrush =  (HBRUSH)b5.m_hObject;
	//HBRUSH hBrush = (HBRUSH)b5.GetSafeHandle();

	//通过画刷句柄可以获取画刷对象
	//Win32方式
	//HBRUSH hBrush = ::CreateSolidBrush(RGB(255, 0, 0));
	//CBrush *pBrush = CBrush::FromHandle(hBrush);

	//空画笔，空画刷
	//CBrush b1(NULL_BRUSH);
	//dc.SelectObject(&b1);

	//HPEN hNullPen = (HPEN)::GetStockObject(NULL_PEN);
	//HBRUSH hNullBrush = (HBRUSH)::GetStockObject(GRAY_BRUSH);
	//dc.SelectObject(hNullPen);
	//dc.SelectObject(hNullBrush);

	//dc.Rectangle(20, 20, 300, 200);

	//画线、

	//3、位图对象 CBitmap
	//CBitmap bmp;
	//bmp.LoadBitmap(IDB_BITMAP2);

	////获取图片的信息
	////类似LOGPEN, LOGBRUSH
	//BITMAP logBmp;
	//bmp.GetBitmap(&logBmp);

	////创建内存DC
	//CDC memDC;
	//memDC.CreateCompatibleDC(&dc);
	//memDC.SelectObject(&bmp);

	////获取整个客户端的宽度
	//CRect rect;
	//GetClientRect(&rect);
	////原比例贴图
	////dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

	////拉伸贴图(多了两个参数)
	//dc.SetStretchBltMode(HALFTONE);
	//dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, logBmp.bmWidth, logBmp.bmHeight, SRCCOPY);

	////创建位图
	//CBitmap bmp;
	//bmp.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());//默认黑色

	////创建内存DC
	//CDC memDC;
	//memDC.CreateCompatibleDC(&dc);
	//memDC.SelectObject(bmp);
	//memDC.FillSolidRect(&rect, RGB(255,255,255));

	//CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	//memDC.SelectObject(&pen);
	//CBrush brush(RGB(255,255,0));
	//memDC.SelectObject(&brush);
	//memDC.Rectangle(10, 10, 200, 100);

	////有位图句柄得到位图对象
	//HBITMAP hBmp = (HBITMAP)LoadImage(AfxGetInstanceHandle(), L"./res/fengjing.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	//CBitmap* pBmp = CBitmap::FromHandle(hBmp);

	////创建内存DC
	//CDC memDC;
	//memDC.CreateCompatibleDC(&dc);
	//memDC.SelectObject(pBmp);
	//dc.BitBlt(0, 0, 400, 300, &memDC, 0, 0, SRCCOPY);

	//有位图对象得到位图句柄
	//(HBITMAP)bmp.m_hObject;

	////保存图片
	//CImage img;
	//img.Attach(bmp);
	//img.Save(L"1.bmp");
	//img.Detach();


	//4、字体对象
	//dc.SetBkMode(TRANSPARENT);
	////CFont类
	//CFont font1, font2, font3, font4, font5,font6;
	//font1.CreatePointFont(140, L"宋体");
	//dc.SelectObject(&font1);
	//dc.TextOut(10, 20, L"长沙顿开教育科技有限公司");

	//font2.CreatePointFont(160, L"楷体");
	//dc.SelectObject(&font2);
	//dc.TextOut(10, 50, L"长沙顿开教育科技有限公司");

	//font3.CreateFont(16, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, L"楷体");
	//dc.SelectObject(&font3);
	//dc.TextOut(10, 80, L"长沙顿开教育科技有限公司");

	//font4.CreateFont(16, 0, -30,0, FW_NORMAL,FALSE, FALSE, TRUE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, L"楷体");
	//dc.SelectObject(&font4);
	//dc.TextOut(10, 110, L"长沙顿开教育科技有限公司");

	//LOGFONT logFont;
	//font1.GetLogFont(&logFont);
	//logFont.lfUnderline = TRUE;
	//logFont.lfItalic = TRUE;
	//wcscpy(logFont.lfFaceName ,L"楷体");

	//font5.CreateFontIndirect(&logFont);
	//dc.SelectObject(&font5);
	//dc.TextOut(10, 140, L"长沙顿开教育科技有限公司");

	//GetFont();
	//SetFont();

	//font5.CreateFontDire

	//5、区域对象
	CRgn rgn1;
	rgn1.CreateRectRgn(10, 10, 200, 100);
	//CBrush b1(RGB(255, 0, 255));
	//dc.FillRgn(&rgn1, &b1);

	CRgn rgn2;
	rgn2.CreateEllipticRgn(150, 50, 300, 200);
	//CBrush b2(RGB(255, 255, 0));
	//dc.FillRgn(&rgn2, &b2);

	rgn1.CombineRgn(&rgn1, &rgn2, RGN_XOR);//两者都有：RGN_AND , 合起来：RGN_OR
	CBrush b2(RGB(255, 255, 0));
	dc.FillRgn(&rgn1, &b2);

	//设置窗口为不规则窗口
	SetWindowRgn(rgn1, TRUE);


	//CRgn rgn3;
	//rgn3.CreateRectRgn(310, 10, 920, 500);
	//dc.FillRgn(&rgn3, &b2);

	//dc.SelectObject(&rgn3);
	//dc.SelectObject(&b2);
	//dc.Rectangle(0, 20, 450, 400);//在区域范围内是可以操作的，超出区域，就不能操作

	CDialogEx::OnPaint();	
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
