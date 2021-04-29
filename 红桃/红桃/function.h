#ifndef _FUNCTION_H_
#define _FUNCTION_H_
/* �����������Ҽ�ֵ */
#define KEYUP	 72
#define KEYDOWN	 80
#define KEYLEFT	 75
#define KEYRIGHT 77
/* ���﷽�� */
#define DIR_RIGHT 0                    
#define DIR_UP   1
#define DIR_LEFT 2
#define DIR_DOWN 3
#define screenwidth  500
#define screenheight 600
//����ͼԪ��ֵ	
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
#define Num 50 //�����
//ͼƬ��С
#define IMGWIDTH  32
#define IMGHEIGHT 32
#define IMAGEWIDTH  32
#define IMAGEHEIGHT 32
#define imgwidth 32
#define imgheight 32
//��ͼ���鳤��
#define POSHEIGHT 13//����
#define POSWIDTH  23 //����
extern int map1[POSHEIGHT][POSWIDTH];
extern int map2[POSHEIGHT][POSWIDTH];
extern int map3[POSHEIGHT][POSWIDTH];
extern int map4[POSHEIGHT][POSWIDTH];
extern int map03[POSHEIGHT][POSWIDTH];
extern int map04[POSHEIGHT][POSWIDTH];
extern int map[13][23];
/* �ƶ��ٶ� */
extern int Speed ;
/* ��ǰ����λ�� */
extern int positionx, positiony;//x�Ǻ������ӦΪ������y���������ӦΪ����

extern int direction;//0-3�����ң��ϣ�����


//��draw���õĵ�ͼ���飬���еĲ�������map�Ͻ��У���ת¥��ʱ����Ӧ��mapx�ı�Ϊmap

extern int f;//��ʾ�ڵڼ��㣬��ת¥��ʱ�ı���ֵ

//ͼƬ����

// ��������������ȡ��ǰ���� 
extern int getDirection();


extern void draw();


extern void loadmap();

/* ������һ�� */
extern void StepUp();

/* ������һ�� */
extern void StepRight();



/* ������һ�� */
extern void StepLeft();

/* ������һ�� */
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