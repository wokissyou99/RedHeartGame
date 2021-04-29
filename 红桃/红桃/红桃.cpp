
//捡完钥匙后要切换背景音乐否则静音



#include <stdlib.h>
#include <stdio.h>
#include<graphics.h>                      //绘图库头文件，绘图语句需要
#include<conio.h>                         //在控制台输入输出文件
#include <math.h>
#include <windows.h>
#include  <time.h>
#include "function.h"
#include "numrain.h"
#include "mmsystem.h"
#include "rain.h"
#pragma comment(lib,"Winmm.lib")


void jiemian();
int introduce();
int excit();

IMAGE background[3];


int introduce()
{
	initgraph(screenheight, screenwidth);
	//printf("《红桃组的大冒险》讲述的是在很久很久以前的一个月高风黑的夜晚，\n美丽的公主被从天而降的恶魔掳走。\n拥有神之血裔的勇士，你，决心一力肩扛起解救公主的艰难任务。\n在一路追踪后来到神秘阴森的魔塔前，这满是恶魔气息的魔塔里不知道潜伏着怎样的奇怪生物、隐藏着怎样的凶险陷阱，\n勇士坚定信念、握紧武器，毫不犹豫的冲进魔塔，开始了这段神秘莫测的冒险之旅。\n");
	loadimage(&background[1],_T("background3.bmp"),600,500,true);
	putimage(0,0,&background[1]);
	settextcolor(WHITE);		// 设置文字颜色为白色
	setbkmode(TRANSPARENT);		// 设置文字背景为透明色
	int counter=0;
	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("黑体"));
	outtextxy(100, 80, _T("美丽的公主被从天而降的恶魔掳走"));
	Sleep(100);
	
	}
    for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("黑体"));
	outtextxy(10, 120, _T("拥有神之血裔的勇士，你，决心一力肩扛起解救公主的艰难任务"));
	Sleep(100);
	
	}

	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("黑体"));
	outtextxy(100, 160, _T("在一路追踪后来到神秘阴森的魔塔前"));
	Sleep(100);
	
	}
	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("黑体"));
	outtextxy(100, 200, _T("这满是恶魔气息的魔塔里不知道潜伏着阱"));
	outtextxy(100, 240, _T("怎样的奇怪生物、隐藏着怎样的凶险陷阱"));
	Sleep(100);
	
	}
	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("黑体"));
	outtextxy(100, 280, _T("勇士坚定信念、握紧武器，毫不犹豫的冲进魔塔"));
	outtextxy(100, 320, _T("开始了这段神秘莫测的冒险之旅!!!"));

	Sleep(100);
	
	}
	getchar();
	system("cls");
	return 1;
}

int excit()
{
	PlaySound(NULL,NULL,SND_FILENAME);
	waterrain();
	return 1;
}

void jiemian()
{
	int i, j;
	int W = 500, H = 500;
	initgraph(screenheight, screenwidth);
	cleardevice();
	loadimage(&background[0],_T("starbackground2.bmp"),600,500,true);
	putimage(0,0,&background[0]);
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			double t1 = j / 150.0 - 2, t2 = -(i / 100.0 - 2.5);
			if (fabs(pow(t1, 2) + pow(t2 - pow(t1*t1, 1 / 3.0), 2) - 1) < 0.1)
				putpixel(j, i, RED);
		}
	}
	settextcolor(WHITE);		// 设置文字颜色为白色
	setbkmode(TRANSPARENT);		// 设置文字背景为透明色

	settextstyle(50, 0, _T("楷书"));
	outtextxy(135, 135, _T("红心组的大冒险"));
	settextstyle(20, 0, _T("黑体"));
	outtextxy(225, 225, _T("1.开始游戏"));
	outtextxy(225, 265, _T("2.游戏说明"));
	outtextxy(225, 305, _T("3.载入游戏"));
	outtextxy(225, 345, _T("4.退出游戏"));
	
	for (i = 0; i < H; i = i + 32)
	{
		IMAGE img;
		loadimage(&img,_T("star.bmp"),imgwidth,imgheight,true);
		putimage(600 - 32, i, &img);
		putimage(0, i, &img);
	}
	 PlaySound (TEXT ("菜单.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
}


int main()
{ 
	numrain();
	jiemian();
    MOUSEMSG m;
	int x, y;
	while (true)
	{  	
		while (true)
		{
			m = GetMouseMsg();				//获取鼠标消息
			if (m.uMsg == WM_LBUTTONDOWN)	//如果左键点击
				break;
		}
		x = m.x;
		y = m.y;
		if (225 < x&&x < 325 && 225 < y&&y < 245)
		{  
			fillrectangle(225, 225, 325, 245);//画填充矩形框
			setfillcolor(RED);
			Sleep(300);
			zhuanchang();
			closegraph();
			f=1;
			play();
			jiemian();
		}
		if (225 < x&&x < 325 && 265 < y&&y < 285)
		{  
			fillrectangle(225, 265, 325, 285);//画填充矩形框
			setfillcolor(RED);
			Sleep(300);
			zhuanchang();
			closegraph();
			introduce();
			jiemian();
		}
		if (225 < x&&x < 325 && 305 < y&&y < 325)
		{
			fillrectangle(225, 305, 325, 325);//画填充矩形框
			setfillcolor(RED);
			Sleep(300);
			zhuanchang();
			closegraph();
			gameload();
			play2();
			jiemian();
		}
		if (225 < x&&x < 325 && 345 < y&&y < 365)
		{
			fillrectangle(225, 345, 325, 365);//画填充矩形框
			setfillcolor(RED);
			Sleep(300);
			closegraph();
			excit();
			break;
		}
	}
    getchar();
	closegraph();
	getchar();
	return 0;
}

