#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include<graphics.h>                      //��ͼ��ͷ�ļ�����ͼ�����Ҫ
#include<conio.h>                         //�ڿ���̨��������ļ�
#include <math.h>
#include <windows.h>
#include "function.h"

#pragma comment(lib,"Winmm.lib")
typedef struct
{
	TCHAR name[30];
	int defence;
	int attack;
	int life;
}Elemtype;
//����ÿ������
typedef struct
{
	Elemtype date;
}People;

typedef struct
{
	People people[Num];
}MGraph;
MGraph G;

//��Կ��
 int red;
//��Կ��
 int blue;
 int yellow;

	TCHAR monster_name[Num];
	int monster_life;
	int monster_attack;
	int monster_defence;
int positionx, positiony;//x�Ǻ������ӦΪ������y���������ӦΪ����
int direction=0;//0-3�����ң��ϣ�����
int Speed=50;
int f=1;//��ʾ�ڵڼ��㣬��ת¥��ʱ�ı���ֵ�������ʼ��¥��Ϊ1����loadmap�����л����f��map��ֵ��map��Ϊ��ǰ��ͼ��
//���еĲ���������map�Ͻ��У���step�ڲ�ʶ����һ����¥��ʱ�����������¥�ݺ�������д�����ں����л�ı�f��ֵȻ��
//map��ֵ��map1�������map1�����Ǵ�ȡ�ĵ����е�map1��Ȼ���ٵ���play������play���ȼ���map���ٻ�ͼ��
int map1[13][23]={
	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1,1,1,1,1},
	{1 ,1 ,1 ,1 ,1 ,1 ,2 ,3 ,3 ,3 ,3 ,8 ,3 ,3 ,3 ,3 ,2 ,1,1,1,1,1,1 },                                         
	{1 ,1 ,1 ,1 ,1 ,1 ,2 ,3 ,3 ,3 ,3 ,5 ,3 ,3 ,3 ,3 ,2 ,1 ,1,1,1,1,1},
	{1 ,1 ,1 ,1 ,1 ,1 ,2 ,3 ,3 ,3 ,3 ,5 ,3 ,3 ,3 ,3 ,2 ,1,1,1,1,1,1 },
	{1 ,1 ,1 ,1 ,1 ,1 ,2 ,3 ,3 ,3 ,3 ,5 ,3 ,3 ,3 ,3 ,2 ,1,1,1,1,1,1},
	{1,1 ,1 ,1 ,1 ,1 ,2 ,3 ,3 ,3 ,3 ,5 ,3 ,3 ,3 ,3 ,2 ,1,1,1,1,1,1},
	{1 ,1 ,1 ,1 ,1 ,1 ,2 ,3 ,3 ,3 ,3 ,5 ,3 ,3 ,3 ,3 ,2 ,1 ,1,1,1,1,1},
	{1 ,1 ,1 ,1 ,1 ,1 ,2 ,2 ,3 ,3 ,3 ,5 ,3 ,3 ,3 ,2 ,2 ,1 ,1,1,1,1,1},
	{1 ,1 ,1 ,1 ,1 ,1 ,2 ,2 ,2 ,2 ,2 ,7 ,2 ,2 ,2 ,2 ,2 ,1 ,1,1,1,1,1},
	{1 ,1 ,1 ,1 ,1 ,1 ,4 ,2 ,4 ,2 ,5 ,0 ,5 ,2 ,4 ,2 ,4 ,1 ,1,1,1,1,1},//0
	{1 ,1 ,1 ,1 ,1 ,1 ,4 ,4 ,4 ,4 ,4 ,6 ,4 ,4 ,4 ,4 ,4 ,1,1,1,1,1,1 },
	{1 ,1 ,1 ,1 ,1 ,1 ,4 ,4 ,4 ,4 ,4 ,5 ,4 ,4 ,4 ,4 ,4 ,1,1,1,1,1,1 },
	{1 ,1 ,1 ,1 ,1 ,1 ,2,2,2,2,2,2,2,2,2,2,2,1 ,1,1,1,1,1}
	};
int map2[13][23]={
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1,1,1,1,1     },
	{1,1,1,1,1,1,8,5,5,5,5,24,5,5,5,5,5,1 ,1,1,1,1,1     },                                    
	{1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,5,1 ,1,1,1,1,1    },
	{1,1,1,1,1,1,21,24,14,7,5,2,21,24,21,2,5,1,1,1,1,1,1  },
	{1,1,1,1,1,1,33,14,27,2,5,2,21,24,21,2,5,1,1,1,1,1,1 },
	{1,1,1,1,1,1,2,7,2,2,5,2,2,2,17,2,5,1 ,1,1,1,1,1    },
	{1,1,1,1,1,1,24,5,24,2,5,7,14,15,17,2,5,1 ,1,1,1,1,1 },
	{1,1,1,1,1,1,27,15,26,2,5,2,2,2,2,2,5,1 ,1,1,1,1,1   },
	{1,1,1,1,1,1,2,12,2,2,5,5,5,5,5,5,5,1 ,1,1,1,1,1     },       
	{1,1,1,1,1,1,5,9,5,2,2,12,2,2,2,7,2,1 ,1,1,1,1,1   },      
	{1,1,1,1,1,1,21,21,26,2,25,6,5,2,27,17,27,1,1,1,1,1,1},
	{1,1,1,1,1,1,21,22,24,2,5,10,5,2,33,25,27,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1  }
}; //9Ϊnpc2�����ܺ���Buff�ӳ�
int map4[13][23]={
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1},                                         
	{1,1,1,1,1,1,2,10,5,5,5,5,5,5,5,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,6,5,5,5,5,5,5,5,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,5,5,5,5,2,5,5,5,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,5,5,5,2,2,2,5,5,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,5,5,2,2,8,2,2,5,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,5,2,2,2,20,2,2,2,5,2,1,1,1,1,1,1},//20
	{1,1,1,1,1,1,2,5,5,2,2,16,2,2,5,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,5,5,5,2,13,2,5,5,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,5,5,5,5,16,5,5,5,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,5,5,5,5,5,5,5,5,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1}};
int map3[13][23]={
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1},                                         
	{1,1,1,1,1,1,2,5,5,5,5, 5 ,5,5,5,5,2,1,1,1,1,1,1},//��������С����
	{1,1,1,1,1,1,2,2,2,2,5,5,5,2,2,2,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,27,19,2,2,5,2,2,18,33,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,27,19,13,5,29,5,7,18,33,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,2,2,2,5,5,5,5,2,2,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,5,19,18,7,5,2,19,5,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,5,5,2,2,5,2,2,5,18,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,7,2,2,2,12,2,2,2,13,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,6,2,2,30,33,30,2,2,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,10,2,5,33,8,33,2,34,5,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1}
};
int map5[13][23]={
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1},                                         
	{1,1,1,1,1,1,2,3,3,3,3,3,3,3,3,3,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,3,3,3,3,3,3,3,3,3,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,3,3,3,3,3,3,3,3,3,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,3,3,2,2,2,2,2,3,3,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,3,3,2,5,31,5,2,3,3,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,3,3,2,5,5,5,2,3,3,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,3,3,2,5,5,5,2,3,3,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,3,3,2,5,6,10,2,3,3,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,3,3,2,2,2,2,2,3,3,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,3,3,3,3,3,3,3,3,3,2,1,1,1,1,1,1},
	{1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1}
};
int map[13][23];
//��draw���õĵ�ͼ���飬���еĲ�������map�Ͻ��У���ת¥��ʱ����Ӧ��mapx�ı�Ϊmap�����еĲ�������ı�map�е�ֵ
IMAGE mapimg[27];
IMAGE propsimg[11];
IMAGE monstersimg[9];
IMAGE npcimg[4];
IMAGE personimg[4];
IMAGE fi;
IMAGE duihua;
IMAGE kuang[2];

// ��������������ȡ��ǰ���� 
int getDirection()
{
	return direction;
}

void drawfight(){
	putimage(IMGWIDTH*6,IMGHEIGHT*4,&fi);
	 TCHAR a[10000];
	 TCHAR b[10000];
	 TCHAR c[10000];
	 TCHAR d[10000];
	 TCHAR e[10000];
	 TCHAR f[10000];
	  settextstyle(20, 0, _T("����"));
	  setcolor(WHITE);
		 setbkmode(TRANSPARENT);		// �������ֱ���Ϊ͸��ɫ
		outtextxy(192, 148, G.people[PERSON].date.name);
		outtextxy(192, 168, _T("����"));
		_stprintf(a, _T("%d"), G.people[PERSON].date.life);
		outtextxy(272, 168, a);
		outtextxy(192, 188, _T("������"));
		_stprintf(b, _T("%d"), G.people[PERSON].date.attack);
		outtextxy(272, 188,b);
		outtextxy(192, 208, _T("������"));
		_stprintf(c, _T("%d"), G.people[PERSON].date.defence);
		outtextxy(272, 208, c);
		outtextxy(416, 148, monster_name);
		outtextxy(416, 168, _T("����"));
		_stprintf(d, _T("%d"), monster_life);
		outtextxy(496, 168,d);
		outtextxy(416, 188, _T("������"));
		_stprintf(e, _T("%d"), monster_attack);
		outtextxy(496, 188,e);
		outtextxy(416, 208, _T("������"));
		_stprintf(f, _T("%d"), monster_defence);
		outtextxy(496, 208,f);
		settextstyle(  80, 0, _T("����"));
		 setbkmode(TRANSPARENT);
		 outtextxy(320, 128, _T("vs"));
		 Sleep(110);
}//ս������
void play()
{
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
	_tcscpy(G.people[PERSON].date.name,_T("��ʿ"));
	G.people[PERSON].date.life=1000;
	G.people[PERSON].date.attack=25;
	G.people[PERSON].date.defence=25;
	loadmap();  
	init();
	
while(1)	
	{
		/* ��ȡ���� */
		int key = getch(); 

		if(key==KEYUP) // ���̡�
			StepUp();
		if(key==KEYDOWN) // ���̡�
			StepDown();
		if(key==KEYLEFT) // ���̡�
			StepLeft();
		if(key==KEYRIGHT) // ���̡�
			StepRight();
		if(key=='q')//�˳���
			break;
		if(key=='o')//�����
			issave();
			
	}
   	PlaySound(NULL,NULL,SND_FILENAME);
	return ;
}
void play2()
{
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
	loadmap();  
	init();
	
while(1)	
	{
		/* ��ȡ���� */
		int key = getch(); 

		if(key==KEYUP) // ���̡�
			StepUp();
		if(key==KEYDOWN) // ���̡�
			StepDown();
		if(key==KEYLEFT) // ���̡�
			StepLeft();
		if(key==KEYRIGHT) // ���̡�
			StepRight();
		if(key=='q')//�˳���
			break;
		if(key=='o')//�����
			issave();
			
	}
   	PlaySound(NULL,NULL,SND_FILENAME);
	return ;
}

void init(){
	initgraph(736,416);
	 loadimage(&mapimg[12],_T("attack.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
    loadimage(&mapimg[0],_T("wall.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[1],_T("redwall.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[2],_T("bluewall.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[4],_T("road.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[8],_T("yellowdoor.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&npcimg[0],_T("npc1.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&personimg[0],_T("right.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
    loadimage(&mapimg[10],_T("downfloor.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[11],_T("star.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[9],_T("upfloor.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[3],_T("redwall.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[5],_T("cadge.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[6],_T("reddoor.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[7],_T("bluedoor.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&propsimg[0],_T("redkey.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&propsimg[1],_T("bluekey.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&propsimg[2],_T("yellowkey.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&propsimg[3],_T("sword1.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&propsimg[4],_T("sword2.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&propsimg[5],_T("sword3.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&propsimg[6],_T("attack.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&propsimg[7],_T("defence.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&propsimg[8],_T("smallhealth.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&propsimg[9],_T("bighealth.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&monstersimg[0],_T("monster1.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&monstersimg[1],_T("monster2.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&monstersimg[2],_T("monster3.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&monstersimg[3],_T("monster4.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&monstersimg[4],_T("monster5.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&monstersimg[5],_T("monster6.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&monstersimg[6],_T("boss.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&monstersimg[7],_T("monster7.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&monstersimg[8],_T("monster8.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&npcimg[1],_T("npc2.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&npcimg[2],_T("npc3.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&npcimg[3],_T("npc4.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&personimg[1],_T("up.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
    loadimage(&personimg[2],_T("left.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&personimg[3],_T("down.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&fi,_T("fight.bmp"),IMAGEWIDTH*11,IMAGEHEIGHT*4,true);
	loadimage(&mapimg[13],_T("loading1.bmp"),736,416,true);
	loadimage(&mapimg[14],_T("loading2.bmp"),736,416,true);
	loadimage(&mapimg[15],_T("loading3.bmp"),736,416,true);
	loadimage(&mapimg[16],_T("loading4.bmp"),736,416,true);
	loadimage(&mapimg[17],_T("sword3.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[18],_T("openyellow1.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[19],_T("openyellow2.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[20],_T("openyellow3.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[21],_T("openred1.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[22],_T("openred2.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[23],_T("openred3.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[24],_T("openblue1.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[25],_T("openblue2.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&mapimg[26],_T("openblue3.bmp"),IMAGEWIDTH,IMAGEHEIGHT,true);
	loadimage(&kuang[0],_T("״̬1.bmp"),128,128,true);
	loadimage(&kuang[1],_T("״̬2.bmp"),96,96,true);
    draw();
	_tcscpy(G.people[MONSTER1].date.name,_T("���ù�"));
	G.people[MONSTER1].date.life=200;
	G.people[MONSTER1].date.attack=30;
	G.people[MONSTER1].date.defence=15;
	_tcscpy(G.people[MONSTER2].date.name,_T("���ñ�"));
	G.people[MONSTER2].date.life=100;
	G.people[MONSTER2].date.attack=60;
	G.people[MONSTER2].date.defence=30;
	_tcscpy(G.people[MONSTER3].date.name,_T("ħ������"));
	G.people[MONSTER3].date.life=1000;
	G.people[MONSTER3].date.attack=300;
	G.people[MONSTER3].date.defence=250;
	_tcscpy(G.people[MONSTER4].date.name,_T("����"));
	G.people[MONSTER4].date.life=150;
	G.people[MONSTER4].date.attack=70;
	G.people[MONSTER4].date.defence=30;

	_tcscpy(G.people[MONSTER5].date.name,_T("ħ������"));
	G.people[MONSTER5].date.life=100;
	G.people[MONSTER5].date.attack=120;
	G.people[MONSTER5].date.defence=65;

	_tcscpy(G.people[MONSTER6].date.name,_T("�߼�����"));
	G.people[MONSTER6].date.life=300;
	G.people[MONSTER6].date.attack=100;
	G.people[MONSTER6].date.defence=50;

	_tcscpy(G.people[MONSTER7].date.name,_T("���öӳ�"));
	G.people[MONSTER7].date.life=900;
	G.people[MONSTER7].date.attack=200;
	G.people[MONSTER7].date.defence=100;

	_tcscpy(G.people[MONSTER8].date.name,_T("����"));
	G.people[MONSTER8].date.life=1000;
	G.people[MONSTER8].date.attack=280;
	G.people[MONSTER8].date.defence=280;

	_tcscpy(G.people[BOSS].date.name,_T("��ħ��"));
	G.people[BOSS].date.life=1500;
	G.people[BOSS].date.attack=400;
	G.people[BOSS].date.defence=150;



	return;
}

void draw()
{  
	  TCHAR a[10000];
	 TCHAR b[10000];
	 TCHAR c[10000];
	 TCHAR d[10000];
	 TCHAR e[10000];
	 TCHAR f[10000];
	 TCHAR g[10000];
	 TCHAR h[10000];
	 TCHAR k[10000];
	
	 int i, j;
	 for(j=0;j<POSHEIGHT;j++)
		for(i=0;i<POSWIDTH;i++)
		{
			if(map[j][i]==LANZHUAN)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[2]);
			}
            else if(map[j][i]==PERSON)
			{  
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&personimg[direction]);
				positionx = i;
				positiony = j;
			}
              else if(map[j][i]==WALL)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[0]);
				
			}
			else if(map[j][i]==STAR)
			{
			putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[11]);
				
			}

            else if(map[j][i]==YANJIANG)
			{
			putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[1]);
				
			}
              else if(map[j][i]==ROAD)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[4]);
				
			}
                                                else if(map[j][i]==YELLOWDOOR)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[8]);
				
			}
                                               else if(map[j][i]==NPC1)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&npcimg[0]);
				
			}
                                                else if(map[j][i]==NPC2)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&npcimg[1]);
				
			}
                                                else if(map[j][i]==UPFLOOR)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[9]);
				
			}
                                                else if(map[j][i]==DOWNFLOOR)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[10]);
				
			}
                                                else if(map[j][i]==NPC3)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&npcimg[2]);
				
			}
												 else if(map[j][i]==NPC4 )
         {
                                                 
              putimage(i*IMGWIDTH,j*IMGHEIGHT,&npcimg[3]);
          }
                                                else if(map[j][i]==REDDOOR)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[6]);
				
			}
												  else if(map[j][i]==SWORD3)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[17]);
				
			}
                                                else if(map[j][i]==BLUEDOOR)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[7]);
				
			}
                                                else if(map[j][i]==MONSTER1)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&monstersimg[0]);
				
			}
                                                else if(map[j][i]==MONSTER2)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&monstersimg[1]);
				
			}
                                                else if(map[j][i]==MONSTER3)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&monstersimg[2]);
				
			}
                                                else if(map[j][i]==MONSTER4 )
            {
                putimage(i*IMGWIDTH,j*IMGHEIGHT,&monstersimg[3]);
                                                 
                }
                                              else if(map[j][i]==MONSTER5 )
               {
                   putimage(i*IMGWIDTH,j*IMGHEIGHT,&monstersimg[4]);
                                                 
               }
                                                else if(map[j][i]==MONSTER6 )
                {
                  putimage(i*IMGWIDTH,j*IMGHEIGHT,&monstersimg[5]);
                                                 
                }
											    else if(map[j][i]==MONSTER7 )
                {
                  putimage(i*IMGWIDTH,j*IMGHEIGHT,&monstersimg[7]);
                                                 
                }  
												else if(map[j][i]==MONSTER8 )
                {
                  putimage(i*IMGWIDTH,j*IMGHEIGHT,&monstersimg[8]);
                                                 
                }
                                         else if(map[j][i]==BOSS )
                {
                  putimage(i*IMGWIDTH,j*IMGHEIGHT,&monstersimg[6]);
                                                 
                }    
                                 
                                                else if(map[j][i]==YELLOWKEY)
                  {
                  putimage(i*IMGWIDTH,j*IMGHEIGHT,&propsimg[2]);
                                                 
                   }
                                                else if(map[j][i]==REDKEY)
                  {
                                                 
                    putimage(i*IMGWIDTH,j*IMGHEIGHT,&propsimg[0]);
                    }
                                                else if(map[j][i]==BLUEKEY)
                    {
                    putimage(i*IMGWIDTH,j*IMGHEIGHT,&propsimg[1]);
                                                 
                       }
                                               
                                             else if(map[j][i]==LIFE )
                    {
                                                 
                     putimage(i*IMGWIDTH,j*IMGHEIGHT,&propsimg[9]);
                    }
                                               else if(map[j][i]==DEFENCE)
                    {
                                                 
						putimage(i*IMGWIDTH,j*IMGHEIGHT,&propsimg[7]);
                  }
                                                
                                                else if(map[j][i]==SWORD1 )
                      {
                                                 
                       putimage(i*IMGWIDTH,j*IMGHEIGHT,&propsimg[3]);
                       }
                                              else if(map[j][i]==CAGE )
                     { 
                       putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[5]);
                        } 
											  else if(map[j][i]==ATTACK )
                     { 
                       putimage(i*IMGWIDTH,j*IMGHEIGHT,&mapimg[12]);
                        }

		}
			 putimage(1*IMGWIDTH,1*IMGHEIGHT,&kuang[0]);
			putimage(1*IMGWIDTH,8*IMGHEIGHT,&kuang[1]);
			putimage(18*IMGWIDTH,2*IMGHEIGHT,&kuang[1]);
	     settextstyle(20, 0, _T("����"));
	     setcolor(BLACK);
		 setbkmode(TRANSPARENT);		// �������ֱ���Ϊ͸��ɫ
		outtextxy(32, 32, G.people[PERSON].date.name);
		outtextxy(32, 64, _T("����"));
		_stprintf(a, _T("%d"), G.people[PERSON].date.life);
		outtextxy(100, 64, a);
		outtextxy(32, 96, _T("������"));
		_stprintf(b, _T("%d"), G.people[PERSON].date.attack);
		outtextxy(100, 96,b);
		outtextxy(32, 128, _T("������"));
		_stprintf(c, _T("%d"), G.people[PERSON].date.defence);
		outtextxy(100, 128, c);
		outtextxy(576, 32, monster_name);
		outtextxy(576, 64, _T("����"));
		_stprintf(d, _T("%d"), monster_life);
		outtextxy(644, 64,d);
		outtextxy(576, 96, _T("������"));
		_stprintf(e, _T("%d"), monster_attack);
		outtextxy(644, 96,e);
		outtextxy(576, 128, _T("������"));
		_stprintf(f, _T("%d"), monster_defence);
		outtextxy(644, 128,f);
		outtextxy(32, 256, _T("��Կ��"));
		_stprintf(g, _T("%d"), yellow);
		outtextxy(100, 256,g);
		outtextxy(32, 288, _T("��Կ��"));
		_stprintf(h, _T("%d"), blue);
		outtextxy(100, 288,h);
		outtextxy(32, 320, _T("��Կ��"));
		_stprintf(k, _T("%d"), red);
		outtextxy(100, 320,k);
		
}

void loadmap(){
int m,n;
	if(f==1)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map[n][m]=map1[n][m];
		}
	} else if(f==2)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map[n][m]=map2[n][m];
		}
	}
	else if(f==3)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map[n][m]=map3[n][m];
		}
	}
	else if(f==4)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map[n][m]=map4[n][m];
		}
	}
	else
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map[n][m]=map5[n][m];
		}
	}
	return;
}//��map��ֵ

int fight1(int N)
{
	int flag;
	flag=999;
	int ad1;//����Թ�������
	int ad2;//�������������
	_tcscpy(monster_name,G.people[N].date.name);
	monster_life=G.people[N].date.life;
	monster_attack=G.people[N].date.attack;
	monster_defence=G.people[N].date.defence;

		if(G.people[PERSON].date.attack>monster_defence){
				ad1=G.people[PERSON].date.attack-monster_defence;
		}
		else{
			ad1=1;
		}
		if(monster_attack>G.people[PERSON].date.defence){
				ad2=monster_attack-G.people[PERSON].date.defence;
		}
		else{
			ad2=1;
		}
		if(G.people[PERSON].date.life/ad2>=monster_life/ad1)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
		return flag;
}

void fight2(int N)
{
	PlaySound (TEXT ("���.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	int ad1;//����Թ�������
	int ad2;//�������������
	_tcscpy(monster_name,G.people[N].date.name);
	monster_life=G.people[N].date.life;
	monster_attack=G.people[N].date.attack;
	monster_defence=G.people[N].date.defence;

		if(G.people[PERSON].date.attack>monster_defence){
				ad1=G.people[PERSON].date.attack-monster_defence;
		}
		else{
			ad1=1;
		}
		if(monster_attack>G.people[PERSON].date.defence){
				ad2=monster_attack-G.people[PERSON].date.defence;
		}
		else{
			ad2=1;
		}
			
	while(G.people[PERSON].date.life>0||monster_life>0){
		monster_life=monster_life-ad1;
		
		if(monster_life<=0)
		{
			monster_life=0;
			drawfight();
			break;
		}
		else{
		drawfight();
		G.people[PERSON].date.life=G.people[PERSON].date.life-ad2;
		drawfight();
		}
	}
	PlaySound(NULL,NULL,SND_FILENAME);//ͣ��
		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
}

void up()//��¥
{ 
		if(f==1)
	{  PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map1[n][m]=map[n][m];
		}

	} 
		else if(f==2)
	{PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map2[n][m]=map[n][m];
		}}
	else if(f==3)
	{PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map3[n][m]=map[n][m];
		}}
		else if(f==4)
	{PlaySound (TEXT ("�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map4[n][m]=map[n][m];
		}}
		f++;
		loadmap();
		init();
}
//��¥
void down(){

		if(f==4)
	{   PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map4[n][m]=map[n][m];
		}

	} 
		else if(f==2)
	{ PlaySound (TEXT ("�ҽ�.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map2[n][m]=map[n][m];
		}}
	else if(f==3)
	{ PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map3[n][m]=map[n][m];
		}
		}
		else if(f==5)
	{PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map5[n][m]=map[n][m];
		}
		}
		f--;
		loadmap();
		init();
}

void zhuanchang(){

initgraph(736, 416);
	loadimage(&mapimg[13],_T("loading1.bmp"),736,416,true);
	loadimage(&mapimg[14],_T("loading2.bmp"),736,416,true);
	loadimage(&mapimg[15],_T("loading3.bmp"),736,416,true);
	loadimage(&mapimg[16],_T("loading4.bmp"),736,416,true);
putimage(0,0,&mapimg[13]);
Sleep(500);
putimage(0,0,&mapimg[14]);
Sleep(500);
putimage(0,0,&mapimg[15]);
Sleep(500);
putimage(0,0,&mapimg[16]);
Sleep(500);
}
/* ������һ�� */
void StepUp()
{
	int i = positionx;
 
	int j = positiony;

	if(j-1<1)//�Ƿ񵽴��ͼ��Ե
	putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[1]);
	else if(map[j-1][i]==5)
{
	map[j-1][i]=6;
	map[j][i]=5;
	direction=1;
	draw();
}
else if(map[j-1][i]==MONSTER1)
{
	if(fight1(MONSTER1)==1){
		fight2(MONSTER1);
		map[j-1][i]=6;
		map[j][i]=5;
		direction=1;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER1)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));

		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        getchar();draw();
	}
}
	else if(map[j-1][i]==MONSTER2)
{
	if(fight1(MONSTER2)==1){
		fight2(MONSTER2);
		map[j-1][i]=6;
		map[j][i]=5;
		direction=1;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER2)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        getchar();draw();
	}
}
	else if(map[j-1][i]==MONSTER3)
{
	if(fight1(MONSTER3)==1){
		fight2(MONSTER3);
		map[j-1][i]=6;
		map[j][i]=5;
		direction=1;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER3)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	
		else if(map[j-1][i]==MONSTER4)
{
	if(fight1(MONSTER4)==1){
		fight2(MONSTER4);
		map[j-1][i]=6;
		map[j][i]=5;
		direction=1;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER4)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
		else if(map[j-1][i]==MONSTER5)
{
	if(fight1(MONSTER5)==1){
		fight2(MONSTER5);
		map[j-1][i]=6;
		map[j][i]=5;
		direction=1;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER5)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if(map[j-1][i]==MONSTER6)
{
	if(fight1(MONSTER6)==1){
		fight2(MONSTER6);
		map[j-1][i]=6;
		map[j][i]=5;
		direction=1;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER6)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
		else if(map[j-1][i]==MONSTER7)
{
	if(fight1(MONSTER7)==1){
		fight2(MONSTER7);
		map[j-1][i]=6;
		map[j][i]=5;
		direction=1;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER7)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if(map[j-1][i]==MONSTER8)
{
	if(fight1(MONSTER8)==1){
		fight2(MONSTER8);
		map[j-1][i]=6;
		map[j][i]=5;
		direction=1;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER8)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
		else if(map[j-1][i]==24)
		{
		direction=1;
		draw();
		map[j-1][i]=6;
		map[j][i]=5;
		yellow++;
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ�˻�Կ�ף�") );
       Sleep(200);draw();

	}
else if(map[j-1][i]==25){
	direction=1;
	draw();
	map[j-1][i]=6;
	map[j][i]=5;
    red++;
		settextstyle(15, 0, _T("����"));
		setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ�˺�Կ�ף�") );
      Sleep(200);draw();
} else if(map[j-1][i]==26){
	direction=1;
	draw();
	map[j-1][i]=6;
	map[j][i]=5;
	blue++;
		settextstyle(15, 0, _T("����"));
		setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ����Կ�ף�") );
       Sleep(200);draw();
} 
 else if(map[j-1][i]==12){
	 if(red!=0){
	direction=1;
		draw();
		settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("ʧȥһ�Ѻ�Կ��") );
	   Sleep(150);
		PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[21]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[22]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[23]);
	Sleep(60);
		 map[j-1][i]=6;
	map[j][i]=5;
	red--;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j-1][i]==13){
	 if(blue!=0){
		 direction=1;
		draw();
		settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("ʧȥһ����Կ��") );
	   Sleep(150);
		PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[24]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[25]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[26]);
	Sleep(60);
	map[j-1][i]=6;
	map[j][i]=5;
	blue--;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j-1][i]==7){
	 if(yellow!=0){
		 direction=1;
		draw();
		settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("ʧȥһ�ѻ�Կ��") );
	   Sleep(150);
	PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[18]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[19]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[20]);
	Sleep(60);
	map[j-1][i]=6;
	map[j][i]=5;
	yellow--; 
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if( map[j-1][i]==8 ){
    up();
   }
   else if( map[j-1][i]==10 ){
    down();
   }
          else if( map[j-1][i]==DEFENCE ){
			  PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_SYNC) ;
			  direction=1;
			  draw();
			  settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��������10") );
	   Sleep(200);
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=10;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
   else if( map[j-1][i]==ATTACK ){
	   direction=1;
	   draw();
	   PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��������10") );
	   Sleep(200);
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=10;
	draw(); 	
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
   else if( map[j-1][i]==SWORD1 ){
	   direction=1;
	   draw();
	   PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��ý�����������30") );
	   Sleep(200);
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=3000;
	draw();	
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
     else if( map[j-1][i]==SWORD3 ){
	   direction=1;
	   draw();
	   PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��ø߼�������������60") );
	   Sleep(200);
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=60;
	draw();	
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
    else if( map[j-1][i]==LIFE ){
	   direction=1;
	   draw();
	   
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("������500") );
	   Sleep(200);
	   PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=5000;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
	else if( map[j-1][i]==0){
    direction=1;
	draw();
    if(f=1){
		npc1();}
	else npc3();
	map[j-1][i]=6;
	map[j][i]=5;
	draw();
   }
	else if( map[j-1][i]==9){
    direction=1;
	draw();
	npc2();
	map[j-1][i]=6;
	map[j][i]=5;
	draw();
   }
	else if(map[j-1][i]==BOSS)
{	boss();
	if(fight1(BOSS)==1){
		fight2(BOSS);
		map[j-1][i]=6;
		map[j][i]=5;
		direction=1;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(BOSS)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if( map[j-1][i]==NPC4){
    direction=1;
	draw();
   npc4();
   }
   else//����������жϣ��ж����߷�����ʲô��������Ӧ�ĵ�����غ�������Ҫnpc������ս������
	//��ս������������Ҫ�رջ���ִ�У�����ս��ʱ�ı�map��init,�������ƣ�����¥�ݺ�����
{
	direction=1;
	draw();
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
	return;
}
/* ������һ�� */
void StepRight()
 {int i = positionx;
  int j = positiony;
if(i+1>16)
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[0]);
else if(map[j][i+1]==5){
	map[j][i+1]=6;
	map[j][i]=5;
	direction=0;
	draw();
}
else if(map[j][i+1]==MONSTER1)
{
	if(fight1(MONSTER1)==1){
		fight2(MONSTER1);
		map[j][i+1]=6;
		map[j][i]=5;
		direction=0;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER1)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if(map[j][i+1]==MONSTER2)
{
	if(fight1(MONSTER2)==1){
		fight2(MONSTER2);
		map[j][i+1]=6;
		map[j][i]=5;
		direction=0;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER2)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if(map[j][i+1]==MONSTER3)
{
	if(fight1(MONSTER3)==1){
		fight2(MONSTER3);
		map[j][i+1]=6;
		map[j][i]=5;
		direction=0;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER3)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if(map[j][i+1]==MONSTER4)
{
	if(fight1(MONSTER4)==1){
		fight2(MONSTER4);
		map[j][i+1]=6;
		map[j][i]=5;
		direction=0;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER4)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if(map[j][i+1]==MONSTER5)
{
	if(fight1(MONSTER5)==1){
		fight2(MONSTER5);
		map[j][i+1]=6;
		map[j][i]=5;
		direction=0;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER5)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if(map[j][i+1]==MONSTER6)
{
	if(fight1(MONSTER6)==1){
		fight2(MONSTER6);
		map[j][i+1]=6;
		map[j][i]=5;
		direction=0;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER6)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
			else if(map[j][i+1]==MONSTER7)
{
	if(fight1(MONSTER7)==1){
		fight2(MONSTER7);
		map[j][i+1]=6;
		map[j][i]=5;
		direction=0;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER7)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if(map[j][i+1]==MONSTER8)
{
	if(fight1(MONSTER8)==1){
		fight2(MONSTER8);
		map[j][i+1]=6;
		map[j][i]=5;
		direction=0;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER8)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if(map[j][i+1]==24){
		direction=0;
		draw();
	map[j][i+1]=6;
	map[j][i]=5;
	yellow++;
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ�˻�Կ�ף�") );
       Sleep(200);draw();
} 
else if(map[j][i+1]==25){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	red++;
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ�˺�Կ�ף�") );
       Sleep(200);draw();
} 
else if(map[j][i+1]==26){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	blue++;
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ����Կ�ף�") );
       Sleep(200);draw();
} 
 else if(map[j][i+1]==12){
	 if(red!=0){
	direction=0;
	draw();
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("ʧȥһ�Ѻ�Կ��") );
	   Sleep(150);
		PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[21]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[22]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[23]);
	Sleep(60);
	map[j][i+1]=6;
	map[j][i]=5;
	red--;
	draw();		
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j][i+1]==13){
	 if(blue!=0){
	direction=0;
	draw();
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("ʧȥһ����Կ��") );
	   Sleep(150);
		PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[24]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[25]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[26]);
	Sleep(60);
	map[j][i+1]=6;
	map[j][i]=5;
	blue--;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j][i+1]==7){
	 if(yellow!=0){
	direction=0;
	draw();
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("ʧȥһ�ѻ�Կ��") );
	   Sleep(150);
		PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[18]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[19]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[20]);
	Sleep(60);
	map[j][i+1]=6;
	map[j][i]=5;
	yellow--;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
    else if( map[j][i+1]==8 ){
    up();
   }
   else if( map[j][i+1]==10 ){
    down();
   }
       else if( map[j][i+1]==DEFENCE ){
		   direction=0;
		   draw();
		   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��������10") );
	   Sleep(200);
		   PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME|SND_SYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=10;
	draw();		
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
   else if( map[j][i+1]==ATTACK ){
	   direction=0;
	   draw();settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��������10") );
	   Sleep(200);
	   PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME|SND_SYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=10;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
   else if( map[j][i+1]==SWORD1 ){
	   direction=0;
	   draw();
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��ý�����������30") );
	   Sleep(200);
	   PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME|SND_SYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=30;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
    else if( map[j][i+1]==SWORD3 ){
	   direction=0;
	   draw();
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��ø߼�������������60") );
	   Sleep(200);
	   PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=60;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
       else if( map[j][i+1]==LIFE ){
	   direction=0;
	   draw();
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("������500") );
	   Sleep(200);
	   PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME|SND_SYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=500;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
   else if( map[j][i+1]==0){
    direction=0;
	draw();
    if(f=3){
		npc3();}
	
	map[j][i+1]=6;
	map[j][i]=5;
	draw();
   }
   	   else if( map[j][i+1]==NPC4){
    direction=0;
	draw();
   npc4();
   }

else//����������жϣ��ж����߷�����ʲô��������Ӧ�ĵ�����غ���
{
	direction=0;
	draw();
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}
/* ������һ�� */
void StepLeft()
 {
	 int i = positionx;
 int j = positiony;
if(i-1<6)
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[2]);
else if(map[j][i-1]==5){
	map[j][i-1]=6;
	map[j][i]=5;
	direction=2;
	draw();
} 
else if(map[j][i-1]==MONSTER1)//����������жϣ��ж����߷�����ʲô��������Ӧ�ĵ�����غ���
{
	if(fight1(MONSTER1)==1){
		fight2(MONSTER1);
		map[j][i-1]=6;
		map[j][i]=5;
		direction=2;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER1)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
else if(map[j][i-1]==MONSTER2)
{
	if(fight1(MONSTER2)==1){
		fight2(MONSTER2);
		map[j][i-1]=6;
		map[j][i]=5;
		direction=2;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER2)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
else if(map[j][i-1]==MONSTER3)
{
	if(fight1(MONSTER3)==1){
		fight2(MONSTER3);
		map[j][i-1]=6;
		map[j][i]=5;
		direction=2;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER3)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
else if(map[j][i-1]==MONSTER4)
{
	if(fight1(MONSTER4)==1){
		fight2(MONSTER4);
		map[j][i-1]=6;
		map[j][i]=5;
		direction=2;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER4)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
else if(map[j][i-1]==MONSTER5)
{
	if(fight1(MONSTER5)==1){
		fight2(MONSTER5);
		map[j][i-1]=6;
		map[j][i]=5;
		direction=2;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER5)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
else if(map[j][i-1]==MONSTER6)
{
	if(fight1(MONSTER6)==1){
		fight2(MONSTER6);
		map[j][i-1]=6;
		map[j][i]=5;
		direction=2;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER6)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
		else if(map[j][i-1]==MONSTER7)
{
	if(fight1(MONSTER7)==1){
		fight2(MONSTER7);
		map[j][i-1]=6;
		map[j][i]=5;
		direction=2;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER7)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if(map[j][i-1]==MONSTER8)
{
	if(fight1(MONSTER8)==1){
		fight2(MONSTER8);
		map[j][i-1]=6;
		map[j][i]=5;
		direction=2;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER8)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
 else if( map[j][i-1]==SWORD3 ){
	   direction=2;
	   draw();
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��ø߼�������������60") );
	   Sleep(200);
	   PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=60;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
else if(map[j][i-1]==24){
	direction=2;
	draw();
	map[j][i-1]=6;
	map[j][i]=5;
	yellow++;
	settextstyle(15, 0, _T("����"));
    setcolor(WHITE);   
	putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ�˻�Կ�ף�") );
       Sleep(200);draw();
} 
else if(map[j][i-1]==25){
	direction=2;
	draw();
	map[j][i-1]=6;
	map[j][i]=5;
	red++;
	settextstyle(15, 0, _T("����"));
    setcolor(WHITE);   
	putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ�˺�Կ�ף�") );
       Sleep(200);draw();
} 
else if(map[j][i-1]==26){
	direction=2;
	draw();
	map[j][i-1]=6;
	map[j][i]=5;
	blue++;
	settextstyle(15, 0, _T("����"));
    setcolor(WHITE);   
	putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ����Կ�ף�") );
       Sleep(200);draw();
} 
 else if(map[j][i-1]==12){
	 if(red!=0){
	direction=2;
	draw();
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("ʧȥһ�Ѻ�Կ��") );
	   Sleep(150);
PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[21]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[22]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[23]);
	Sleep(60);
	map[j][i-1]=6;
	map[j][i]=5;
	red--;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j][i-1]==13){
	 if(blue!=0){
	direction=2;
	draw();
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("ʧȥһ����Կ��") );
	   Sleep(150);
	PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[24]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[25]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[26]);
	Sleep(60);
	map[j][i-1]=6;
	map[j][i]=5;
	blue--;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j][i-1]==7){
	 if(yellow!=0){
	direction=2;
	draw();
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("ʧȥһ�ѻ�Կ��") );
	   Sleep(150);
	PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[18]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[19]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[20]);
	Sleep(60);
	map[j][i-1]=6;
	map[j][i]=5;
	yellow--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
		}
	}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
    else if( map[j][i-1]==8 ){
    up();
   }
   else if( map[j][i-1]==10 ){
    down();
   }
    else if( map[j][i-1]==DEFENCE ){	
		direction=2;
		draw();
		settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��������10") );
	   Sleep(200);
	PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_SYNC) ;//ѭ����������snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=10;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
   else if( map[j][i-1]==ATTACK ){	
	  direction=2;
	  draw();
	  settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��������10") );
	   Sleep(200);
   PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_SYNC) ;//ѭ����������snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=10;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
   else if( map[j][i-1]==SWORD1 ){	direction=2;
   draw();
   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��ý�����������30") );
	   Sleep(200);
   PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;//ѭ����������snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=30;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
       else if( map[j][i-1]==LIFE ){
		   
	   direction=2;
	   draw();
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("������500") );
	   Sleep(200);
		PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_SYNC) ;//ѭ����������snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=500;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
	else if( map[j][i-1]==0){
    direction=2;
	draw();
    if(f=1){
		npc1();}
	else npc3();
	map[j][i-1]=6;
	map[j][i]=5;
	draw();
   }
	else if( map[j][i-1]==NPC4){
    direction=2;
	draw();
   npc4();
   }

else//����������жϣ��ж����߷�����ʲô��������Ӧ�ĵ�����غ���G.people[PERSON].date.attack
{
	direction=2;
	draw();
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}
/* ������һ�� */
void StepDown()
 {
int i = positionx;
 int j = positiony;
if(j+1>12)
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[3]);
else if(map[j+1][i]==5){
	map[j+1][i]=6;
	map[j][i]=5;
	direction=3;
	draw();
} 
else if(map[j+1][i]==MONSTER1)
{
	if(fight1(MONSTER1)==1){
		fight2(MONSTER1);
		map[j+1][i]=6;
		map[j][i]=5;
		direction=3;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER1)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
else if(map[j+1][i]==MONSTER2)
{
	if(fight1(MONSTER2)==1){
		fight2(MONSTER2);
		map[j+1][i]=6;
		map[j][i]=5;
		direction=3;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER2)==0){
		direction=3;
		draw();
		settextstyle(20, 0, _T("����"));
		setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
 else if( map[j+1][i]==SWORD3 ){
	direction=3;
	draw();
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��ø߼�������������60") );
	   Sleep(200);
	PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=60;
	draw();			switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
else if(map[j+1][i]==MONSTER3)
{
	if(fight1(MONSTER3)==1){
		fight2(MONSTER3);
		map[j+1][i]=6;
		map[j][i]=5;
		direction=3;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER3)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
else if(map[j+1][i]==MONSTER4)
{
	if(fight1(MONSTER4)==1){
		fight2(MONSTER4);
		map[j+1][i]=6;
		map[j][i]=5;
		direction=3;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER4)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
else if(map[j+1][i]==MONSTER5)
{
	if(fight1(MONSTER5)==1){
		fight2(MONSTER5);
		map[j+1][i]=6;
		map[j][i]=5;
		direction=3;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER5)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
else if(map[j+1][i]==MONSTER6)
{
	if(fight1(MONSTER6)==1){
		fight2(MONSTER6);
		map[j+1][i]=6;
		map[j][i]=5;
		direction=3;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER6)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
		else if(map[j+1][i]==MONSTER7)
{
	if(fight1(MONSTER7)==1){
		fight2(MONSTER7);
		map[j+1][i]=6;
		map[j][i]=5;
		direction=3;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER7)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
	else if(map[j+1][i]==MONSTER8)
{
	if(fight1(MONSTER8)==1){
		fight2(MONSTER8);
		map[j+1][i]=6;
		map[j][i]=5;
		direction=3;
		draw();
		settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER8)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("�޷�ս��"));		settextstyle(15, 0, _T("����"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
        outtextxy(218, 200, _T("��Ŀǰ���޷�����ս��") );
        Sleep(180);draw();
	}
}
else if(map[j+1][i]==24){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	yellow++;
	settextstyle(15, 0, _T("����"));
    setcolor(WHITE);   
	putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ�˻�Կ�ף�") );
       Sleep(200);draw();
} 
else if(map[j+1][i]==25){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	red++;
	settextstyle(15, 0, _T("����"));
       setcolor(WHITE);
	   putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ�˺�Կ�ף�") );
       Sleep(200);draw();
} 
else if(map[j+1][i]==26){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	blue++;
	settextstyle(15, 0, _T("����"));
    setcolor(WHITE);   
	putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("���ȡ����Կ�ף�") );
       Sleep(200);draw();
} 
 else if(map[j+1][i]==12){
	 if(red!=0){
	direction=3;
	draw();
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
	 putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
    outtextxy(218, 200, _T("ʧȥһ�Ѻ�Կ��") );
	   Sleep(150);
	PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC);
	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[21]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[22]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[23]);
	Sleep(60);
	    map[j+1][i]=6;
	    map[j][i]=5;
	red--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j+1][i]==13){
	 if(blue!=0){
	direction=3;
	draw();
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("ʧȥһ����Կ��") );
	   Sleep(150);
	PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC);
	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[24]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[25]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[26]);
	Sleep(60);
	map[j+1][i]=6;
	map[j][i]=5;
	blue--;
	draw();	
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j+1][i]==7){
	 if(yellow!=0){
	direction=3;
	draw();
	settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("ʧȥһ�ѻ�Կ��") );
	   Sleep(150);
	PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC);
	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[18]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[19]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[20]);
	Sleep(60);
	map[j+1][i]=6;
	map[j][i]=5;
	yellow--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
    else if( map[j+1][i]==8 ){
    up();
   }
   else if( map[j+1][i]==10 ){
    down();
   }
          else if( map[j+1][i]==DEFENCE ){
			  direction=3;
			  draw();
			  settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��������10") );
	   Sleep(200);
    PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_SYNC) ;//ѭ����������snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=10;
	draw();
		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
   else if( map[j+1][i]==ATTACK ){
	   direction=3;
	   draw();
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��������10") );
	   Sleep(200);
	     PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_SYNC) ;//ѭ����������snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=10;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
   else if( map[j+1][i]==SWORD1 ){
	   direction=3;
	   draw();
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("��ý�����������30") );
	   Sleep(200);
		PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;
      PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_SYNC) ;//ѭ����������snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=30;
	draw();	
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
       else if( map[j+1][i]==LIFE ){
	   direction=3;
	   draw();
	   settextstyle(15, 0, _T("����"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("������500") );
	   Sleep(200);
		PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_SYNC) ;//��������snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=500;
	
	draw();	
	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//ѭ����������snd_loop
	default:break;
	}
   }
	   else if(map[j+1][i]==NPC2)
	   {
	   direction=3;draw();
	   npc2();
	   	map[j+1][i]=6;
	    map[j][i]=5;
	   draw();
	   }
	   else if(map[j+1][i]==0)
	   {
	   direction=3;draw();
	   if(f=3) {npc3();}
	   else;
	   map[j+1][i]=6;
	   map[j][i]=5;
	   draw();
	   }
else//����������жϣ��ж����߷�����ʲô��������Ӧ�ĵ�����غ���
{
	direction=3;
	draw();
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}
 
void npc1(){
loadimage(&duihua,_T("�Ի���.bmp"),352,95,true);
settextstyle(15, 0, _T("����"));
setcolor(WHITE);
setbkmode(TRANSPARENT);// �������ֱ���Ϊ͸��ɫ
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽע������
outtextxy(218, 345, _T("��ʿ:������������") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:�����ˣ�") );
getchar();draw();

settextstyle(15, 0, _T("����"));//��ʿ��ʽע������
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("��ʿ:����������������˭���������") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:������������ӣ�") );
outtextxy(218, 232, _T("�ղ��㱻�����С�ִ���ˡ�") );
getchar();draw();
settextstyle(15, 0, _T("����"));//��ʿ��ʽע������
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("��ʿ:���������������ҵĽ��أ�") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:��Ľ������������ˣ�") );
outtextxy(218, 232, _T("��ֻ���ü�����ȳ�����") );
getchar();draw();

settextstyle(15, 0, _T("����"));//��ʿ��ʽע������
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("��ʿ:��,�����أ��������ȹ����ġ�") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:�����������棬������ȥ�ǲ��е�") );
getchar();draw();

settextstyle(15, 0, _T("����"));//��ʿ��ʽע������
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("��ʿ:�Ҵ�Ӧ�˹���Ҫ�ѹ����ȳ�����") );
outtextxy(218, 377, _T("��ʿ:��������Ӧ����ô���أ�") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:���İɣ��Ұ��ҵ����������") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
outtextxy(218, 200, _T("�������������!") );
getchar();draw();
settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:����ֻ�ܸ�����ô��������") );
getchar();draw();
settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:����������Ȱ���ȥ��һ����") );
getchar();draw();
settextstyle(15, 0, _T("����"));//��ʿ��ʽע������
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("��ʿ:ʲô�ˣ�") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:��Ӧ���ڵڶ��㣬�����Ŷ���") );
getchar();draw();

settextstyle(15, 0, _T("����"));//��ʿ��ʽע������
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("��ʿ:��Ϊʲô���Լ�ȥ��") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:�ҵ���������ӡ��һ���֣�����Ҫ���˰���") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:��������Ǹ��ˣ����а취���ң�") );
getchar();draw();

settextstyle(15, 0, _T("����"));//��ʿ��ʽע������
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("��ʿ:�ðɣ������Կ�") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:�����аѻ�Կ�ף�����Խ�ȥ��") );
getchar();draw();

yellow++;//���Կ��

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
outtextxy(218, 200, _T("���ȡ�˻�Կ�ף�") );
getchar();draw();

settextstyle(15, 0, _T("����"));//��ʿ��ʽע������
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("��ʿ:������ڣ�") );
getchar();draw();
return;
     }//����С����

void npc2(){
loadimage(&duihua,_T("�Ի���.bmp"),352,95,true);
setbkmode(TRANSPARENT);// �������ֱ���Ϊ͸��ɫ

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽע������
outtextxy(218, 345, _T("��ʿ:����ֻ����һ���ˣ������񡣡�������") );
getchar();draw();
settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽע������
outtextxy(218, 345, _T("��ʿ:����ʶС������") );
getchar();draw();
settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("��ʦ:�ȿȡ���������˭��") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽע������
outtextxy(218, 345, _T("��ʿ:С���Ӱ����������㣬��˵����԰���") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("��ʦ:�ã����Ի�������������ȥ�ģ�") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽע������
outtextxy(218, 345, _T("��ʿ:��Ҫȥɱ���Ǹ�ħͷ�ȳ�������") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("��ʦ:��..��֪����Ҫ��˭��") );
getchar();draw();
settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("��ʦ:�㻹�кܳ���·Ҫ��") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽע������
outtextxy(218, 345, _T("��ʿ:����԰�������") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("��ʦ:�ǵ�Ȼ��������ң��Ҹ���������") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽע������
outtextxy(218, 345, _T("��ʿ:����������ʲô��") );
getchar();draw();

Speed=10;//�ٶȼӿ�

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("��ʦ:�����Ŷ�����") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽע������
outtextxy(218, 345, _T("��ʿ:�ۣ��������ӯ") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("��ʦ:�ţ��������ߵĸ����ˣ�ף����ˣ�") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽע������
outtextxy(218, 345, _T("��ʿ:лл��") );
getchar();

map3[3][12]=0;

draw();


return;
}
void npc3(){
loadimage(&duihua,_T("�Ի���.bmp"),352,95,true);
settextstyle(15, 0, _T("����"));
setcolor(WHITE);
setbkmode(TRANSPARENT);// �������ֱ���Ϊ͸��ɫ
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽע������
outtextxy(218, 345, _T("��ʿ:С��������ô������") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:лл���������ĳ�ŵ") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:Ϊ�˱����㣬�һ�Ϊ��ʹ���ҵ�ħ��") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽע������
outtextxy(218, 345, _T("��ʿ:������û�������Ķ������Ǹ�ʵ��̫ʹ��") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:�������Ҳ�������ʩ��ħ����") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:���Ҹ���һЩ������.....") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("�����˺�Կ��*1����Կ��*2����Կ��*1") );
getchar();draw();yellow++;blue++;red++;yellow++;
G.people[PERSON].date.attack+=150;//����������ȡbuff
G.people[PERSON].date.defence+=150;
G.people[PERSON].date.life+=2000;

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//���Ӹ�ʽ
outtextxy(218, 200, _T("����:�����·�����Լ����ˣ����С�ģ�") );
getchar();
draw();
return;

}
void boss(){
	settextstyle(15, 0, _T("����"));
setcolor(WHITE);
setbkmode(TRANSPARENT);// �������ֱ���Ϊ͸��ɫ
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//ħ����ʽע������
outtextxy(218, 200, _T("ħ��:���վ���������") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽ
outtextxy(218, 345, _T("��ʿ:��������ͷ�ˣ���ħ��") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//ħ����ʽע������
outtextxy(218, 200, _T("ħ��:����������������˵ʲôЦ��") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽ
outtextxy(218, 345, _T("��ʿ:��ħ��������ҵĹ���������") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//ħ����ʽע������
outtextxy(218, 200, _T("ħ��:��ƾ�㣿") );
getchar();draw();
}void npc4()
{
	settextstyle(15, 0, _T("����"));
setcolor(WHITE);
setbkmode(TRANSPARENT);// �������ֱ���Ϊ͸��ɫ
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//ħ����ʽע������
outtextxy(218, 200, _T("����:�ۣ���ʿ����������") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽ
outtextxy(218, 345, _T("��ʿ:�����������ҵ�����") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//ħ����ʽע������
outtextxy(218, 200, _T("����:�꣬��С���㣬С�ı�ħ������") );
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//��ʿ��ʽ
outtextxy(218, 345, _T("��ʿ:��ħ���Ѿ����Ҵ���ˣ�") );
outtextxy(218, 377, _T("����һ��ؼҰ�" ));
getchar();draw();

settextstyle(15, 0, _T("����"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//ħ����ʽע������
outtextxy(218, 200, _T("����:���������?̫��������ʿ") );
getchar();
ending();
play2();
}

/*��Ϸ����*/
void ending()
{
	IMAGE ending;
	loadimage(&ending,_T("end.bmp"),600,500,true);
	closegraph();
	initgraph(screenheight, screenwidth);
	putimage(0,0,&ending);
	settextcolor(WHITE);		
	int counter=0;
	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("����"));
	outtextxy(120, 80, _T("�����Ĺ������ڱ����ǵ�Ӣ��������"));
	Sleep(100);
	
	}
    for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("����"));
	outtextxy(100, 120, _T("ӵ����֮Ѫ�����ʿ"));
	outtextxy(100, 160, _T("ʹ��������ָֻ��˺�ƽ"));
	Sleep(100);
	
	}

	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("����"));
	outtextxy(100, 200, _T("���ҹ���ò���ƺ��Ѿ����������ǵ���ʿ"));
	Sleep(100);
	
	}
	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("����"));
	outtextxy(100, 240, _T("��һ���Ĵ�ð���Ѿ�����"));
	outtextxy(100, 280, _T("��һ�����ߵ���ĩ���Լ�������"));
	Sleep(100);
	
	}
	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("����"));
	outtextxy(100, 320, _T("���߼ᶨ����ս�������������ԥ�ĳ������"));
	outtextxy(100, 360, _T("���������Ĺ����ڵȴ��ź��������λ�������??"));
	outtextxy(100, 400, _T("���ǿ�����������������"));

	Sleep(100);
	
	}
	getchar();
	closegraph();
	system("cls");
	return;
}
/*�ļ�����*/
int gamesave()
{
	int m,n;
	if(f==1)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map1[n][m]=map[n][m];
		}
	} 
	else if(f==2)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map2[n][m]=map[n][m];
		}
	}
	else if(f==3)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map3[n][m]=map[n][m];
		}
	}
	else if(f==4)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map4[n][m]=map[n][m];
		}
	}
	else
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map[n][m]=map5[n][m];
		}
	}
	FILE* fp;
	fp = fopen("memory.txt", "w+");
	 if (!fp)
    {
       return 0;
    }
	fprintf(fp,"%d  %d  %d  %d  %d  %d\n",positionx,positiony,f,red,blue,yellow);
	fprintf(fp,"%d  %d  %d\n",G.people[PERSON].date.attack,G.people[PERSON].date.defence,G.people[PERSON].date.life);
    for(n=0;n<POSHEIGHT;n++)
	 {
		for(m=0;m<POSWIDTH;m++)
		{
		  fprintf(fp," %d ",map1[n][m]);
		}
		  fputs("\n",fp);
	 }
	 for(n=0;n<POSHEIGHT;n++)
	{
		for(m=0;m<POSWIDTH;m++)
		{
			fprintf(fp," %d ",map2[n][m]);
		}
			fputs("\n",fp);
	 }
	 for(n=0;n<POSHEIGHT;n++)
	 {
		for(m=0;m<POSWIDTH;m++)
		{
			fprintf(fp," %d ",map3[n][m]);
		}
		 fputs("\n",fp);
	 }
	 for(n=0;n<POSHEIGHT;n++)
	 {
		for(m=0;m<POSWIDTH;m++)
		{
			fprintf(fp," %d ",map4[n][m]);
		}
		 fputs("\n",fp);
	 }
	 for(n=0;n<POSHEIGHT;n++)
	 {
		for(m=0;m<POSWIDTH;m++)
		{
			fprintf(fp," %d ",map5[n][m]);
		}
		 fputs("\n",fp);
	}
	fclose(fp);
	return 1;

}

/*�ļ���ȡ*/
int gameload()
{
	int m,n;
   
	FILE* fp;
	fp = fopen("memory.txt", "r");
	 if (!fp)
    {
       return 0;
        
    }
	rewind(fp);
	fscanf(fp,"%d  %d  %d  %d  %d  %d\n",&positionx,&positiony,&f,&red,&blue,&yellow);
	fscanf(fp,"%d  %d  %d\n",&G.people[PERSON].date.attack,&G.people[PERSON].date.defence,&G.people[PERSON].date.life);
	for(n=0;n<POSHEIGHT;n++)
	 {
		for(m=0;m<POSWIDTH;m++)
		{
		  fscanf(fp,"%d",&map1[n][m]);
		}
		
	 }
	 for(n=0;n<POSHEIGHT;n++)
	{
		for(m=0;m<POSWIDTH;m++)
		{
			fscanf(fp," %d ",&map2[n][m]);
		}
		
	 }
	 for(n=0;n<POSHEIGHT;n++)
	 {
		for(m=0;m<POSWIDTH;m++)
		{
			fscanf(fp," %d ",&map3[n][m]);
		}
		
	 }
	 for(n=0;n<POSHEIGHT;n++)
	 {
		for(m=0;m<POSWIDTH;m++)
		{
			fscanf(fp," %d ",&map4[n][m]);
		}
		
	 }
	 for(n=0;n<POSHEIGHT;n++)
	 {
		for(m=0;m<POSWIDTH;m++)
		{
			fscanf(fp," %d ",&map5[n][m]);
		}
		
	}
	fclose(fp);
	if(f==1)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map[n][m]=map1[n][m];
		}
	} else if(f==2)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map[n][m]=map2[n][m];
		}
	}
	else if(f==3)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map[n][m]=map3[n][m];
		}
	}
	else if(f==4)
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map[n][m]=map4[n][m];
		}
	}
	else
	{
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map[n][m]=map5[n][m];
		}
	}
	loadmap();
	fclose(fp);
	play2();
	return 1;
}
/*�ж��ļ��Ƿ񴢴�ɹ�*/
void issave()
{
	
	loadimage(&duihua,_T("�Ի���.bmp"),352,95,true);
    settextstyle(15, 0, _T("����"));
    setcolor(WHITE);
    setbkmode(TRANSPARENT);// �������ֱ���Ϊ͸��ɫ
    putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
	if(gamesave())
	{
    outtextxy(218, 345, _T("����ɹ�") );
	}
	else
	{
		outtextxy(218, 345, _T("����ʧ��") );
	}

    getchar();draw();


}
