#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

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

char click = 1;
int sorce = 0;
char name[1024] = { 0 };

typedef struct Snake
{
	int x;
	int y;
	struct Snake* next;

}snake;

snake *head, *tail;

struct Food
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

void gotoprint(int x, int y)
{
	gotoxy(x, y);
	printf("■");
}

void gotoclear(int x, int y)
{
	gotoxy(x, y);
	printf(" ");
}

int getKeyBoard()
{
	int a = _getch();
	int result = ((char)a < 0) ? (a << 8 | _getch()) : a;
	return result;
}

void print_start()
{
	gotoxy(45, 10);
	printf("====================================\n");
	gotoxy(55, 13);
	printf("--->开始你的表演		   \n");
	gotoxy(55, 16);
	printf("    结束这场游戏		   \n");
	gotoxy(45, 20);
	printf("====================================\n");
}

void print_exit()
{
	gotoxy(45, 10);
	printf("====================================\n");
	gotoxy(55, 13);
	printf("    开始你的表演		   \n");
	gotoxy(55, 16);
	printf("--->结束这场游戏		   \n");
	gotoxy(45, 20);
	printf("====================================\n");
}

void print_name()
{
	gotoxy(55, 13);
	printf("请输入玩家姓名:");
	scanf("%s", name);
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
	for (i = 0; i <= 60; i += 2)
	{
		gotoprint(i, 0);
		gotoprint(i, 28);
	}
	for (i = 1; i <= 28; ++i)
	{
		gotoprint(0, i);
		gotoprint(60, i);
	}
	gotoxy(83, 10);
	printf("欢迎, %s !", name);

	gotoxy(83, 15);
	printf("您的成绩是:%d ", sorce);

	gotoxy(83, 20);
	printf("游戏制作:AustinYANyh");
}

void PrintSnake()
{
	head = (snake*)malloc(sizeof(snake));
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

void CreatFood()
{
	srand((unsigned int)time(0));
lable:

	food.y = rand() % (25 - 1 + 1) + 1;
	food.x = rand() % (54 - 2 + 1) + 2;

	if ((food.x % 2) != 0)
	{
		food.x = food.x + 1;
	}

	snake* judge = head;
	//判断随机出的food位置是否与蛇的身体重合
	while (1)
	{
		if (judge->next == NULL)
		{
			break;
		}
		if (food.x == judge->x && food.y == judge->y)//x y确定一个位置.此处用&&
		{
			goto lable;//重合则重新生成随机数
		}
		judge = judge->next;
	}
	gotoxy(food.x, food.y);//光标移动到food的位置
	printf("*");
}

void EatFood()
{
	if (head->x == food.x&&head->y == food.y)
	{
		CreatFood();
		snake *_new = (snake*)malloc(sizeof(snake));
		snake *p;
		p = head;
		while (1)
		{
			if (p->next->next == NULL)
			{
				break;
			}
			p = p->next;
		}
		p->next = _new;
		_new->next = tail;
		sorce += 10;
		gotoxy(93, 15);
		printf("%d", sorce);
	}
}

void UpdateSnake(int m, int n)
{
	snake *p = head->next;
	int a, b, c, d;
	//把节点内的数据先保存起来
	a = p->x;
	b = p->y;

	while (1)
	{
		if (p->next->next == NULL)
		{
			break;
		}
		//把p->next的值分别存入c,d之中与a,b交换
		c = p->next->x;
		p->next->x = a;
		a = c;

		d = p->next->y;
		p->next->y = b;
		b = d;

		p = p->next;//循环的自增
	}

	p = head->next;
	if (p->next != NULL)
	{
		p->x = m;//把蛇头的坐标赋给蛇
		p->y = n;
	}
}

void MovingSnake()
{
	int count = 0;	//蛇的身体长度
	int a = head->x;
	int b = head->y;
	snake *p = head;

	while (1)
	{
		if (p->next == NULL)
		{
			break;
		}
		gotoclear(p->x, p->y);
		++count;				//消除一个等会重新打印一个,造成动态效果
		p = p->next;
	}

	// up down left right 使用字符  w s a d 代替
	switch (click)
	{
	case up:
			head->y -= 1;//往上走纵坐标走一步自减一
			UpdateSnake(a, b);
			break;
	case down:
		head->y += 1;//往下走纵坐标自增一
		UpdateSnake(a, b);
		break;
	case left:
		head->x -= 2;//往左走横坐标自减二
		UpdateSnake(a, b);
		break;
	case right:
		head->x += 2;//往右走横坐标自增二
		UpdateSnake(a, b);
		break;
	case pause:
		system("pause");
		break;
	}

	p = head;
	while (1)
	{
		if (p->next == NULL)
		{
			break;
		}
		gotoprint(p->x, p->y);
		p = p->next;
	}
	p = head;
	int speed = 0;
	gotoxy(0, 28);
	if (count <= 10)
	{
		speed = 150;
	}
	else if (count > 10 && count <= 20)
	{
		speed = 100;
	}
	else if (count > 20 && count <= 40)
	{
		speed = 50;
	}
	else
	{
		speed = 10;
	}
	Sleep(speed);
}

void Finish()
{
	system("cls");
	gotoxy(45, 10);
	printf("====================================\n");
	gotoxy(55, 13);
	printf("您的分数是:%d		   \n", sorce);
	gotoxy(47, 16);
	printf("用金灿毅的话说,多一点练习吧!兄弟\n");
	gotoxy(45, 20);
	printf("====================================\n");
	gotoxy(45, 23);
	system("pause");
	return 0;
}

int CheckWinner()
{
	if (head->x == 0 || head->x == 60 || head->y == 0 || head->y == 28)
	{
		Finish();
		return 0;
	}
	snake *p = head->next;
	while (1)
	{
		if (p->next == NULL)
		{
			break;
		}
		if (head->x == p->x&&head->y == p->y)
		{
			Finish();
			return 0;
		}
		p = p->next;
	}
	return 1;
}

int ClickControl()
{
		while (1)
		{
			if (CheckWinner() == 0)
			{
				Finish();
				return 0;
			}
			if (_kbhit())//如果指令不做修改,就不给click重新赋值
			{
				click = _getch();
			}
			MovingSnake();
			EatFood();
		}
	return 1;
}


int main()
{
	system("color 0E");//黑色背景淡黄色字体

	while (1)
	{
		switch (welcomePage())
		{
		case START:
					  print_name();
					  system("cls");
					  Creatmap();
					  PrintSnake();
					  CreatFood();
					  ClickControl();
					  if (ClickControl() == 0)
					  {
						  return 0;
					  }
					  break; 
		case EXIT:
			return 0;
		}
	}
	return 0;
}
