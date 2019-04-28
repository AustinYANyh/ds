#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//游戏界面蛇的控制
 #define up 'w'
 #define down 's'
 #define left 'a'
 #define right 'd'
 #define pause 'p'

//菜单界面的控制
#define UP    0xE048
#define DOWN  0xE050
#define LEFT  0xE04B
#define RIGHT 0xE04D

#define PAGE_NUM 2
enum
{
	START = 0,
	EXIT,
};

typedef struct Snake
{
	int x;
	int y;
	struct Snake* next;

}snake;

snake *head,*tail;

typedef struct Food
{
	int x;
	int y;

}food;

void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

void gotoprint(int x,int y)
{
	gotoxy(x,y);
	printf("■");
}

int getKeyBoard()
{
	int a = _getch();
	int result = ((char)a < 0) ? (a << 8 | _getch()) : a;
	return result;
}

void print_start()
{
	printf("===============================\n");
	printf("--->开始你的表演		   \n");
	printf("    结束这场游戏		   \n");
	printf("===============================\n");
}

void print_exit()
{
	printf("===============================\n");
	printf("    开始你的表演		   \n");
	printf("--->结束这场游戏		   \n");
	printf("===============================\n");
}

void(*printSence[PAGE_NUM])() = { print_start, print_exit };


int welcomePage()
{
	int flag = 0;
	print_start();
	while (1)
	{
		switch (getKeyBoard())
		{
		case UP:
			flag--;
			if (flag < 0)
			{
				flag = PAGE_NUM - 1;
			}
			system("cls");
			break;
		case DOWN:
			flag++;
			if (flag > PAGE_NUM - 1)
			{
				flag = 0;
			}
			system("cls");
			break;
		case '\r':
			return flag;
		default:;
		}
		printSence[flag]();
	}
}

void Creatmap()
{
	int i = 0;
	for (i=0; i <= 60; i+=2)
	{
		gotoprint(i,0);
		gotoprint(i,28);
	}
	for (i = 1; i <= 28; ++i)
	{
		gotoprint(0,i);
		gotoprint(60,i);
	}
	gotoxy(63, 10);	
	char name[1024] = "闫云皓";
	printf("欢迎, %s !", name);	
	gotoxy(63, 15);	
	char score[1024] = { 0 };
	printf("您的成绩是:%d ", score);
	gotoxy(63, 20);	
	printf("游戏制作:AustinYANyh");
}

void PrintSnake()
{
	head =(snake*)malloc(sizeof(snake));	
	head->x = 28;	
	head->y = 13;//给蛇的初始位置
	gotoprint(head->x, head->y);

 	tail = (snake*)malloc(sizeof(snake));
 	snake *p = (snake*)malloc(sizeof(snake));
 	snake *q = (snake*)malloc(sizeof(snake));

 	p->x = 28;	
 	p->y = 14;	//向下前进
 	q->x = 28;	
 	q->y = 15;	//继续向下前进
 	head->next = p;
 	p->next = q;	
 	q->next = tail;
 	gotoprint(p->x, p->y);	
	gotoprint(q->x, q->y);	
	tail->next = NULL;	
//  tail->x = 4;	
// 	tail->y = 2;
}

int main()
{
	system("color 0E");//黑色背景淡黄色字体
#if(0)
	while (1)
	{
		switch (welcomePage())
		{
		case START:
			//TO DO
			break;
		case EXIT:
			return 0;
		}
	}
#endif
	Creatmap();
	PrintSnake();
   //system("pause");
   return 0;
}
