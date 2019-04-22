#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

//int main()
//{
//	int arr[10] = { 1, 6, 7, 9, 2, 7, 9, 1, 5, 6 };
//	int sum = 0;
//	for (int i = 0; i < 10; ++i)
//	{
//		sum ^= arr[i];
//	}
//	int pos = 0;
//	int num1 = 0;
//	int num2 = 0;
//	for (int i = 0; i < 32; ++i)
//	{
//		if (sum & 1 << i)
//		{
//			pos = i;
//			break;
//		}
//	}
//	for (int i = 0; i < 10; ++i)
//	{
//		if (arr[i] & 1 << pos)
//		{
//			num1 ^= arr[i];
//		}
//		else
//		{
//			num2 ^= arr[i];
//		}
//	}
//	printf("%d %d", num1, num2);
//	system("pause");
//	return 0;
//}

#define and &&

char * Strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	if (*str2 == '\0')
	{
		return NULL;
	}
	char *chazhao = (char*)str1;
	char *zichuan = (char*)str2;
	while (*chazhao != '\0')
	{
		char *panduan = chazhao;
		while (*zichuan == *panduan and *zichuan != '\0' and *panduan != '\0')
		{
			panduan++;
			zichuan++;
		}
		if (*zichuan == '\0')
		{
			return chazhao;
		}
		++chazhao;
	}
}
//
//int main()
//{
//		char str1[1024] = "wuyiqunawan";
//		char str2[1024] = "quna";
//		Strstr(str1, str2);
//		printf("%p ", str1);
//		printf("%p ", Strstr(str1, str2));
//	system("pause");
//	return 0;
//}


//数组中的奇数放在后面,偶数放在前面

void Sort(int arr[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] % 2 != 0)
		{
			int tmp = arr[i];
			arr[i] = arr[size - 1];
			arr[size - 1] = tmp;
			size--;
			i--;
		}
		else
		{
			continue;
		}
	}
}

void sort(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[j-1] >arr[j]) //注意边界问题
			{
				int tmp;
				tmp = arr[j];
				arr[j ] = arr[j-1];
				arr[j - 1] = tmp;
			}
		}
	}
}

//int main()
//{
//	int arr[10] = { 6, 8, 1, 3, 4, 7, 2, 9, 15, 17 };
//	Sort(arr, 10);
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//	sort(arr, 10);
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}

typedef struct LL
{
	char name[1024];
	char age[1024];
	char sex[1024];
}LL;

typedef struct Wozhisuoai
{
	LL ll[1];
	int size;
}Wa;

Wa _wa;

void init()
{
	_wa.size = 0;
	_wa.ll[0].name[0] = '\0';
	_wa.ll[0].age[0] = '\0';
	_wa.ll[0].sex[0] = '\0';
}

void add(ll)
{
	printf("请输入最爱的人的姓名: ");
	scanf("%s", _wa.ll[0].name);
	printf("请输入最爱的人的年龄: ");
	scanf("%s", _wa.ll[0].age);
	printf("请输入最爱的人的性别: ");
	scanf("%s", _wa.ll[0].sex);
	_wa.size++;
	return;
}

void print(ll)
{
	for (int i = 0; i < _wa.size; ++i)
	{
		printf("%s\t%s\t%s\t", _wa.ll[i].name, _wa.ll[i].age, _wa.ll[i].sex);
	}
	printf("\n");
}

int menu()
{
		printf("========\n");
		printf("1.新增\n");
		printf("2.给我打\n");
		printf("0.没了\n");
		printf("========\n");
		int choice = 0;
		scanf("%d", &choice);
		return choice;
}

int main()
{
	init();
	while (1)
	{
		int choice = menu();
		if (choice == 1)
		{
			add();
		}
		if (choice == 2)
		{
			print();
		}
		if (choice == 0)
		{
			printf("走好");
			return 0;
		}
	}
	system("pause");
	return 0;
}