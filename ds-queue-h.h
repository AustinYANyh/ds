#pragma once

typedef int QDataType;
typedef struct QNode
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front; // 指向队头元素 
	QNode* _back; // 指向队尾元素 
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestroy(Queue* q);

void QueueTest();