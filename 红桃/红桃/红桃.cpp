
//����Կ�׺�Ҫ�л��������ַ�����



#include <stdlib.h>
#include <stdio.h>
#include<graphics.h>                      //��ͼ��ͷ�ļ�����ͼ�����Ҫ
#include<conio.h>                         //�ڿ���̨��������ļ�
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
	//printf("��������Ĵ�ð�ա����������ںܾúܾ���ǰ��һ���¸߷�ڵ�ҹ��\n�����Ĺ�������������Ķ�ħ°�ߡ�\nӵ����֮Ѫ�����ʿ���㣬����һ���翸���ȹ����ļ�������\n��һ·׷�ٺ�����������ɭ��ħ��ǰ�������Ƕ�ħ��Ϣ��ħ���ﲻ֪��Ǳ�����������������������������������壬\n��ʿ�ᶨ����ս�������������ԥ�ĳ��ħ������ʼ���������Ī���ð��֮�á�\n");
	loadimage(&background[1],_T("background3.bmp"),600,500,true);
	putimage(0,0,&background[1]);
	settextcolor(WHITE);		// ����������ɫΪ��ɫ
	setbkmode(TRANSPARENT);		// �������ֱ���Ϊ͸��ɫ
	int counter=0;
	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("����"));
	outtextxy(100, 80, _T("�����Ĺ�������������Ķ�ħ°��"));
	Sleep(100);
	
	}
    for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("����"));
	outtextxy(10, 120, _T("ӵ����֮Ѫ�����ʿ���㣬����һ���翸���ȹ����ļ�������"));
	Sleep(100);
	
	}

	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("����"));
	outtextxy(100, 160, _T("��һ·׷�ٺ�����������ɭ��ħ��ǰ"));
	Sleep(100);
	
	}
	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("����"));
	outtextxy(100, 200, _T("�����Ƕ�ħ��Ϣ��ħ���ﲻ֪��Ǳ������"));
	outtextxy(100, 240, _T("��������������������������������"));
	Sleep(100);
	
	}
	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("����"));
	outtextxy(100, 280, _T("��ʿ�ᶨ����ս�������������ԥ�ĳ��ħ��"));
	outtextxy(100, 320, _T("��ʼ���������Ī���ð��֮��!!!"));

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
	settextcolor(WHITE);		// ����������ɫΪ��ɫ
	setbkmode(TRANSPARENT);		// �������ֱ���Ϊ͸��ɫ

	settextstyle(50, 0, _T("����"));
	outtextxy(135, 135, _T("������Ĵ�ð��"));
	settextstyle(20, 0, _T("����"));
	outtextxy(225, 225, _T("1.��ʼ��Ϸ"));
	outtextxy(225, 265, _T("2.��Ϸ˵��"));
	outtextxy(225, 305, _T("3.������Ϸ"));
	outtextxy(225, 345, _T("4.�˳���Ϸ"));
	
	for (i = 0; i < H; i = i + 32)
	{
		IMAGE img;
		loadimage(&img,_T("star.bmp"),imgwidth,imgheight,true);
		putimage(600 - 32, i, &img);
		putimage(0, i, &img);
	}
	 PlaySound (TEXT ("�˵�.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
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
			m = GetMouseMsg();				//��ȡ�����Ϣ
			if (m.uMsg == WM_LBUTTONDOWN)	//���������
				break;
		}
		x = m.x;
		y = m.y;
		if (225 < x&&x < 325 && 225 < y&&y < 245)
		{  
			fillrectangle(225, 225, 325, 245);//�������ο�
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
			fillrectangle(225, 265, 325, 285);//�������ο�
			setfillcolor(RED);
			Sleep(300);
			zhuanchang();
			closegraph();
			introduce();
			jiemian();
		}
		if (225 < x&&x < 325 && 305 < y&&y < 325)
		{
			fillrectangle(225, 305, 325, 325);//�������ο�
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
			fillrectangle(225, 345, 325, 365);//�������ο�
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

