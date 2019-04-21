#include <stdio.h>
#include <stdlib.h>
// ��̬��˳��� 
typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	int _capacity; // ˳�����ܴ�С 
	int _size; // ˳�������ЧԪ�صĸ��� 
}SeqList, *PSeq;

//typedef struct SeqList SeqList; 
//typedef struct SeqList* PSeqList; 

// ˳���ĳ�ʼ�� 
void SeqListInit(PSeq ps, int capacity)
{
	ps->_capacity= capacity;
	ps->_size = 0;
	ps->_array = (DataType*)malloc(ps->_capacity, sizeof(int));
}

// ��˳����β������ֵΪdata��Ԫ�� 
void SeqListPushBack(PSeq ps, DataType data)
{
	ps->_array[ps->_size] = ps->_array[data];
	++ps->_size;
}

// ɾ��˳������һ��Ԫ�� 
void SeqListPopBack(PSeq ps)
{
	--ps->_size;
}

// ��˳����ͷ������ֵΪdata��Ԫ�� 
void SeqListPushFront(PSeq ps, DataType data)
{
	for (int i = ps->_size - 1; i >= 0; ++i)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	ps->_array[0] = ps->_array[data];
	++ps->_size;
}

// ɾ��˳���ͷ����Ԫ�� 
void SeqListPopFront(PSeq ps)
{
	for (int i = 0; i < ps->_size - 1; ++i)
	{
		ps->_array[i] = ps->_array[i+1];
	}
	--ps->_size;
}

// ��˳���posλ�ò���ֵΪdata��Ԫ�� 
void SeqListInsert(PSeq ps, int pos, DataType data)
{
	for (int i = pos - 1; i < ps->_size;++i)
	{
		ps->_array[pos] = ps->_array[pos-1];
	}
	ps->_array[pos - 1] = ps->_array[data];
	++ps->_size;
}

// ɾ��˳�����posλ���ϵ�Ԫ�� 
void SeqListErase(PSeq ps, int pos)
{
	for (int i = pos - 1; i < ps->_size; ++i)
	{
		ps->_array[pos-1] = ps->_array[pos];
	}
}

// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е��±꣬���򷵻�-1 
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

// ���˳����Ƿ�Ϊ�գ����Ϊ�շ��ط�0ֵ���ǿշ���0 
int SeqListEmpty(PSeq ps)
{
	if (ps->_size == 0)
	{
		return -1;
	}
	return 0;
}

// ����˳�������ЧԪ�صĸ��� 
int SeqListSize(PSeq ps)
{
	return ps->_size;
}

// ����˳����������С 
int SeqListCapacity(PSeq ps)
{
	return ps->_capacity;
}

// ��˳����е�Ԫ����� 
void SeqListClear(PSeq ps)
{
	ps->_size = 0;
}

// ɾ��˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeq ps, DataType data)
{
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] = data)
		{
			for (i; i < ps->_size; ++i)
			{
				ps->_array[i] = ps->_array[i+1];
			}
		}
	}
}

// ����˳��� 
void SeqListDestroy(PSeq ps)
{
	ps->_size = 0;
	ps->_capacity = 0;
}

// ˳�������� 
void CheckCapacity(PSeq ps);

int main()
{
	SeqListInit(PSeq ps, int capacity);
	system("pause");
	return 0;
}