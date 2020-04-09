#define _CRT_SECURE_NO_WARNINGS  //第一行必须
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>//随机数
//判断按键是否存在 _kbhit()
void outtextxy_int(int x, int y, int num)
{
	char text[20] = " ";
	sprintf(text, "%d", num);
	outtextxy(x, y, text);
}
int main()
{	//随机函数种子
	srand((unsigned int)time(NULL));
	//从上往下执行
	initgraph(600, 400);
	outtextxy(100, 100, "Hello world");//基本文字输出，项目属性改为宽字节,一个字符由两个字节存储，数字不可以
	outtextxy(50, 50, 'A');

	settextcolor(RGB(255, 128, 255));
	settextstyle(35, 0, "Buston Sketch");//第二个高度为0，为自适应
	//数字类转化为字符串， 不要用字符串处理函数
	outtextxy_int(200, 300, 999);
	while (1)
	{
		settextcolor(RGB(rand() % 256, rand() % 256,rand() % 256));
		outtextxy(200, 200, "blink color by random");
		outtextxy(20,20, "press anything to continue");
		if (_kbhit())
		{
			break;
		}
		Sleep(50);//休眠50毫秒防止太快
	}
	//二维数组操作字符串,改变y坐标就可以,自己调试
	//cleardivice() 刷新，闪烁
	char str[8][3] = {"欲","练","神","功","闭","先","自","攻" };
	int x = 500;
	int y = 100;
	int count = 0;
	while (1)
	{
		outtextxy(x, y, str[count]);
		count++;
		y += 50;
		Sleep(100);
	}
	_getch();
	closegraph();
	return 0;
}
