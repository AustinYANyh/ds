#include "heap.h"
#include<stdio.h>
#include <assert.h>
#include <malloc.h>


void swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int less(HPDataType a, HPDataType b)
{
	return a<b;
}

int Greater(HPDataType a, HPDataType b)
{
	return a>b;
}

void AdjustDown(HPDataType* a, int size, int parent, PCom compare)
{
	int child = parent * 2 + 1;

	//��˫���н�С�ĺ���
	while (child < size)
	{
		//���뱣֤�Һ��Ӵ���
		if (child + 1 < size && compare(a[child + 1] , a[child]))
		{
			child += 1;
		}

		if (compare(a[child] , a[parent]))
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void AdjustUp(HPDataType* a, int size, int child,PCom compare)
{
	int parent = (child - 1) / 2;

	while (child != 0)
	{
		if (compare(a[child] , a[parent]))
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			return;
		}
	}
}

void InitHeap(Heap* hp, HPDataType* a, int size,PCom compare)
{
	assert(hp);
	//�Ѹ��������е�Ԫ�ض�����������,size�����鳤��
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	hp->_capacity = size;
	hp->_size = 0;
	for (int i = 0; i < size; ++i)
	{
		hp->_array[i] = a[i];
	}
	hp->_size = size;

	hp->compare = compare;
	int lastleaf = ((size - 2) >> 1);
	//����0Ҳ��Ҫ������
	while (lastleaf >= 0)
	{
		AdjustDown(hp->_array, size, lastleaf,hp->compare);
		lastleaf--;
	}
}


void InitEmptyHeap(Heap* hp, int capacity);


void InsertHeap(Heap* hp, HPDataType data)
{
	assert(hp);
	CheckCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	AdjustUp(hp->_array, hp->_size, hp->_size - 1,hp->compare);
}


void EraseHeap(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
	{
		return;
	}
	//�ѶѶ�Ԫ�غ����һ��Ԫ�ػ���,Ȼ��size--;�����ϵ���
	swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_array, hp->_size, 0,hp->compare);
}


int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		int newcapacity = hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)malloc(sizeof(HPDataType)*newcapacity);
		if (tmp == NULL)
		{
			return;
		}
		for (int i = 0; i < hp->_size; ++i)
		{
			tmp[i] = hp->_array[i];
		}

		//�ͷžɿռ�
		free(hp->_array);
		hp->_array = tmp;
		hp->_capacity = newcapacity;
	}
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
	{
		return -1;
	}
	return 1;
}


HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
	{
		return -1;
	}
	return hp->_array[0];
}

void DestroyHeap(Heap* hp)
{
	assert(hp);
	if (hp->_array != NULL)
	{
		free(hp->_array);
		hp->_array = NULL;
		hp->_size = 0;
		hp->_capacity = 0;
	}
}

void HeapTest()
{
	Heap hp;
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	InitHeap(&hp, a, sizeof(a) / sizeof(a[0]),less);

   	printf("size=%d\n", HeapSize(&hp));
	printf("�Ѷ�:%d\n", HeapTop(&hp));

	EraseHeap(&hp);
	printf("ɾ���Ѷ�Ԫ�سɹ�!\n");


	printf("size=%d\n", HeapSize(&hp));
	printf("�Ѷ�:%d\n", HeapTop(&hp));

	InsertHeap(&hp, 13);
	printf("����Ԫ�سɹ�!\n");

	printf("size=%d\n", HeapSize(&hp));
	printf("�Ѷ�:%d\n", HeapTop(&hp));

	InsertHeap(&hp, 0);
	printf("����Ԫ�سɹ�!\n");

	printf("size=%d\n", HeapSize(&hp));
	printf("�Ѷ�:%d\n", HeapTop(&hp));

	EraseHeap(&hp);
	printf("ɾ���Ѷ�Ԫ�سɹ�!\n");

	printf("size=%d\n", HeapSize(&hp));
	printf("�Ѷ�:%d\n", HeapTop(&hp));
	//DestroyHeap(&hp);
}

int main()
{
	HeapTest();

	return 0;
}