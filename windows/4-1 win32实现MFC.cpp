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
//注意项目属性一定要改为MFC中的一个
#include <afxwin.h>   //mfc 是windows.h的封装 所以不用调用winmain 不用包含windows.h


class CMyApp :public CWinApp
{
public:
	CMyApp(){}//默认的构造函数 可不写
	~CMyApp(){}//析构函数 可不写
	//看作是入口函数所有代码从这里开始
	//Initinastance:MFC的初始化过程，启动管理 相当于main，用于初始化应用程序，虚函数
	virtual BOOL InitInstance()
	{//messagebox: windows Api
		::MessageBox(NULL, L"this is a MFC Application", L"HINT", MB_OK);
		//如果作用域分辨符（::)前面为空 调用全局函数即windowsAPI
		AfxMessageBox(L"My first MFC");//Afx：application framework微软的一个技术团队
		//Afx 开头的函数都表示MFC的专属全局函数
		return TRUE;//表示初始化成功 return False: Close app
	}
	int ExitInstance()//负责清理操作 退出程序 释放内存。。 大部分不写，可重写，内部也可默认处理
	{
		return CWinApp::ExitInstance();//调用的父类
	}

};


CMyApp theApp; //定义全局对象,MFC应用程序的核心对象， 一个应用程序有且只有一个theapp--自己起的名字

