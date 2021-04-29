#ifndef _FUNCTION_H_
#define _FUNCTION_H_
/* 键盘上下左右键值 */
#define KEYUP	 72
#define KEYDOWN	 80
#define KEYLEFT	 75
#define KEYRIGHT 77
/* 人物方向 */
#define DIR_RIGHT 0                    
#define DIR_UP   1
#define DIR_LEFT 2
#define DIR_DOWN 3
#define screenwidth  500
#define screenheight 600
//各地图元素值	
#define LANZHUAN 1
#define PERSON 6
#define WALL 2
#define STAR 3
#define YANJIANG 4
#define ROAD 5
#define YELLOWDOOR 7	
#define NPC1 0
#define NPC2 9
#define UPFLOOR 8
#define DOWNFLOOR 10
#define NPC3 11
#define REDDOOR 12
#define BLUEDOOR 13
#define MONSTER1 14
#define MONSTER2 15
#define MONSTER3 16
#define MONSTER4 17
#define MONSTER5 18
#define MONSTER6 19
#define BOSS 20
#define LIFE 21
#define SWORD1 22
#define YELLOWKEY 24
#define REDKEY  25
#define BLUEKEY  26
#define DEFENCE 27
#define CAGE 29
#define MONSTER7 29
#define MONSTER8 30
#define NPC4 31
#define ATTACK 33
#define SWORD3 34
#define Num 50 //定义点
//图片大小
#define IMGWIDTH  32
#define IMGHEIGHT 32
#define IMAGEWIDTH  32
#define IMAGEHEIGHT 32
#define imgwidth 32
#define imgheight 32
//地图数组长宽
#define POSHEIGHT 13//行数
#define POSWIDTH  23 //列数
extern int map1[POSHEIGHT][POSWIDTH];
extern int map2[POSHEIGHT][POSWIDTH];
extern int map3[POSHEIGHT][POSWIDTH];
extern int map4[POSHEIGHT][POSWIDTH];
extern int map03[POSHEIGHT][POSWIDTH];
extern int map04[POSHEIGHT][POSWIDTH];
extern int map[13][23];
/* 移动速度 */
extern int Speed ;
/* 当前人物位置 */
extern int positionx, positiony;//x是横坐标对应为列数，y是纵坐标对应为行数

extern int direction;//0-3代表右，上，左，下


//被draw调用的地图数组，所有的操作都在map上进行，跳转楼层时将相应的mapx改变为map

extern int f;//表示在第几层，跳转楼层时改变其值

//图片数组

// 基本动作——获取当前方向 
extern int getDirection();


extern void draw();


extern void loadmap();

/* 向上走一步 */
extern void StepUp();

/* 向右走一步 */
extern void StepRight();



/* 向左走一步 */
extern void StepLeft();

/* 向下走一步 */
extern void StepDown();

extern void play();
extern void play2();

extern void init();

extern void up();

extern void down();

extern void music();

extern int fight1(int N);

extern void fight2(int N);

extern void drawfight();

extern IMAGE mapimg[27];
extern IMAGE propsimg[11];
extern IMAGE monstersimg[9];
extern IMAGE npcimg[4];
extern IMAGE personimg[4];
extern IMAGE fi;
extern IMAGE duihua;
extern IMAGE kuang[2];
extern int yellow;
extern int red;
extern int blue;
extern void zhuanchang();
extern void npc1();
extern void npc2();
extern void npc3();
extern void boss();
extern void npc4();
extern int gamesave();
extern int gameload();
extern void issave();
extern void ending();
#endif