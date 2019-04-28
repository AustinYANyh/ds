#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define pause 'p'

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

}snake,*head,*tail;

typedef struct Food
{
	int x;
	int y;

}food;

//void gotoxy(int x, int y)
//{
//	COORD pos;
//	HANDLE hOutput;
//	pos.X = x;
//	pos.Y = y;
//	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(hOutput, pos);
//}

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
	printf("	�����ⳡ��Ϸ		   \n");
	printf("===============================\n");
}

void print_exit()
{
	printf("===============================\n");
	printf("	��ʼ��ı���		   \n");
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
		case up:
			flag--;
			if (flag < 0)
			{
				flag = PAGE_NUM - 1;
			}
			break;
		case down:
			flag++;
			if (flag > PAGE_NUM - 1)
			{
				flag = 0;
			}
			break;
		case '\r':
			return flag;
		default:;
		}
		printSence[flag]();
	}
}


int main()
{
	system("color 0E");//��ɫ��������ɫ����
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
   system("pause");
   return 0;
}
