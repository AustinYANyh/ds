#include "sort.h"
#include <stdio.h>
#include "stack.h"
#include <malloc.h>
#include <assert.h>
#include <memory.h>


void insertSort(int* array, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = array[i];
		int end = i - 1;

		while (key < array[end] && end >= 0)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}

void shellSort(int* array, int size)
{
	int gap = size;

	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = gap; i < size; ++i)
		{
			int key = array[i];
			int end = i - gap;

			while (key < array[end] && end >= 0)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		//gap--;
	}
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectSort(int* array, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int maxPos = 0;

		for (int j = 1; j < size-i; ++j)
		{
			if (array[j]>array[maxPos])
			{
				maxPos = j;
			}
		}

		if (maxPos != size - i - 1)
		{
			swap(&array[maxPos], &array[size - i - 1]);
		}
	}
}

void selectSort2(int* array, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int begin = 0;
		int end = size - 1;

		while (begin < end)
		{
			int maxPos = begin;
			int minPos = begin;
			int index = begin + 1;

			while (index <= end)
			{
				if (array[index]>array[maxPos])
				{
					maxPos = index;
				}
				if (array[index] < array[minPos])
				{
					minPos = index;
				}

				++index;
			}

			if (maxPos != end)
			{
				swap(&array[maxPos], &array[end]);
			}

			//小元素如果刚好在end的位置,maxpos和end交换过之后,minpos的位置变到maxpos位置
			if (minPos == end)
			{
				minPos = maxPos;
			}

			if (minPos != begin)
			{
				swap(&array[minPos], &array[begin]);
			}

			begin++;
			end--;
		}
	}
}

void HeapAdjust(int* array, int size, int parent)
{
	int child = parent * 2 + 1; 

	while (child < size)	
	{		
		// 找左右孩子中较大的孩子		
		if (child + 1 < size && array[child + 1] > array[child])
		{
			child += 1;
		}
		
		if (array[child] > array[parent])		
		{		
			swap(&array[child], &array[parent]);	
			parent = child;			
			child = parent * 2 + 1;		
		}	
		else	
		{			
			return;	
		}	
	}
} 

void HeapSort(int* array, int size)
{	
	//建堆	
	int root = ((size - 1) >> 1);

	for (root; root >= 0; --root)	
	{		
		HeapAdjust(array, size, root);	
	} 
	//排序
	int end = size - 1;	
	
	while (end != 0)	
	{		
		swap(&array[0], &array[end]);	
		HeapAdjust(array, end, 0);	
		end--;	
	}
}

void BubbleSort(int* array, int size)
{
	int i = 0;
	int j = 0;
	for (i; i < size; ++i)
	{
		for (j=size-1; j >i ; --j)
		{
			if (array[j - 1] > array[j])
			{
				swap(&array[j - 1], &array[j]);
			}
		}
	}
}

int GetMiddleIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);

	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
		{
			return left;
		}
		else if (array[mid]>array[right - 1])
		{
			return right - 1;
		}
		else
		{
			return mid;
		}
	}
	else
	{
		if (array[mid] > array[left])
		{
			return left;
		}
		else if (array[mid] < array[right - 1])
		{
			return right - 1;
		}
		else
		{
			return mid;
		}
	}
}

int partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right-1;

	int mid = GetMiddleIndex(array, left, right);
	swap(&array[mid], &array[right - 1]);

	int key = array[right - 1];

	while (begin < end)
	{
		while (array[begin] <= key && begin < end)
		{
			begin++;
		}
		while (array[end] >= key && begin < end)
		{
			end--;
		}

		if (begin != end)
		{
			swap(&array[begin], &array[end]);
		}
	}

	//放好基准值

	//这里必须和right-1比较,因为end是会动的
	if (begin != right-1)
	{
		swap(&array[begin], &array[right-1]);
	}

	return begin;
}

int partion2(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;

	int mid = GetMiddleIndex(array, left, right);
	swap(&array[mid], &array[right - 1]);

	int key = array[right - 1];

	while (begin < end)
	{
		//从前往后找比基准值大的元素
		while (array[begin] < key && begin < end)
		{
			begin++;
		}

		//填充最后的end位置
		if (begin<end)
		{
			array[end] = array[begin];
			end--;
		}

		//从后往前找比基准值小的元素
		while (array[end] > key && begin < end)
		{
			end--;
		}

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}
	array[begin] = key;
	return begin;
}

int partion3(int* array, int left, int right)
{
	int cur = left;
	int pre = cur - 1;

	int mid = GetMiddleIndex(array, left, right);
	swap(&array[mid], &array[right - 1]);

	int key = array[right - 1];

	while (cur < right)
	{
		//cur标记的元素比基准值小,并且pre走一步不和cur相同,说明中间的都比基准值大,交换
		//cur标记的元素比基准值大,cur继续走,但是pre是不动的,pre走和cur标记的比基准值小同步
		if (array[cur] < key && ++pre != cur)
		{
				swap(&array[pre], &array[cur]);
		}
		cur++;
	}

	//交换的是基准值位置的值,不是和key保存的值交换
	if ((pre + 1) != right)
	{
		swap(&array[pre + 1], &array[right - 1]);
	}

	return pre + 1;
}

void QuickSort(int* array, int left,int right)
{
	//元素个数最少一个
	if (right - left > 1)
	{
		//int div = partion1(array, left, right);
		//int div = partion2(array, left, right);
		int div = partion3(array, left, right);

		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

void QucikSortNor(int* array, int size)
{
	int left = 0;
	int right = size;

	Stack s;
	StackInit(&s);

	//栈的特性是先入后出,所以反过来压入元素,出栈的顺序就是对的
	StackPush(&s, right);
	StackPush(&s, left);

	//栈若不空,就对左右部分继续分别分组
	while (StackEmpty(&s) != -1)
	{
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = partion3(array, left, right);

			StackPush(&s, right);
			StackPush(&s, div + 1);
			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
}

void MergeData(int* array, int left, int mid, int right,int* tmp)
{
	int begin1 = left;
	int end1 = mid;

	int begin2 = mid;
	int end2 = right;

	int index = left;

	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] < array[begin2])
		{
			tmp[index] = array[begin1];
			begin1++;
			index++;
		}
		else
		{
			tmp[index] = array[begin2];
			begin2++;
			index++;
		}
	}

	//长短不一样的情况,单独处理
	while (begin1 < end1)
	{
		tmp[index] = array[begin1];
		index++;
		begin1++;
	}
	while (begin2 < end2)
	{
		tmp[index] = array[begin2];
		index++;
		begin2++;
	}
}

//类似后序遍历

void _MergeSort(int* array, int left, int right,int* tmp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);

		_MergeSort(array, left, mid,tmp);
		_MergeSort(array, mid, right,tmp);

		MergeData(array, left, mid, right,tmp);

		memcpy(array+left, tmp+left, sizeof(int)*(right - left));
	}
}

void MergeSort(int* array, int size)
{
	int* tmp = (int*)malloc(sizeof(int)*size);

	if (tmp == NULL)
	{
		assert(0);
	}
	_MergeSort(array, 0, size, tmp);

	free(tmp);
	tmp = NULL;
}

void MergeSortNor(int* array, int size)
{
	int* tmp = (int*)malloc(sizeof(int)*size);

	if (tmp == NULL)
	{
		assert(0);
	}
	int gap = 1;

	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			if (right >= size)
			{
				right = size;
			}

			if (mid >= size)
			{
				mid = size;
			}

			MergeData(array, left, mid, right, tmp);
		}

		memcpy(array, tmp, sizeof(int)*size);
		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}

void PrintAll(int* array,int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = { 0, 1, 9, 5, 3, 8, 6, 7, 25 };

	int size = sizeof(a) / sizeof(a[0]);

	//insertSort(a,sizeof(a)/sizeof(a[0]));

	//shellSort(a, sizeof(a) / sizeof(a[0]));

	//selectSort(a, sizeof(a) / sizeof(a[0]));

	//selectSort2(a, sizeof(a) / sizeof(a[0]));

	//BubbleSort(a, sizeof(a) / sizeof(a[0]));
	//PrintAll(a, size);

	//QuickSort(a, 0, sizeof(a) / sizeof(a[0]));
	//PrintAll(a, size);

	//QucikSortNor(a, sizeof(a) / sizeof(a[0]));
	//PrintAll(a, size);

	//MergeSort(a, sizeof(a) / sizeof(a[0]));
	//PrintAll(a, size);

	MergeSortNor(a, sizeof(a) / sizeof(a[0]));
	PrintAll(a, size);

	system("pause");
	return 0;
}