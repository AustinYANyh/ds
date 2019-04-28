#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

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
	printf("��");
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
	printf("--->��ʼ��ı���		   \n");
	gotoxy(55, 16);
	printf("    �����ⳡ��Ϸ		   \n");
	gotoxy(45, 20);
	printf("====================================\n");
}

void print_exit()
{
	gotoxy(45, 10);
	printf("====================================\n");
	gotoxy(55, 13);
	printf("    ��ʼ��ı���		   \n");
	gotoxy(55, 16);
	printf("--->�����ⳡ��Ϸ		   \n");
	gotoxy(45, 20);
	printf("====================================\n");
}

void print_name()
{
	gotoxy(55, 13);
	printf("�������������:");
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
	printf("��ӭ, %s !", name);

	gotoxy(83, 15);
	printf("���ĳɼ���:%d ", sorce);

	gotoxy(83, 20);
	printf("��Ϸ����:AustinYANyh");
}

void PrintSnake()
{
	head = (snake*)malloc(sizeof(snake));
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
	//�ж��������foodλ���Ƿ����ߵ������غ�
	while (1)
	{
		if (judge->next == NULL)
		{
			break;
		}
		if (food.x == judge->x && food.y == judge->y)//x yȷ��һ��λ��.�˴���&&
		{
			goto lable;//�غ����������������
		}
		judge = judge->next;
	}
	gotoxy(food.x, food.y);//����ƶ���food��λ��
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
	//�ѽڵ��ڵ������ȱ�������
	a = p->x;
	b = p->y;

	while (1)
	{
		if (p->next->next == NULL)
		{
			break;
		}
		//��p->next��ֵ�ֱ����c,d֮����a,b����
		c = p->next->x;
		p->next->x = a;
		a = c;

		d = p->next->y;
		p->next->y = b;
		b = d;

		p = p->next;//ѭ��������
	}

	p = head->next;
	if (p->next != NULL)
	{
		p->x = m;//����ͷ�����긳����
		p->y = n;
	}
}

void MovingSnake()
{
	int count = 0;	//�ߵ����峤��
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
		++count;				//����һ���Ȼ����´�ӡһ��,��ɶ�̬Ч��
		p = p->next;
	}

	// up down left right ʹ���ַ�  w s a d ����
	switch (click)
	{
	case up:
			head->y -= 1;//��������������һ���Լ�һ
			UpdateSnake(a, b);
			break;
	case down:
		head->y += 1;//����������������һ
		UpdateSnake(a, b);
		break;
	case left:
		head->x -= 2;//�����ߺ������Լ���
		UpdateSnake(a, b);
		break;
	case right:
		head->x += 2;//�����ߺ�����������
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
	printf("���ķ�����:%d		   \n", sorce);
	gotoxy(47, 16);
	printf("�ý����Ļ�˵,��һ����ϰ��!�ֵ�\n");
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
			if (_kbhit())//���ָ����޸�,�Ͳ���click���¸�ֵ
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
	system("color 0E");//��ɫ��������ɫ����

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
