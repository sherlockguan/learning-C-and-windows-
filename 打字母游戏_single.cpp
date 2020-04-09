#define _CRT_SECURE_NO_WARNINGS  //第一行必须
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<conio.h>

//从上往下掉，改变y 就可以
struct textInfo 
{
	int x;
	int y;
	char target;
	
};
struct textInfo str;
void initTarget()
{	
	str.x = rand() % 601 + 100; //随机x的范围 【100，700】
	str.y = -50;
	str.target = rand() % 26 + 'A';//字符一定要用单引号
}
void outtextxy_xy(int x, int y, int num)
{
	char scoreText[20]=" ";
	sprintf(scoreText,"score:%d",num);
	outtextxy(x, y, scoreText);//项目属性-》常规=》字符集=》多字节
}
int main()
{
	srand((unsigned int)time(NULL));
	initTarget();
	initgraph(800, 600);
	int score = 0;
	while (1)
	{//动画 字母往下掉
		cleardevice();
		outtextxy_xy(710, 100, score);
		str.y += 10;
		outtextxy(str.x, str.y, str.target);
		//边界处理
		if (str.y > 600)
			initTarget();
		//按键处理 conio.h
		if (_kbhit())
		{
			char userKey = _getch();//用不可见接受键盘操作
			//userkey - target = 'a' -'A'
			if (userKey == str.target || userKey == (str.target + 'a' - 'A'))
			{
				score += 10;//数字在图形库不能直接打印， 封装函数在上面
				initTarget();
			}
		}
		Sleep(50);
	}
	closegraph();

	system("pause");
	return 0;
}
