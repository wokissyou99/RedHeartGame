#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include<graphics.h>                      //��ͼ��ͷ�ļ�����ͼ�����Ҫ
#include<conio.h>                         //�ڿ���̨��������ļ�
#include <math.h>
#include <windows.h>
#include "function.h"

#pragma comment(lib,"Winmm.lib")
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER1)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER2)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER3)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER4)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER5)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER6)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
	}
}
		else if(map[j-1][i]==24)
		{
		direction=1;
		draw();PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
		map[j-1][i]=6;
		map[j][i]=5;
		yellow++;
	draw();
		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} 
else if(map[j-1][i]==25){
	direction=1;
		draw();
	map[j-1][i]=6;
	map[j][i]=5;
    red++;PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();
			switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} else if(map[j-1][i]==26){
	direction=1;
		draw();
	map[j-1][i]=6;
	map[j][i]=5;
	blue++;PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();
			switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} 
 else if(map[j-1][i]==12){
	 if(red!=0){
	direction=1;
		draw();PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
		 map[j-1][i]=6;
	map[j][i]=5;
	red--;
	draw();
	 		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j-1][i]==13){
	 if(blue!=0){
		 direction=1;
		draw();PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
	blue--;
	draw();
	 		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j-1][i]==7){
	 if(yellow!=0){
		 direction=1;
		draw();PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
	yellow--;
	draw();
	 switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
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
			  PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
			  direction=1;
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=5;
	draw();
	 switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
   else if( map[j-1][i]==ATTACK ){
	   direction=1;PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=5;
	draw(); switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
   else if( map[j-1][i]==SWORD1 ){
	   direction=1;PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=15;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
    else if( map[j-1][i]==LIFE ){
	   direction=1;PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=50;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
   else//����������жϣ��ж����߷�����ʲô��������Ӧ�ĵ�����غ�������Ҫnpc������ս������
	//��ս������������Ҫ�رջ���ִ�У�����ս��ʱ�ı�map��init,�������ƣ�����¥�ݺ�����
{
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER1)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER2)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER3)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER4)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER5)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER6)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
	}
}
	else if(map[j][i+1]==24){
		direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	yellow++;PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} 
else if(map[j][i+1]==25){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	red++;PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} 
else if(map[j][i+1]==26){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	blue++;PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} 
 else if(map[j][i+1]==12){
	 if(red!=0){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	red--;PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j][i+1]==13){
	 if(blue!=0){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	blue--;PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j][i+1]==7){
	 if(yellow!=0){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	yellow--;PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
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
		   direction=0;PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME|SND_ASYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=5;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
   else if( map[j][i+1]==ATTACK ){direction=0;PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME|SND_ASYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=5;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
   else if( map[j][i+1]==SWORD1 ){direction=0;PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME|SND_ASYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=15;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
       else if( map[j][i+1]==LIFE ){PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME|SND_ASYNC);
	   direction=1;
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=50;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
else//����������жϣ��ж����߷�����ʲô��������Ӧ�ĵ�����غ���
{
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}

/* ������һ�� */
void StepLeft()
 {int i = positionx;
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER1)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER2)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER3)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER4)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER5)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER6)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
	}
}
else if(map[j][i-1]==24){
	direction=2;
	draw();PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	yellow++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} 
else if(map[j][i-1]==25){
	direction=2;
	draw();PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	red++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} 
else if(map[j][i-1]==26){
	direction=2;
	draw();PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	blue++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} 
 else if(map[j][i-1]==12){
	 if(red!=0){
	direction=2;
	draw();	PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	red--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j][i-1]==13){
	 if(blue!=0){
	direction=2;
	draw();PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	blue--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j][i-1]==7){
	 if(yellow!=0){
	direction=2;
	draw();PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	yellow--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
    else if( map[j][i-1]==8 ){
    up();
   }
   else if( map[j][i-1]==10 ){
    down();
   }
    else if( map[j][i-1]==DEFENCE ){	direction=2;
	PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//ѭ����������snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=5;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
   else if( map[j][i-1]==ATTACK ){	direction=2;
   PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//ѭ����������snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=5;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
   else if( map[j][i-1]==SWORD1 ){	direction=2;
   PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//ѭ����������snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=15;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
       else if( map[j][i-1]==LIFE ){
		   PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//ѭ����������snd_loop
	   direction=1;
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=50;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
else//����������жϣ��ж����߷�����ʲô��������Ӧ�ĵ�����غ���G.people[PERSON].date.attack
{
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}

/* ������һ�� */
void StepDown()
 {
	 int i = positionx;
 int j = positiony;
if(j+1>11)
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER1)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER2)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER3)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER4)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER5)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
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
		outtextxy(20, 200, _T("ս��ʤ��"));
	}
	else if(fight1(MONSTER6)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("����"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("�޷�ս��"));
	}
}
else if(map[j+1][i]==24){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	yellow++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} 
else if(map[j+1][i]==25){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	red++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} 
else if(map[j+1][i]==26){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	PlaySound (TEXT ("��Կ��.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	blue++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
} 
 else if(map[j+1][i]==12){
	 if(red!=0){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	red--;
	PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j+1][i]==13){
	 if(blue!=0){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	blue--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j+1][i]==7){
	 if(yellow!=0){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	yellow--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
    else if( map[j+1][i]==8 ){
    up();
   }
   else if( map[j+1][i]==10 ){
    down();
   }
          else if( map[j+1][i]==DEFENCE ){direction=3;
		  PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//ѭ����������snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=5;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
   else if( map[j+1][i]==ATTACK ){
	     PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//ѭ����������snd_loop
	map[j+1][i]=6;direction=3;
	map[j][i]=5;
    G.people[PERSON].date.attack+=5;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
   else if( map[j+1][i]==SWORD1 ){direction=3;
      PlaySound (TEXT ("����.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//ѭ����������snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=15;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
       else if( map[j+1][i]==LIFE ){
		 PlaySound (TEXT ("��ȡ�������.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//ѭ����������snd_loop
	   direction=1;
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=50;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("��һ��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 2:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 3:PlaySound (TEXT ("�ڶ�����.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	case 4:PlaySound (TEXT ("boss��.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//ѭ����������snd_loop
	}
   }
else//����������жϣ��ж����߷�����ʲô��������Ӧ�ĵ�����غ���
{
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}