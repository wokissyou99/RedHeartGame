#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include<graphics.h>                      //绘图库头文件，绘图语句需要
#include<conio.h>                         //在控制台输入输出文件
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
//定义每个生物
typedef struct
{
	Elemtype date;
}People;

typedef struct
{
	People people[Num];
}MGraph;
MGraph G;

//红钥匙
 int red;
//蓝钥匙
 int blue;
 int yellow;

	TCHAR monster_name[Num];
	int monster_life;
	int monster_attack;
	int monster_defence;
int positionx, positiony;//x是横坐标对应为列数，y是纵坐标对应为行数
int direction=0;//0-3代表右，上，左，下
int Speed=50;
int f=1;//表示在第几层，跳转楼层时改变其值。这里初始化楼层为1，在loadmap函数中会根据f给map赋值，map作为当前地图，
//所有的操作都会在map上进行，在step内部识别到下一步是楼梯时，会调用上下楼梯函数（待写），在函数中会改变f的值然后将
//map赋值给map1（这里的map1必须是存取的档案中的map1）然后再调用play函数。play会先加载map，再画图。
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
}; //9为npc2，击败后获得Buff加成
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
	{1,1,1,1,1,1,2,5,5,5,5, 5 ,5,5,5,5,2,1,1,1,1,1,1},//这里遇见小仙子
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
//被draw调用的地图数组，所有的操作都在map上进行，跳转楼层时将相应的mapx改变为map，所有的操作必须改变map中的值
IMAGE mapimg[27];
IMAGE propsimg[11];
IMAGE monstersimg[9];
IMAGE npcimg[4];
IMAGE personimg[4];
IMAGE fi;
IMAGE duihua;
IMAGE kuang[2];

// 基本动作——获取当前方向 
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
	  settextstyle(20, 0, _T("黑体"));
	  setcolor(WHITE);
		 setbkmode(TRANSPARENT);		// 设置文字背景为透明色
		outtextxy(192, 148, G.people[PERSON].date.name);
		outtextxy(192, 168, _T("生命"));
		_stprintf(a, _T("%d"), G.people[PERSON].date.life);
		outtextxy(272, 168, a);
		outtextxy(192, 188, _T("攻击力"));
		_stprintf(b, _T("%d"), G.people[PERSON].date.attack);
		outtextxy(272, 188,b);
		outtextxy(192, 208, _T("防御力"));
		_stprintf(c, _T("%d"), G.people[PERSON].date.defence);
		outtextxy(272, 208, c);
		outtextxy(416, 148, monster_name);
		outtextxy(416, 168, _T("生命"));
		_stprintf(d, _T("%d"), monster_life);
		outtextxy(496, 168,d);
		outtextxy(416, 188, _T("攻击力"));
		_stprintf(e, _T("%d"), monster_attack);
		outtextxy(496, 188,e);
		outtextxy(416, 208, _T("防御力"));
		_stprintf(f, _T("%d"), monster_defence);
		outtextxy(496, 208,f);
		settextstyle(  80, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);
		 outtextxy(320, 128, _T("vs"));
		 Sleep(110);
}//战斗界面
void play()
{
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
	_tcscpy(G.people[PERSON].date.name,_T("勇士"));
	G.people[PERSON].date.life=1000;
	G.people[PERSON].date.attack=25;
	G.people[PERSON].date.defence=25;
	loadmap();  
	init();
	
while(1)	
	{
		/* 获取按键 */
		int key = getch(); 

		if(key==KEYUP) // 键盘↑
			StepUp();
		if(key==KEYDOWN) // 键盘↓
			StepDown();
		if(key==KEYLEFT) // 键盘←
			StepLeft();
		if(key==KEYRIGHT) // 键盘→
			StepRight();
		if(key=='q')//退出键
			break;
		if(key=='o')//保存键
			issave();
			
	}
   	PlaySound(NULL,NULL,SND_FILENAME);
	return ;
}
void play2()
{
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
	loadmap();  
	init();
	
while(1)	
	{
		/* 获取按键 */
		int key = getch(); 

		if(key==KEYUP) // 键盘↑
			StepUp();
		if(key==KEYDOWN) // 键盘↓
			StepDown();
		if(key==KEYLEFT) // 键盘←
			StepLeft();
		if(key==KEYRIGHT) // 键盘→
			StepRight();
		if(key=='q')//退出键
			break;
		if(key=='o')//保存键
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
	loadimage(&kuang[0],_T("状态1.bmp"),128,128,true);
	loadimage(&kuang[1],_T("状态2.bmp"),96,96,true);
    draw();
	_tcscpy(G.people[MONSTER1].date.name,_T("骷髅怪"));
	G.people[MONSTER1].date.life=200;
	G.people[MONSTER1].date.attack=30;
	G.people[MONSTER1].date.defence=15;
	_tcscpy(G.people[MONSTER2].date.name,_T("骷髅兵"));
	G.people[MONSTER2].date.life=100;
	G.people[MONSTER2].date.attack=60;
	G.people[MONSTER2].date.defence=30;
	_tcscpy(G.people[MONSTER3].date.name,_T("魔王宠物"));
	G.people[MONSTER3].date.life=1000;
	G.people[MONSTER3].date.attack=300;
	G.people[MONSTER3].date.defence=250;
	_tcscpy(G.people[MONSTER4].date.name,_T("卫兵"));
	G.people[MONSTER4].date.life=150;
	G.people[MONSTER4].date.attack=70;
	G.people[MONSTER4].date.defence=30;

	_tcscpy(G.people[MONSTER5].date.name,_T("魔法警卫"));
	G.people[MONSTER5].date.life=100;
	G.people[MONSTER5].date.attack=120;
	G.people[MONSTER5].date.defence=65;

	_tcscpy(G.people[MONSTER6].date.name,_T("高级卫兵"));
	G.people[MONSTER6].date.life=300;
	G.people[MONSTER6].date.attack=100;
	G.people[MONSTER6].date.defence=50;

	_tcscpy(G.people[MONSTER7].date.name,_T("骷髅队长"));
	G.people[MONSTER7].date.life=900;
	G.people[MONSTER7].date.attack=200;
	G.people[MONSTER7].date.defence=100;

	_tcscpy(G.people[MONSTER8].date.name,_T("红龙"));
	G.people[MONSTER8].date.life=1000;
	G.people[MONSTER8].date.attack=280;
	G.people[MONSTER8].date.defence=280;

	_tcscpy(G.people[BOSS].date.name,_T("大魔王"));
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
	     settextstyle(20, 0, _T("黑体"));
	     setcolor(BLACK);
		 setbkmode(TRANSPARENT);		// 设置文字背景为透明色
		outtextxy(32, 32, G.people[PERSON].date.name);
		outtextxy(32, 64, _T("生命"));
		_stprintf(a, _T("%d"), G.people[PERSON].date.life);
		outtextxy(100, 64, a);
		outtextxy(32, 96, _T("攻击力"));
		_stprintf(b, _T("%d"), G.people[PERSON].date.attack);
		outtextxy(100, 96,b);
		outtextxy(32, 128, _T("防御力"));
		_stprintf(c, _T("%d"), G.people[PERSON].date.defence);
		outtextxy(100, 128, c);
		outtextxy(576, 32, monster_name);
		outtextxy(576, 64, _T("生命"));
		_stprintf(d, _T("%d"), monster_life);
		outtextxy(644, 64,d);
		outtextxy(576, 96, _T("攻击力"));
		_stprintf(e, _T("%d"), monster_attack);
		outtextxy(644, 96,e);
		outtextxy(576, 128, _T("防御力"));
		_stprintf(f, _T("%d"), monster_defence);
		outtextxy(644, 128,f);
		outtextxy(32, 256, _T("黄钥匙"));
		_stprintf(g, _T("%d"), yellow);
		outtextxy(100, 256,g);
		outtextxy(32, 288, _T("蓝钥匙"));
		_stprintf(h, _T("%d"), blue);
		outtextxy(100, 288,h);
		outtextxy(32, 320, _T("红钥匙"));
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
}//对map赋值

int fight1(int N)
{
	int flag;
	flag=999;
	int ad1;//人物对怪物的输出
	int ad2;//怪物对人物的输出
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
	PlaySound (TEXT ("打击.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	int ad1;//人物对怪物的输出
	int ad2;//怪物对人物的输出
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
	PlaySound(NULL,NULL,SND_FILENAME);//停播
		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
}

void up()//上楼
{ 
		if(f==1)
	{  PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map1[n][m]=map[n][m];
		}

	} 
		else if(f==2)
	{PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map2[n][m]=map[n][m];
		}}
	else if(f==3)
	{PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map3[n][m]=map[n][m];
		}}
		else if(f==4)
	{PlaySound (TEXT ("第五层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
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
//下楼
void down(){

		if(f==4)
	{   PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map4[n][m]=map[n][m];
		}

	} 
		else if(f==2)
	{ PlaySound (TEXT ("岩浆.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map2[n][m]=map[n][m];
		}}
	else if(f==3)
	{ PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
		int m,n;
	 for(n=0;n<POSHEIGHT;n++)
		for(m=0;m<POSWIDTH;m++)
		{
			map3[n][m]=map[n][m];
		}
		}
		else if(f==5)
	{PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;
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
/* 向上走一步 */
void StepUp()
{
	int i = positionx;
 
	int j = positiony;

	if(j-1<1)//是否到达地图边缘
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER1)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));

		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER2)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER3)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER4)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER5)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER6)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER7)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER8)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了黄钥匙！") );
       Sleep(200);draw();

	}
else if(map[j-1][i]==25){
	direction=1;
	draw();
	map[j-1][i]=6;
	map[j][i]=5;
    red++;
		settextstyle(15, 0, _T("黑体"));
		setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了红钥匙！") );
      Sleep(200);draw();
} else if(map[j-1][i]==26){
	direction=1;
	draw();
	map[j-1][i]=6;
	map[j][i]=5;
	blue++;
		settextstyle(15, 0, _T("黑体"));
		setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了蓝钥匙！") );
       Sleep(200);draw();
} 
 else if(map[j-1][i]==12){
	 if(red!=0){
	direction=1;
		draw();
		settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("失去一把红钥匙") );
	   Sleep(150);
		PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[21]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[22]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[23]);
	Sleep(60);
		 map[j-1][i]=6;
	map[j][i]=5;
	red--;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j-1][i]==13){
	 if(blue!=0){
		 direction=1;
		draw();
		settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("失去一把蓝钥匙") );
	   Sleep(150);
		PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[24]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[25]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[26]);
	Sleep(60);
	map[j-1][i]=6;
	map[j][i]=5;
	blue--;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j-1][i]==7){
	 if(yellow!=0){
		 direction=1;
		draw();
		settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("失去一把黄钥匙") );
	   Sleep(150);
	PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[18]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[19]);
	Sleep(60);	putimage(i*IMGWIDTH,(j-1)*IMGHEIGHT,&mapimg[20]);
	Sleep(60);
	map[j-1][i]=6;
	map[j][i]=5;
	yellow--; 
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
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
			  PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_SYNC) ;
			  direction=1;
			  draw();
			  settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("防御力加10") );
	   Sleep(200);
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=10;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
   else if( map[j-1][i]==ATTACK ){
	   direction=1;
	   draw();
	   PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("攻击力加10") );
	   Sleep(200);
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=10;
	draw(); 	
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
   else if( map[j-1][i]==SWORD1 ){
	   direction=1;
	   draw();
	   PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("获得剑，攻击力加30") );
	   Sleep(200);
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=3000;
	draw();	
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
     else if( map[j-1][i]==SWORD3 ){
	   direction=1;
	   draw();
	   PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("获得高级剑，攻击力加60") );
	   Sleep(200);
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=60;
	draw();	
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
    else if( map[j-1][i]==LIFE ){
	   direction=1;
	   draw();
	   
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("生命加500") );
	   Sleep(200);
	   PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=5000;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(BOSS)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
        Sleep(180);draw();
	}
}
	else if( map[j-1][i]==NPC4){
    direction=1;
	draw();
   npc4();
   }
   else//在这里加入判断，判断所走方向是什么东西，相应的调用相关函数，需要npc函数，战斗函数
	//（战斗函数若是需要关闭画布执行，结束战斗时改变map再init,其他类推，上下楼梯函数）
{
	direction=1;
	draw();
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
	return;
}
/* 向右走一步 */
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER1)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER2)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER3)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER4)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER5)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER6)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER7)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER8)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
        Sleep(180);draw();
	}
}
	else if(map[j][i+1]==24){
		direction=0;
		draw();
	map[j][i+1]=6;
	map[j][i]=5;
	yellow++;
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了黄钥匙！") );
       Sleep(200);draw();
} 
else if(map[j][i+1]==25){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	red++;
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了红钥匙！") );
       Sleep(200);draw();
} 
else if(map[j][i+1]==26){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	blue++;
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了蓝钥匙！") );
       Sleep(200);draw();
} 
 else if(map[j][i+1]==12){
	 if(red!=0){
	direction=0;
	draw();
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("失去一把红钥匙") );
	   Sleep(150);
		PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[21]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[22]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[23]);
	Sleep(60);
	map[j][i+1]=6;
	map[j][i]=5;
	red--;
	draw();		
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j][i+1]==13){
	 if(blue!=0){
	direction=0;
	draw();
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("失去一把蓝钥匙") );
	   Sleep(150);
		PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[24]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[25]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[26]);
	Sleep(60);
	map[j][i+1]=6;
	map[j][i]=5;
	blue--;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j][i+1]==7){
	 if(yellow!=0){
	direction=0;
	draw();
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("失去一把黄钥匙") );
	   Sleep(150);
		PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[18]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[19]);
	Sleep(60);	putimage((i+1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[20]);
	Sleep(60);
	map[j][i+1]=6;
	map[j][i]=5;
	yellow--;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
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
		   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("防御力加10") );
	   Sleep(200);
		   PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME|SND_SYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=10;
	draw();		
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
   else if( map[j][i+1]==ATTACK ){
	   direction=0;
	   draw();settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("攻击力加10") );
	   Sleep(200);
	   PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME|SND_SYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=10;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
   else if( map[j][i+1]==SWORD1 ){
	   direction=0;
	   draw();
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("获得剑，攻击力加30") );
	   Sleep(200);
	   PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME|SND_SYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=30;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
    else if( map[j][i+1]==SWORD3 ){
	   direction=0;
	   draw();
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("获得高级剑，攻击力加60") );
	   Sleep(200);
	   PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=60;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
       else if( map[j][i+1]==LIFE ){
	   direction=0;
	   draw();
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("生命加500") );
	   Sleep(200);
	   PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME|SND_SYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=500;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
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

else//在这里加入判断，判断所走方向是什么东西，相应的调用相关函数
{
	direction=0;
	draw();
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}
/* 向左走一步 */
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
else if(map[j][i-1]==MONSTER1)//在这里加入判断，判断所走方向是什么东西，相应的调用相关函数
{
	if(fight1(MONSTER1)==1){
		fight2(MONSTER1);
		map[j][i-1]=6;
		map[j][i]=5;
		direction=2;
		draw();
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER1)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER2)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER3)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER4)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER5)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER6)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER7)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER8)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
        Sleep(180);draw();
	}
}
 else if( map[j][i-1]==SWORD3 ){
	   direction=2;
	   draw();
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("获得高级剑，攻击力加60") );
	   Sleep(200);
	   PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=60;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
else if(map[j][i-1]==24){
	direction=2;
	draw();
	map[j][i-1]=6;
	map[j][i]=5;
	yellow++;
	settextstyle(15, 0, _T("黑体"));
    setcolor(WHITE);   
	putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了黄钥匙！") );
       Sleep(200);draw();
} 
else if(map[j][i-1]==25){
	direction=2;
	draw();
	map[j][i-1]=6;
	map[j][i]=5;
	red++;
	settextstyle(15, 0, _T("黑体"));
    setcolor(WHITE);   
	putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了红钥匙！") );
       Sleep(200);draw();
} 
else if(map[j][i-1]==26){
	direction=2;
	draw();
	map[j][i-1]=6;
	map[j][i]=5;
	blue++;
	settextstyle(15, 0, _T("黑体"));
    setcolor(WHITE);   
	putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了蓝钥匙！") );
       Sleep(200);draw();
} 
 else if(map[j][i-1]==12){
	 if(red!=0){
	direction=2;
	draw();
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("失去一把红钥匙") );
	   Sleep(150);
PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[21]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[22]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[23]);
	Sleep(60);
	map[j][i-1]=6;
	map[j][i]=5;
	red--;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j][i-1]==13){
	 if(blue!=0){
	direction=2;
	draw();
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("失去一把蓝钥匙") );
	   Sleep(150);
	PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[24]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[25]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[26]);
	Sleep(60);
	map[j][i-1]=6;
	map[j][i]=5;
	blue--;
	draw();
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j][i-1]==7){
	 if(yellow!=0){
	direction=2;
	draw();
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("失去一把黄钥匙") );
	   Sleep(150);
	PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC) ;	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[18]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[19]);
	Sleep(60);	putimage((i-1)*IMGWIDTH,j*IMGHEIGHT,&mapimg[20]);
	Sleep(60);
	map[j][i-1]=6;
	map[j][i]=5;
	yellow--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
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
		settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("防御力加10") );
	   Sleep(200);
	PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_SYNC) ;//循环播放音乐snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=10;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
   else if( map[j][i-1]==ATTACK ){	
	  direction=2;
	  draw();
	  settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("攻击力加10") );
	   Sleep(200);
   PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_SYNC) ;//循环播放音乐snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=10;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
   else if( map[j][i-1]==SWORD1 ){	direction=2;
   draw();
   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("获得剑，攻击力加30") );
	   Sleep(200);
   PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME | SND_SYNC) ;//循环播放音乐snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=30;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
       else if( map[j][i-1]==LIFE ){
		   
	   direction=2;
	   draw();
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("生命加500") );
	   Sleep(200);
		PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_SYNC) ;//循环播放音乐snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=500;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
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

else//在这里加入判断，判断所走方向是什么东西，相应的调用相关函数G.people[PERSON].date.attack
{
	direction=2;
	draw();
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}
/* 向下走一步 */
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER1)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER2)==0){
		direction=3;
		draw();
		settextstyle(20, 0, _T("黑体"));
		setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
        Sleep(180);draw();
	}
}
 else if( map[j+1][i]==SWORD3 ){
	direction=3;
	draw();
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("获得高级剑，攻击力加60") );
	   Sleep(200);
	PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME | SND_SYNC) ;
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=60;
	draw();			switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER3)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER4)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER5)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER6)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER7)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("战斗胜利"));
	}
	else if(fight1(MONSTER8)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(576, 256, _T("无法战斗"));		settextstyle(15, 0, _T("黑体"));
        setcolor(WHITE);
        putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
        outtextxy(218, 200, _T("你目前还无法与其战斗") );
        Sleep(180);draw();
	}
}
else if(map[j+1][i]==24){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	yellow++;
	settextstyle(15, 0, _T("黑体"));
    setcolor(WHITE);   
	putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了黄钥匙！") );
       Sleep(200);draw();
} 
else if(map[j+1][i]==25){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	red++;
	settextstyle(15, 0, _T("黑体"));
       setcolor(WHITE);
	   putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了红钥匙！") );
       Sleep(200);draw();
} 
else if(map[j+1][i]==26){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	blue++;
	settextstyle(15, 0, _T("黑体"));
    setcolor(WHITE);   
	putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("你获取了蓝钥匙！") );
       Sleep(200);draw();
} 
 else if(map[j+1][i]==12){
	 if(red!=0){
	direction=3;
	draw();
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
	 putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
    outtextxy(218, 200, _T("失去一把红钥匙") );
	   Sleep(150);
	PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC);
	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[21]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[22]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[23]);
	Sleep(60);
	    map[j+1][i]=6;
	    map[j][i]=5;
	red--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j+1][i]==13){
	 if(blue!=0){
	direction=3;
	draw();
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("失去一把蓝钥匙") );
	   Sleep(150);
	PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC);
	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[24]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[25]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[26]);
	Sleep(60);
	map[j+1][i]=6;
	map[j][i]=5;
	blue--;
	draw();	
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j+1][i]==7){
	 if(yellow!=0){
	direction=3;
	draw();
	settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("失去一把黄钥匙") );
	   Sleep(150);
	PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC);
	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[18]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[19]);
	Sleep(60);	putimage(i*IMGWIDTH,(j+1)*IMGHEIGHT,&mapimg[20]);
	Sleep(60);
	map[j+1][i]=6;
	map[j][i]=5;
	yellow--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
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
			  settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("防御力加10") );
	   Sleep(200);
    PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_SYNC) ;//循环播放音乐snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=10;
	draw();
		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
   else if( map[j+1][i]==ATTACK ){
	   direction=3;
	   draw();
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("攻击力加10") );
	   Sleep(200);
	     PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_SYNC) ;//循环播放音乐snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=10;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
   else if( map[j+1][i]==SWORD1 ){
	   direction=3;
	   draw();
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("获得剑，攻击力加30") );
	   Sleep(200);
		PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_SYNC) ;
      PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME | SND_SYNC) ;//循环播放音乐snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=30;
	draw();	
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	default:break;
	}
   }
       else if( map[j+1][i]==LIFE ){
	   direction=3;
	   draw();
	   settextstyle(15, 0, _T("黑体"));
	setcolor(WHITE);
       putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
       outtextxy(218, 200, _T("生命加500") );
	   Sleep(200);
		PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_SYNC) ;//播放音乐snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=500;
	
	draw();	
	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);
		break;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);break;
		//循环播放音乐snd_loop
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
else//在这里加入判断，判断所走方向是什么东西，相应的调用相关函数
{
	direction=3;
	draw();
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}
 
void npc1(){
loadimage(&duihua,_T("对话框.bmp"),352,95,true);
settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
setbkmode(TRANSPARENT);// 设置文字背景为透明色
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式注意坐标
outtextxy(218, 345, _T("勇士:。。。。。。") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:你醒了！") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));//勇士格式注意坐标
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("勇士:。。。。。。你是谁？我在哪里？") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:我是这里的仙子，") );
outtextxy(218, 232, _T("刚才你被这里的小怪打昏了。") );
getchar();draw();
settextstyle(15, 0, _T("黑体"));//勇士格式注意坐标
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("勇士:。。。剑，剑，我的剑呢？") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:你的剑被他们抢走了，") );
outtextxy(218, 232, _T("我只来得及将你救出来。") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));//勇士格式注意坐标
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("勇士:那,公主呢？我是来救公主的。") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:公主还在里面，你这样去是不行的") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));//勇士格式注意坐标
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("勇士:我答应了国王要把公主救出来，") );
outtextxy(218, 377, _T("勇士:那我现在应该怎么办呢？") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:放心吧，我把我的力量借给你") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
outtextxy(218, 200, _T("你的能力提升了!") );
getchar();draw();
settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:现在只能给你这么多能力了") );
getchar();draw();
settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:不过，你得先帮我去救一个人") );
getchar();draw();
settextstyle(15, 0, _T("黑体"));//勇士格式注意坐标
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("勇士:什么人？") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:她应该在第二层，她穿着斗篷") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));//勇士格式注意坐标
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("勇士:你为什么不自己去？") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:我的能力被封印了一部分，我需要别人帮我") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:等你救了那个人，他有办法帮我！") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));//勇士格式注意坐标
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("勇士:好吧，我试试看") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:这里有把黄钥匙，你可以进去了") );
getchar();draw();

yellow++;//获得钥匙

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);
outtextxy(218, 200, _T("你获取了黄钥匙！") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));//勇士格式注意坐标
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
outtextxy(218, 345, _T("勇士:后会有期！") );
getchar();draw();
return;
     }//初见小仙子

void npc2(){
loadimage(&duihua,_T("对话框.bmp"),352,95,true);
setbkmode(TRANSPARENT);// 设置文字背景为透明色

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式注意坐标
outtextxy(218, 345, _T("勇士:这里只有他一个人，身穿斗篷。。。！！") );
getchar();draw();
settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式注意坐标
outtextxy(218, 345, _T("勇士:你认识小仙子吗？") );
getchar();draw();
settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("巫师:咳咳。。。你是谁？") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式注意坐标
outtextxy(218, 345, _T("勇士:小仙子拜托我来救你，她说你可以帮他") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("巫师:好，我自会帮他，你接下来去哪？") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式注意坐标
outtextxy(218, 345, _T("勇士:我要去杀死那个魔头救出公主！") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("巫师:噢..我知道你要找谁了") );
getchar();draw();
settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("巫师:你还有很长的路要走") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式注意坐标
outtextxy(218, 345, _T("勇士:你可以帮助我吗？") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("巫师:那当然，你救了我，我给予你力量") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式注意坐标
outtextxy(218, 345, _T("勇士:啊！！这是什么？") );
getchar();draw();

Speed=10;//速度加快

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("巫师:你试着动动看") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式注意坐标
outtextxy(218, 345, _T("勇士:哇，身体好轻盈") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("巫师:嗯，你现在走的更快了，祝你好运！") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式注意坐标
outtextxy(218, 345, _T("勇士:谢谢！") );
getchar();

map3[3][12]=0;

draw();


return;
}
void npc3(){
loadimage(&duihua,_T("对话框.bmp"),352,95,true);
settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
setbkmode(TRANSPARENT);// 设置文字背景为透明色
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式注意坐标
outtextxy(218, 345, _T("勇士:小仙子你怎么在这里") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:谢谢你兑现了你的承诺") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:为了报答你，我会为你使用我的魔法") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式注意坐标
outtextxy(218, 345, _T("勇士:我想有没有其他的东西，那个实在太痛了") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:哈哈，我猜他给你施放魔法了") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:那我给你一些东西吧.....") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("你获得了红钥匙*1，黄钥匙*2，蓝钥匙*1") );
getchar();draw();yellow++;blue++;red++;yellow++;
G.people[PERSON].date.attack+=150;//提升能力获取buff
G.people[PERSON].date.defence+=150;
G.people[PERSON].date.life+=2000;

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//仙子格式
outtextxy(218, 200, _T("仙子:后面的路得你自己走了，多加小心！") );
getchar();
draw();
return;

}
void boss(){
	settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
setbkmode(TRANSPARENT);// 设置文字背景为透明色
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//魔王格式注意坐标
outtextxy(218, 200, _T("魔王:你终究还是来了") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式
outtextxy(218, 345, _T("勇士:你死到临头了，大魔王") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//魔王格式注意坐标
outtextxy(218, 200, _T("魔王:哈哈哈哈哈，你在说什么笑话") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式
outtextxy(218, 345, _T("勇士:大魔王，快把我的公主还回来") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//魔王格式注意坐标
outtextxy(218, 200, _T("魔王:就凭你？") );
getchar();draw();
}void npc4()
{
	settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
setbkmode(TRANSPARENT);// 设置文字背景为透明色
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//魔王格式注意坐标
outtextxy(218, 200, _T("公主:哇，勇士你终于来了") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式
outtextxy(218, 345, _T("勇士:公主我终于找到你了") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//魔王格式注意坐标
outtextxy(218, 200, _T("公主:嘘，你小声点，小心被魔王听到") );
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);//勇士格式
outtextxy(218, 345, _T("勇士:大魔王已经被我打败了，") );
outtextxy(218, 377, _T("和我一起回家吧" ));
getchar();draw();

settextstyle(15, 0, _T("黑体"));
setcolor(WHITE);
putimage(IMGWIDTH*6,IMGHEIGHT*5,&duihua);//魔王格式注意坐标
outtextxy(218, 200, _T("公主:这是真的吗?太厉害了勇士") );
getchar();
ending();
play2();
}

/*游戏结束*/
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
	settextstyle(20, 0, _T("黑体"));
	outtextxy(120, 80, _T("美丽的公主终于被我们的英雄所拯救"));
	Sleep(100);
	
	}
    for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("黑体"));
	outtextxy(100, 120, _T("拥有神之血裔的勇士"));
	outtextxy(100, 160, _T("使这个国家又恢复了和平"));
	Sleep(100);
	
	}

	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("黑体"));
	outtextxy(100, 200, _T("而且公主貌似似乎已经爱上了我们的勇士"));
	Sleep(100);
	
	}
	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("黑体"));
	outtextxy(100, 240, _T("这一季的大冒险已经结束"));
	outtextxy(100, 280, _T("这一季作者的期末考试即将来到"));
	Sleep(100);
	
	}
	for(counter=0;counter<20;counter++)
	{
	settextstyle(20, 0, _T("黑体"));
	outtextxy(100, 320, _T("作者坚定信念、握紧武器，毫不犹豫的冲进考场"));
	outtextxy(100, 360, _T("又有怎样的故事在等待着红桃组的三位苦逼作者??"));
	outtextxy(100, 400, _T("我们考完再来揭晓！！！"));

	Sleep(100);
	
	}
	getchar();
	closegraph();
	system("cls");
	return;
}
/*文件储存*/
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

/*文件读取*/
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
/*判断文件是否储存成功*/
void issave()
{
	
	loadimage(&duihua,_T("对话框.bmp"),352,95,true);
    settextstyle(15, 0, _T("黑体"));
    setcolor(WHITE);
    setbkmode(TRANSPARENT);// 设置文字背景为透明色
    putimage(IMGWIDTH*6,IMGHEIGHT*10,&duihua);
	if(gamesave())
	{
    outtextxy(218, 345, _T("保存成功") );
	}
	else
	{
		outtextxy(218, 345, _T("保存失败") );
	}

    getchar();draw();


}
