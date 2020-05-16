/*MFC是微软封装Windows API的面向对象的C++类库。
好处 : 可重用性, 代码和数据更加紧密捆绑
	 文档试图体系结构 提高程序员开发效率，可以重用
	 缺点 丑----》qt 界面设计方便
	 轻巧 duilib
	 Easyx 个人开发 low

	 1）第一个MFC应用程序 HelloWorld, 从WinMain过度到MFC
	 三部曲：
	 1．建立CWinApp派生类
	 2．重载InitInstance虚函数
	 3．定义CWinApp派生类全局变量theApp(应用程序对象)
*/
#include <afxwin.h>   //mfc 是windows.h的封装 所以不用调用winmain 不用包含windows.h
#include"resource.h"
//对话框关联类： 每一个类（CMainDlg）关联一个对话框资源(IDD..)
class CMainDlg :public CDialog
{
private:
	HICON m_hIcon; //图标句柄
public:
	enum{ IDD = IDD_MAIN_DLG };
	//CMainDlg() :CDialog(IDD_MAIN_DLG) //派生父类， 父类是CDialog 不用枚举的写法
	CMainDlg():CDialog(IDD)//无参的构造函
	{

	}
	//对话框初始化函数：对话框生成了 但没显示
	virtual BOOL OnInitDialog() //windowsAPI  WM_INIDIALOG 在mfc中调用封装好了
	{
		//设置对话框窗口标题
		//::SetWindowText 表示windowsAPI(需要窗口句柄） 同名函数 在MFC 中的调用
		SetWindowText(L"My name is Guan");
		//修改程序的图标 WM_INIDIALOG
		//加载图标 hInstance
		//MFC 中如何获取实例句柄  多种方式
			//AfxGetInstnceHandle()  HICON hIcon
			//or: AfxGetApp()  ==> CmyApp theApp通过全局对象的指针
		//m_hIcon = ::LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
		//m_hIcon = ::LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURC(IDI_ICON1));
		m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
		SetIcon(m_hIcon, TRUE);//大图标
		SetIcon(m_hIcon, FALSE);//小图标

		//// MFC基本数据类型
		//	//介绍字符串 CString 
		//CString str("THIS IS me");
		//AfxMessageBox(str);
		//CString str2 = "hello world";
		////str2.Empty();//清空的调用
		//int nLength = str2.GetLength;
	
		//if (str2.IsEmpty() == TRUE)
		//{
		//	AfxMessageBox(L"this is empty");
		//}
		//else
		//{
		//	AfxMessageBox(L"NOT empty");
		//}
		////宽字符 wchar_t
		//wchar_t ch = str2.GetAt(0);
		//wchar_t ch = str2.GetAt(2);//visit by index
		//wchar_t ch = str2[2];
		//str2.SetAt(0, L'w');//update by index
		//AfxMessageBox(str2);
		////LPCTSTR 运算符重载 C-> CString
		//CString  str3 = str2 + L"123";
		//if (str2.Compare(L"Hela")>0)// or str2 >"hela"
		//{
		//	AfxMessageBox(L"str2 is BIG");
		//}
		////字符串截取函数 CString::Mid 类似于python list
		//CString str4 = str2.Left(5);
		//CString str5 = str2.Right(5);// look doc MSDN VS6.0
		//AfxMessageBox(str5);
		////makeLower MakeReverse makeUpper Replace remove insert delete
		////L 宽字符
		////格式化 format
		//int year = 2020;
		//int month = 4;
		//int day = 23;
		//CString str6;
		//str6.Format(L"%d Year%dMonth%dDay%s", year, month, day, L"22:00");

		//str2.Delete(2,3);
		//AfxMessageBox(str2);
		//CString str7 = L"  3456";
		//str7 = str7.TrimLeft();//去左边的空格
		////TrimRight  FormatMessage语言转换
		////find 查找位置 
		////reversefind 多用于查找路径下的某文件 单斜杠/变成//
		//CString str8 = L"C:\\Program Files(x86)\\DingDing\\DingtalkLauncher.exe";
		//int pos = str8.ReverseFind('\\');
		//if (pos != -1) //NOT FOUND
		//{
		//	str8 = str8.Mid(pos + 1);
		//}
		////getBuffer 返回C 语言指针
		//wchar_t arr[100];
		////wcscpy(arr, str3);
		//wcscpy(arr, str3.GetBuffer());



		////第二个常用类 CPoint 
		////结构体 POINT 获取鼠标当前位置
		//CPoint pt;
		//GetCursorPos(&pt);
		//CString str;
		//str.Format(L"the pos of my mouse if:%d %d", pt.x, pt.y);
		//AfxMessageBox(str);
		////offset 偏移 下300 右边200
		//pt.Offset(200, 300);
		////三：CSize 类 窗口大小定义
		//CSize size(600, 400);
		////四： CRect 矩形区
		//CRect rect(10, 0, 300, 200);//doc easy
		//int width = rect.Width();//290
		//	//一条线 IsRectEmpty
		//	//IsRectNull 四个点都是零
		//	//ptInRect : true false
		//	//InflatRect:上下左右各扩充10  反之 DeflatRect
		//	//NormalizeRect 
		//CRect rect2(300, 200, 10, 10);
		//rect2.NormalizeRect(); //（10，10，300，200）

		////CTime
		//CTime time = CTime::GetCurrentTime();
		//int year = time.GetYear();
		//int day = time.GetDay();
		//int hour = time.GetHour();
		//CString str9;
		//str9.Format(L"CURRENT TIME%d%d%d", year, day, hour);
		//SetWindowText(str9);
		////上面太麻烦 time.Format->doc %M,..
		//




		return TRUE;


	}


};
class CMyApp :public CWinApp
{
public:

	//看作是入口函数所有代码从这里开始
	//Initinastance:MFC的初始化过程，启动管理 相当于main，用于初始化应用程序，虚函数
	virtual BOOL InitInstance()
	{
		//第一个对话框窗口
		CMainDlg dlg;//无参的构造函数 右键 添加 资源dialog 包含resource.h
		dlg.DoModal();//弹出一个模态对话框 上一节详细讲了 内部封装的dialogbox 
		//MFC 比win32 开发快

		return TRUE;//表示初始化成功 return False: Close app
	}
	int ExitInstance()//负责清理操作 退出程序 释放内存。。 大部分不写，可重写，内部也可默认处理
	{
		return CWinApp::ExitInstance();//调用的父类
	}

};


CMyApp theApp; 

