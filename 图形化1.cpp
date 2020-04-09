#include<stdio.h>
#include<graphics.h>
#include<conio.h>
//图形窗口不支持C 语言输入输出 scanf printf，窗口左上角是x=0 y=0
//颜色宏，其他的右击查看定义; 第二种方法 RGB(x,y,z) 配置颜色 0-255
//背景颜色 setbkcolor(RED),刷新显示 cleardevice()

int main()
{
	initgraph(600, 400); // width height
	//RED; //右键打开， ESC推出
	setbkcolor(RGB(255,128,255));
	cleardevice();


	_getch();
	closegraph();

	return 0;
}
