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
struct textInfo str[4];
void initTarget(int i)
{	
	str[i].x = rand() % 601 + 100; //随机x的范围 【100，700】
	str[i].y = -50;
	str[i].target = rand() % 26 + 'A';//字符一定要用单引号
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
	for (int i = 0; i < 4; i++)//一次掉四个字母
	{
		initTarget(i);
	}
	
	initgraph(800, 600);
	int score = 0;
	
	while (1)
	{//动画 字母往下掉4
		cleardevice();
		for (int i = 0; i < 4; i++)
		{
			str[i].y += 10;
			outtextxy(str[i].x, str[i].y, str[i].target);
			//边界处理
			if (str[i].y > 600)
				initTarget(i);
		}
		
		outtextxy_xy(710, 100, score);
		
	
		//按键处理 conio.h
		if (_kbhit())
		{
			char userKey = _getch();//用不可见接受键盘操作
			//userkey - target = 'a' -'A'
			for (int i = 0; i < 4; i++)
			{
				if (userKey == str[i].target || userKey == (str[i].target + 'a' - 'A'))
				{
					score += 10;//数字在图形库不能直接打印， 封装函数在上面
					initTarget(i);
//outtextxy_xy(710, 100, score);
				}
			}
			
		}
		Sleep(50);
	}
	closegraph();

	system("pause");
	return 0;
}
