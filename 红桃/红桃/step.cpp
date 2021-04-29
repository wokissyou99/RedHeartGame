#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include<graphics.h>                      //绘图库头文件，绘图语句需要
#include<conio.h>                         //在控制台输入输出文件
#include <math.h>
#include <windows.h>
#include "function.h"

#pragma comment(lib,"Winmm.lib")
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER1)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER2)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER3)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER4)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER5)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER6)==0){
		direction=1;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
	}
}
		else if(map[j-1][i]==24)
		{
		direction=1;
		draw();PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
		map[j-1][i]=6;
		map[j][i]=5;
		yellow++;
	draw();
		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} 
else if(map[j-1][i]==25){
	direction=1;
		draw();
	map[j-1][i]=6;
	map[j][i]=5;
    red++;PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();
			switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} else if(map[j-1][i]==26){
	direction=1;
		draw();
	map[j-1][i]=6;
	map[j][i]=5;
	blue++;PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();
			switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} 
 else if(map[j-1][i]==12){
	 if(red!=0){
	direction=1;
		draw();PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
		 map[j-1][i]=6;
	map[j][i]=5;
	red--;
	draw();
	 		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j-1][i]==13){
	 if(blue!=0){
		 direction=1;
		draw();PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
	blue--;
	draw();
	 		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j-1][i]==7){
	 if(yellow!=0){
		 direction=1;
		draw();PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
	yellow--;
	draw();
	 switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
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
			  PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
			  direction=1;
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=5;
	draw();
	 switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
   else if( map[j-1][i]==ATTACK ){
	   direction=1;PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=5;
	draw(); switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
   else if( map[j-1][i]==SWORD1 ){
	   direction=1;PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=15;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
    else if( map[j-1][i]==LIFE ){
	   direction=1;PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j-1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=50;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
   else//在这里加入判断，判断所走方向是什么东西，相应的调用相关函数，需要npc函数，战斗函数
	//（战斗函数若是需要关闭画布执行，结束战斗时改变map再init,其他类推，上下楼梯函数）
{
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER1)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER2)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER3)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER4)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER5)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER6)==0){
		direction=0;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
	}
}
	else if(map[j][i+1]==24){
		direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	yellow++;PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} 
else if(map[j][i+1]==25){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	red++;PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} 
else if(map[j][i+1]==26){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	blue++;PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} 
 else if(map[j][i+1]==12){
	 if(red!=0){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	red--;PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j][i+1]==13){
	 if(blue!=0){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	blue--;PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j][i+1]==7){
	 if(yellow!=0){
	direction=0;
	draw();
	map[j][i+1]=6;
	map[j][i]=5;
	yellow--;PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
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
		   direction=0;PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME|SND_ASYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=5;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
   else if( map[j][i+1]==ATTACK ){direction=0;PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME|SND_ASYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=5;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
   else if( map[j][i+1]==SWORD1 ){direction=0;PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME|SND_ASYNC);
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=15;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
       else if( map[j][i+1]==LIFE ){PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME|SND_ASYNC);
	   direction=1;
	map[j][i+1]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=50;
	draw();		switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
else//在这里加入判断，判断所走方向是什么东西，相应的调用相关函数
{
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}

/* 向左走一步 */
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER1)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER2)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER3)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER4)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER5)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER6)==0){
		direction=2;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
	}
}
else if(map[j][i-1]==24){
	direction=2;
	draw();PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	yellow++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} 
else if(map[j][i-1]==25){
	direction=2;
	draw();PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	red++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} 
else if(map[j][i-1]==26){
	direction=2;
	draw();PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	blue++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} 
 else if(map[j][i-1]==12){
	 if(red!=0){
	direction=2;
	draw();	PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	red--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j][i-1]==13){
	 if(blue!=0){
	direction=2;
	draw();PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	blue--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j][i-1]==7){
	 if(yellow!=0){
	direction=2;
	draw();PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	map[j][i-1]=6;
	map[j][i]=5;
	yellow--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
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
	PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//循环播放音乐snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=5;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
   else if( map[j][i-1]==ATTACK ){	direction=2;
   PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//循环播放音乐snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=5;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
   else if( map[j][i-1]==SWORD1 ){	direction=2;
   PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//循环播放音乐snd_loop
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=15;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
       else if( map[j][i-1]==LIFE ){
		   PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//循环播放音乐snd_loop
	   direction=1;
	map[j][i-1]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=50;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
else//在这里加入判断，判断所走方向是什么东西，相应的调用相关函数G.people[PERSON].date.attack
{
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}

/* 向下走一步 */
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
		settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER1)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER2)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER3)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER4)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER5)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
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
		outtextxy(20, 200, _T("战斗胜利"));
	}
	else if(fight1(MONSTER6)==0){
		direction=3;
		draw();
			settextstyle(20, 0, _T("黑体"));
		 setbkmode(TRANSPARENT);		
		outtextxy(20, 200, _T("无法战斗"));
	}
}
else if(map[j+1][i]==24){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	yellow++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} 
else if(map[j+1][i]==25){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	red++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} 
else if(map[j+1][i]==26){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	PlaySound (TEXT ("捡钥匙.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	blue++;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
} 
 else if(map[j+1][i]==12){
	 if(red!=0){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	red--;
	PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
  else if(map[j+1][i]==13){
	 if(blue!=0){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	blue--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}}
	 else putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
} 
   else if(map[j+1][i]==7){
	 if(yellow!=0){
	direction=3;
	draw();
	map[j+1][i]=6;
	map[j][i]=5;
	PlaySound (TEXT ("开门.wav"), NULL, SND_FILENAME | SND_ASYNC) ;
	yellow--;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
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
		  PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//循环播放音乐snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.defence+=5;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
   else if( map[j+1][i]==ATTACK ){
	     PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//循环播放音乐snd_loop
	map[j+1][i]=6;direction=3;
	map[j][i]=5;
    G.people[PERSON].date.attack+=5;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
   else if( map[j+1][i]==SWORD1 ){direction=3;
      PlaySound (TEXT ("捡起剑.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//循环播放音乐snd_loop
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.attack+=15;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
       else if( map[j+1][i]==LIFE ){
		 PlaySound (TEXT ("捡取增益道具.wav"), NULL, SND_FILENAME | SND_ASYNC) ;//循环播放音乐snd_loop
	   direction=1;
	map[j+1][i]=6;
	map[j][i]=5;
    G.people[PERSON].date.life+=50;
	draw();	switch(f){
	case 1:PlaySound (TEXT ("第一层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 2:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 3:PlaySound (TEXT ("第二三层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	case 4:PlaySound (TEXT ("boss层.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP) ;//循环播放音乐snd_loop
	}
   }
else//在这里加入判断，判断所走方向是什么东西，相应的调用相关函数
{
putimage(i*IMAGEWIDTH,j*IMAGEHEIGHT,&personimg[direction]);
}
return;
}