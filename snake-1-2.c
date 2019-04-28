#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//��Ϸ�����ߵĿ���
 #define up 'w'
 #define down 's'
 #define left 'a'
 #define right 'd'
 #define pause 'p'

//�˵�����Ŀ���
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
	printf("��");
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
	printf("--->��ʼ��ı���		   \n");
	printf("    �����ⳡ��Ϸ		   \n");
	printf("===============================\n");
}

void print_exit()
{
	printf("===============================\n");
	printf("    ��ʼ��ı���		   \n");
	printf("--->�����ⳡ��Ϸ		   \n");
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
	char name[1024] = "�����";
	printf("��ӭ, %s !", name);	
	gotoxy(63, 15);	
	char score[1024] = { 0 };
	printf("���ĳɼ���:%d ", score);
	gotoxy(63, 20);	
	printf("��Ϸ����:AustinYANyh");
}

void PrintSnake()
{
	head =(snake*)malloc(sizeof(snake));	
	head->x = 28;	
	head->y = 13;//���ߵĳ�ʼλ��
	gotoprint(head->x, head->y);

 	tail = (snake*)malloc(sizeof(snake));
 	snake *p = (snake*)malloc(sizeof(snake));
 	snake *q = (snake*)malloc(sizeof(snake));

 	p->x = 28;	
 	p->y = 14;	//����ǰ��
 	q->x = 28;	
 	q->y = 15;	//��������ǰ��
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
	system("color 0E");//��ɫ��������ɫ����
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
