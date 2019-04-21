#include <stdio.h>
#include <stdlib.h>
// 动态的顺序表 
typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	int _capacity; // 顺序表的总大小 
	int _size; // 顺序表中有效元素的个数 
}SeqList, *PSeq;

//typedef struct SeqList SeqList; 
//typedef struct SeqList* PSeqList; 

// 顺序表的初始化 
void SeqListInit(PSeq ps, int capacity)
{
	ps->_capacity = capacity;
	ps->_size = 0;
	ps->_array = (DataType*)malloc(ps->_capacity, sizeof(int));
}

// 在顺序表的尾部插入值为data的元素 
void SeqListPushBack(PSeq ps, DataType data)
{
	ps->_array[ps->_size] = ps->_array[data];
	++ps->_size;
}

// 删除顺序表最后一个元素 
void SeqListPopBack(PSeq ps)
{
	--ps->_size;
}

// 在顺序表的头部插入值为data的元素 
void SeqListPushFront(PSeq ps, DataType data)
{
	for (int i = ps->_size - 1; i >= 0; ++i)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[0] = ps->_array[data];
	++ps->_size;
}

// 删除顺序表头部的元素 
void SeqListPopFront(PSeq ps)
{
	for (int i = 0; i < ps->_size - 1; ++i)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	--ps->_size;
}

// 在顺序表pos位置插入值为data的元素 
void SeqListInsert(PSeq ps, int pos, DataType data)
{
	for (int i = pos - 1; i < ps->_size; ++i)
	{
		ps->_array[pos] = ps->_array[pos - 1];
	}
	ps->_array[pos - 1] = ps->_array[data];
	++ps->_size;
}

// 删除顺序表中pos位置上的元素 
void SeqListErase(PSeq ps, int pos)
{
	for (int i = pos - 1; i < ps->_size; ++i)
	{
		ps->_array[pos - 1] = ps->_array[pos];
	}
}

// 在顺序表中查找值为data的元素，找到返回该元素在顺序表中的下标，否则返回-1 
int SeqListFind(PSeq ps, DataType data)
{
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] = data)
		{
			return i;
		}
	}
	return -1;
}

// 检测顺序表是否为空，如果为空返回非0值，非空返回0 
int SeqListEmpty(PSeq ps)
{
	if (ps->_size == 0)
	{
		return -1;
	}
	return 0;
}

// 返回顺序表中有效元素的个数 
int SeqListSize(PSeq ps)
{
	return ps->_size;
}

// 返回顺序表的容量大小 
int SeqListCapacity(PSeq ps)
{
	return ps->_capacity;
}

// 将顺序表中的元素清空 
void SeqListClear(PSeq ps)
{
	ps->_size = 0;
}

// 删除顺序表中第一个值为data的元素 
void SeqListRemove(PSeq ps, DataType data)
{
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] = data)
		{
			for (i; i < ps->_size; ++i)
			{
				ps->_array[i] = ps->_array[i + 1];
			}
		}
	}
}

// 销毁顺序表 
void SeqListDestroy(PSeq ps)
{
	ps->_size = 0;
	ps->_capacity = 0;
}

// 顺序表的扩容 
void CheckCapacity(PSeq ps);


int main()
{
	SeqListInit(PSeq ps, 10);
	system("pause");
	return 0;
}