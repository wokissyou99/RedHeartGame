#include <stdio.h>
#include <windows.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 500
#define DEF_RAIN_NUM 50//�������
#pragma comment(lib, "Winmm.lib")            //For MCI(Media Control Interface��ý����ƽӿ�)

//�����꿪ʼ��λ��
int g_nRainPos[DEF_RAIN_NUM] = { 0 };
IMAGE starground;

void load()
{
	loadimage(&starground,_T("starbackground.bmp"),600,500,true);
	PlaySound (_T("backgroundmusic.wav"),NULL,SND_FILENAME | SND_ASYNC|SND_LOOP);
	
}

//��������ַ���
char g_strRain[DEF_RAIN_NUM][10] = { 0 };

//�������һ����ĸ
char CreateRandomNum() {
	char nRandomNum = 0;

	while (1) {
		nRandomNum = rand() % 123;   //�������0~122��һ���ַ�

		if ((nRandomNum >= 65 && nRandomNum <= 90) || nRandomNum >= 97) {
			return nRandomNum;
		}
	}
}

//�������������Ŀ�ʼλ��
void InitPos() {
	int i;
	for (i = 0; i < DEF_RAIN_NUM; i++) {
		g_nRainPos[i] = rand() % SCREEN_HEIGHT;
	}
}

//��ʼ��������
void InitNumRain() {
	int i,j;
	for ( i = 0; i < DEF_RAIN_NUM; i++) {
		for ( j = 0; j < 10; j++) {
			g_strRain[i][j] = CreateRandomNum();
		}
	}
}

//��ʾ��
void ShowNumRain() {
	putimage(0,0,&starground);
	int i, j;
	for ( i = 0; i < DEF_RAIN_NUM; i++) {
		//����������ɫ
		settextcolor(RGB(255, 255, 255));  //��ɫ
		setbkmode(TRANSPARENT);		// �������ֱ���Ϊ͸��ɫ
		for ( j = 0; j < 10; j++) {
			outtextxy(i * 15, g_nRainPos[i] - 15 * j, g_strRain[i][j]);
			settextcolor(RGB(0, 255 - 28 * j, 0));
		}
	}

	for (i = 0; i < DEF_RAIN_NUM; i++) {
		g_nRainPos[i] += 15;    //��Ļˢ�º����λ���½�15
	}

	for (i = 0; i < DEF_RAIN_NUM; i++) {
		if (g_nRainPos[i] - 10 * 15 >= SCREEN_HEIGHT) {
			g_nRainPos[i] = 0;
		}
	}
}
int numrain() {
	srand((unsigned)time(NULL));
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	putimage(0,0,&starground);
	InitPos();
	InitNumRain();
	BeginBatchDraw();
	int i=0;
	load();
	int counter=0;
	while (counter<=100) {
		InitNumRain();
		ShowNumRain();
		FlushBatchDraw();
		Sleep(100);   //��ʱ0.1��

		cleardevice();  //�����Ļ
		counter++;
	}

	EndBatchDraw();
	PlaySound(NULL,NULL,SND_FILENAME);
	closegraph();
	return 0;
}