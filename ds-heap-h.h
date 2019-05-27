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

// 用数组初始化堆 
void InitHeap(Heap* hp, HPDataType* array, int size,PCom compare);

// 初始化一个空堆 
void InitEmptyHeap(Heap* hp, int capacity, PCom compare);

// 在堆中插入值为data的元素 
void InsertHeap(Heap* hp, HPDataType data);

// 删除堆顶元素 
void EraseHeap(Heap* hp);

// 获取堆中有效元素个数 
int HeapSize(Heap* hp);

// 检测堆是否为空堆 
int HeapEmpty(Heap* hp);

// 获取堆顶元素 
HPDataType HeapTop(Heap* hp);

// 销毁堆 
void DestroyHeap(Heap* hp);

//检测容量
void CheckCapacity(Heap* hp);