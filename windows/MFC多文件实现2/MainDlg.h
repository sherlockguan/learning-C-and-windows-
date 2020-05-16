
//对话框文件
class CMainDlg :public CDialog //窗口类
{private:
	enum{ IDD = IDD_MAIN_DLG };//相当于一个常量
public:
	HICON m_hIcon;
	HICON m_hIcon1;
	CMainDlg();//构造函数初始化类 只是声明 不实现
	BOOL OnInitDialog();//专门重写的虚函数
	DECLARE_MESSAGE_MAP()
	
	//声明消息映射 宏定义（宏替换） 不用写分号 \：宏定义中表示换行符
//protected: 
//	static const AFX_MSGMAP* PASCAL GetThisMessageMap(); 
//	virtual const AFX_MSGMAP* GetMessageMap() const; 

	//2.开始消息映射 在CPP里面
public:
	afx_msg int OnCreate(LPCREATESTRUCT LpCreateStruct); //wm_create消息的处理函数
	afx_msg void OnClose(); //WM_close 消息处理函数 afx_msg宏可加可不加 空白标记宏
	afx_msg void OnDestroy();
	afx_msg void OnPaint();// WM_PAINT 消息处理函数
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);//不是我写的 类视图下自动添加
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);//抬起消息
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);//双击消息
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//自定义消息 处理函数 手动必须
	LRESULT OnTest(WPARAM wParam,LPARAM lParam);
	virtual void OnOK(); //可不写
	virtual void OnCancel();//可不写
	afx_msg void OnBnClickedButton1();
};