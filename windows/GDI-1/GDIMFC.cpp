//图像=》显卡 接口不同=》统一(技术飞跃）
//GDI graph device interface
//WM_PAINT 绘图消息

//HDC 绘图句柄 结构体指针 DC = Device Context(设备上下文-》黑板）
//HANDLE : void*  通用句柄指针
//HWND HISTANCE 具体结构体指针
//windows API:内核的东西（线程 进程） 窗口 图标 资源。。。至关重要的都不用指针传递 用句柄的原因， windows是不开源的。 =》为了封装，为了安全


// GDIDlg.cpp : 实现文件
#include "stdafx.h"
#include "GDI.h"
#include "GDIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDIDlg 



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
END_MESSAGE_MAP()


// CGDIDlg 

BOOL CGDIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 
	SetIcon(m_hIcon, TRUE);			// 
	SetIcon(m_hIcon, FALSE);		// 

	

	return TRUE;  //
}

// 4.位图bmp CBitmap

//  5.字体对象
//  6.区域对象

void CGDIDlg::OnPaint()//类向导自动添加
{
	//CDC类 由MFC，以C++封装所有GDI接口
		//CPaintDC, CClientDC CWindowDC
	CPaintDC dc(this);
	////画线
	//dc.MoveTo(20, 20);	//起点， 不指定=》默认（0，0）客户区
	//dc.LineTo(100, 100);	//终点=》新起点
	//dc.LineTo(400, 200); //新终点
	////画五条线 循环
	//for (int i = 0; i < 5;i++)
	//{
	//	dc.MoveTo(10, i * 10 + 10);
	//	dc.LineTo(200, i * 10 + 10);
	//}

	//dc.Rectangle(0, 0, 100, 100);//起点 终点 填充颜色以后讲
	//dc.Rectangle(10, 150, 200, 200); //正方形

	//矩形内切
	//dc.Ellipse(100, 100, 200, 200);//画圆  起点 终点 两个轴都是100
	//dc.Ellipse(100, 100, 500, 300); //画椭圆 轴 400 200

	//画圆角矩形
	//dc.RoundRect(50, 50, 300, 200,50,55);

	//画3d矩形 立体 两种颜色 边框后面讲 先了解
	//dc.Draw3dRect(50, 50, 400, 200, RGB(255, 0, 0), RGB(0, 255, 0));

	//绘制矩形边缘
	//CRect rect = { 50, 50, 400, 200};
	//dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);//突出
	//EDGE_SUNKEN 下沉风格
	
	//绘制楔形 扇子
	CRect rect = { 50, 50, 400, 200 };
	dc.Rectangle(rect);
	dc.Pie(&rect, CPoint(10, 10), CPoint(300, 250));
	//画点 理解扇形原理
	dc.SetPixel(CPoint(10, 10), RGB(255, 0, 0));
	dc.SetPixel(CPoint(300, 250), RGB(255, 0, 0));

	dc.MoveTo(CPoint(10, 10));
	dc.LineTo(rect.CenterPoint());//中心点
	dc.LineTo(CPoint(300, 250));
	
	
	//Arc 画圆弧 弧线是个不封闭的曲线， 扇形是封闭的， 由外切矩形的中心点
	//CRect rect = { 50, 50, 400, 200 };
	//dc.Arc(&rect, CPoint(10, 10), CPoint(300, 250));

	//
	//CRect rect = { 50, 50, 400, 200 };
	//dc.Chord(&rect, CPoint(10, 10), CPoint(300, 250));

	
	//
	//dc.MoveTo(200, 200);
	//CRect rect = { 50, 50, 400, 200 };
	//dc.ArcTo(&rect, CPoint(10, 10), CPoint(300, 250));

	//画多边形
	//CPoint pt[3] = {CPoint(10,10), CPoint(10,100), CPoint(100,100)};//三角形点数组
	//dc.Polygon(pt, 3);
	//五角星 十个点 用画图工具跟踪点坐标
	//CPoint pt[10] = {CPoint(102,5), CPoint(124,69),CPoint(197,72), CPoint(139,110),CPoint(161,174),
	//	CPoint(102, 137), CPoint(40, 174), CPoint(63, 111), CPoint(5, 72), CPoint(80,69)
	//};

	//dc.Polygon(pt, 10);

	//多边线 不封闭的 上图的起点和终点不相连
	//dc.Polyline(pt, 10);

	//dc.PolylineTo(pt, 10);

	//一种特殊曲线 贝尔赛
	//dc.PolyBezier(pt, 10);

	//输出文字
	//CString str = L"Hello,麻省理工学院";
	//dc.SetBkColor(RGB(255, 255, 0));//背景颜色 黄色
	//dc.SetBkMode(TRANSPARENT);//背景颜色 设成透明 不透明 OPAGUE
	//dc.SetTextColor(RGB(255, 0, 0));//文字颜色的设置
	//dc.TextOut(10, 10, str);

	//获取客户区大小
	//CRect rect;
	//GetClientRect(&rect);   居中方式  
	//dc.DrawText(str, &rect, DT_BOTTOM | DT_SINGLELINE);

	//绘图图标
	//dc.DrawIcon(CPoint(50, 50), m_hIcon);
	//:: WINAPI
	//::DrawIconEx(dc.m_hDC, 10, 10, m_hIcon, 20, 20, 0, NULL, DI_NORMAL);

	//绘制一个框架
	//CRect rect = { 30, 30, 120, 80 };
	//CBrush brush(RGB(255,0,0));//画刷 红色
	//dc.FrameRect(&rect, &brush);

	//
	//CRect rect = { 30, 30, 120, 80 };
	
	//CBrush brush(RGB(255, 0, 0));//红绿蓝三原色
	//dc.SelectObject(&brush);
	//dc.Ellipse(30, 30, 120, 80);
	//dc.InvertRect(&rect);//反转颜色   默认是白色=》黑色 红色=》青色

	//画焦点矩形 就是虚线 没别的
	//CRect rect = { 30, 30, 120, 80 };
	//dc.DrawFocusRect(&rect);

	//填充 不包含画笔 不用边框单独设置
	//CRect rect = { 30, 30, 120, 80 };
	//CBrush brush(RGB(255, 0, 0));
	//dc.FillRect(&rect, &brush);

	//dc.FillSolidRect(&rect, RGB(255, 0, 255));

//第二部分  GDI对象 通用类 父类：CGdiObject
	//通用GDI 句柄 HGDIOBJ 
	//1.画笔对象 CPen 子类
	//2.画刷对象
	//3.位图对象
	//4.字体对象
	//5.区域对象
	

	//CPen p1;//默认 黑色 一个像素宽度 实线
	//CPen p2(PS_DASHDOT, 1, RGB(255,0,0));
	//dc.SelectObject(&p2);//画黑板dc上面

	//获取画笔结构
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

	//通过画笔对象获取画笔句柄 两种方式

	//HPEN hPen = (HPEN)p4.GetSafeHandle();
	//HPEN hPen = (HPEN)p4.m_hObject;

//通过画笔句柄获取画笔对象
	//Win32
	//HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 192, 255));
	//CPen* pPen = CPen::FromHandle(hPen);
	//CPen* pOldPen  = dc.SelectObject(pPen);//旧笔是默认黑色一个像素
	//dc.Rectangle(20, 20, 200, 100);

	//dc.SelectObject(pOldPen);
	//dc.Rectangle(20, 220, 400, 300);

	CPen p(PS_SOLID, 3, RGB(255,0,255));
	dc.SelectObject(&p);

	//画刷的实现，一定是填充封闭的区域
	//CBrush b1(RGB(255,100,100)); //一只彩色笔
	//dc.SelectObject(&b1);  // 黑板上用这支笔
	//dc.Rectangle(0, 0, 200, 100); //画了一个长方形

	//CRect rect = { 50, 50, 400, 200 };
	//dc.Arc(&rect, CPoint(10, 10), CPoint(300, 250));//²»ÊÇÒ»¸ö·â±ÕÇøÓò£¬²»ÄÜÌî³ä

	//CBrush b2(HS_VERTICAL, RGB(255, 0, 0));//不同风格的画刷

	//CBitmap bmp;
	//bmp.LoadBitmap(IDB_BITMAP1);//添加资源

	//CBrush b3(&bmp);

	//CBrush b4;
	//b4.CreateSolidBrush(RGB(255, 0, 0));

	//dc.SelectObject(&b4);
	//dc.Rectangle(300, 100, 500, 300);

	//获取画刷结构
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

	//通过画刷句柄获取画刷指针对象
	//Win32方式
	//HBRUSH hBrush = ::CreateSolidBrush(RGB(255, 0, 0));
	//CBrush *pBrush = CBrush::FromHandle(hBrush);

	//空画刷 NULL_BRUSH
	//CBrush b1(NULL_BRUSH);
	//dc.SelectObject(&b1);

	HPEN hNullPen = (HPEN)::GetStockObject(NULL_PEN);
	HBRUSH hNullBrush = (HBRUSH)::GetStockObject(GRAY_BRUSH);
	dc.SelectObject(hNullPen);
	dc.SelectObject(hNullBrush);

	dc.Rectangle(20, 20, 300, 200);

	
	CDialogEx::OnPaint();	
}


HCURSOR CGDIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

