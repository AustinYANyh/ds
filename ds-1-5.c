#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ��̬��˳��� 
typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	int _capacity; // ˳�����ܴ�С 
	int _size; // ˳�������ЧԪ�صĸ��� 
}SeqList, *PSeq;

// ˳���ĳ�ʼ�� 
void SeqListInit(PSeq ps, int capacity)
{
	ps->_array = (DataType*)malloc(capacity*sizeof(DataType));
	if (ps->_array==NULL)
	{
		exit(EXIT_FAILURE);
	}
	ps->_capacity = capacity;
	ps->_size = 0;
}

// ����˳��� 
void SeqListDestroy(PSeq ps)
{
	if (ps->_array != NULL)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_size = 0;
		ps->_capacity = 0;
	}
}

// ˳�������� 
void CheckCapacity(PSeq ps)
{
	if (ps->_size == ps->_capacity)
	{
		int newCapacity = ps->_capacity * 2;
		int* pemp = (DataType*)malloc(newCapacity*sizeof(DataType));
		if (pemp == NULL)
		{
			return;
		}
		for (int i = 0; i < ps->_size; ++i)
		{
			pemp[i] = ps->_array[i];
		}
		free(ps->_array);
		ps->_array = pemp;
		ps->_capacity = newCapacity;
	}
}

// ��˳����β������ֵΪdata��Ԫ�� 
void SeqListPushBack(PSeq ps, DataType data)
{
	//���˳�������
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	++ps->_size;
}

// ɾ��˳������һ��Ԫ�� 
void SeqListPopBack(PSeq ps)
{
	if (SeqListEmpty(ps))
	{
		return;
	}
	--ps->_size;
}

// ��˳����ͷ������ֵΪdata��Ԫ�� 
void SeqListPushFront(PSeq ps, DataType data)
{
	//���˳�������
	CheckCapacity(ps);
	for (int i = ps->_size - 1; i >= 0; --i)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[0] = data;
	++ps->_size;
}

// ɾ��˳���ͷ����Ԫ�� 
void SeqListPopFront(PSeq ps)
{
	if (SeqListEmpty(ps))
	{
		return;
	}
	for (int i = 0; i < ps->_size - 1; ++i)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	--ps->_size;
}

// ��˳���posλ�ò���ֵΪdata��Ԫ�� 
void SeqListInsert(PSeq ps, int pos, DataType data)
{
	CheckCapacity(ps);
	for (int i = ps->_size - 1; i >=pos -1; --i)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos - 1] = data;
	++ps->_size;
}

// ɾ��˳�����posλ���ϵ�Ԫ�� 
void SeqListErase(PSeq ps, int pos)
{
	for (int i = pos; i <=ps->_size- 1; ++i)
	{
		ps->_array[i-1] = ps->_array[i];
	}
	--ps->_size;
}

// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е��±꣬���򷵻�-1 
int SeqListFind(PSeq ps, DataType data)
{
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == data)
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
		if (ps->_array[i] == data)
		{
			for (i; i < ps->_size; ++i)
			{
				ps->_array[i] = ps->_array[i + 1];
			}
		}
	}
	--ps->_size;
}


void SeqListPrint(PSeq ps)
{
	for (int i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void TestSeqlist()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1); 
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 10);
	SeqListPrint(&s);
	printf("size=%d capacity=%d \n", SeqListSize(&s), SeqListCapacity(&s));
	SeqListPushBack(&s, 11);
	printf("size=%d capacity=%d \n", SeqListSize(&s), SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListInsert(&s, 1, 1);
	SeqListPrint(&s);
	SeqListErase(&s, 3);
	SeqListPrint(&s);

	SeqListFind(&s, 4);
	printf("�±�:%d\n", SeqListFind(&s, 4));

	SeqListRemove(&s, 1);
	SeqListPrint(&s);
}

int main()
{
	TestSeqlist();

	system("pause");
	return 0;
}