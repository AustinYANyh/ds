#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


void CountSort(int* array, int size)
{
	//未告知范围的情况下,先找出数据范围

	int minPos = 0;
	int maxPos = 0;

	for (int i = 1; i < size; ++i)
	{
		if (array[minPos]>array[i])
		{
			minPos = array[i];
		}
		if (array[maxPos] < array[i])
		{
			maxPos = array[i];
		}
	}

	int range = maxPos - minPos + 1;

	int* a = (int*)malloc(sizeof(int)*range);
	memset(a, 0, sizeof(int)*range);

	for (int i = 0; i < size; ++i)
	{
		a[array[i]]++;
	}
	
	int count = 0;

	for (int j = 0; j < size; ++j)
	{
		while (a[j]--)
		{
			array[count++]=j;
		}
	}

	free(a);
	a = NULL;
}

void PrintAll(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}

int main()
{
	int array[] = { 0, 1, 5, 3, 3, 4, 2, 5, 0, 9 };
	CountSort(array, sizeof(array) / sizeof(array[0]));

	PrintAll(array, sizeof(array) / sizeof(array[0]));
	system("pause");
	return 0;
}
