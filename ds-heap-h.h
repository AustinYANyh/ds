#pragma once

typedef int HPDataType;

typedef int(*PCom)(HPDataType, HPDataType);

typedef struct Heap
{
	HPDataType* _array;
	int _capacity;
	int _size;
	PCom compare;
}Heap;

// �������ʼ���� 
void InitHeap(Heap* hp, HPDataType* array, int size,PCom compare);

// ��ʼ��һ���ն� 
void InitEmptyHeap(Heap* hp, int capacity, PCom compare);

// �ڶ��в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, HPDataType data);

// ɾ���Ѷ�Ԫ�� 
void EraseHeap(Heap* hp);

// ��ȡ������ЧԪ�ظ��� 
int HeapSize(Heap* hp);

// �����Ƿ�Ϊ�ն� 
int HeapEmpty(Heap* hp);

// ��ȡ�Ѷ�Ԫ�� 
HPDataType HeapTop(Heap* hp);

// ���ٶ� 
void DestroyHeap(Heap* hp);

//�������
void CheckCapacity(Heap* hp);