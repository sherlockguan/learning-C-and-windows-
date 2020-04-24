

class CMainDlg :public CDialog //窗口类
{private:
	enum{ IDD = IDD_MAIN_DLG };//相当于一个常量
public:
	HICON m_hIcon;
	CMainDlg();//构造函数初始化类 只是声明 不实现
	BOOL OnInitDialog();//专门重写的虚函数

};