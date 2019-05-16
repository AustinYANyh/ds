#include "queue.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

QNode* BuyNode(QDataType data)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		assert(0);
	}
	newnode->_data = data;
	newnode->_pNext = NULL;
	return newnode;
}

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* node = BuyNode(data);
	if (q->_front == NULL )
	{
		q->_front = q->_back = node;
	}
	else
	{
		q->_back->_pNext = node;
		q->_back = node;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
	{
		return;
	}
	QNode* newhead = q->_front;
	//队列中只有一个元素
	if (q->_front->_pNext == NULL)
	{
		q->_front = q->_back = NULL;
	}
	else
	{
		q->_front = newhead->_pNext;
		free(newhead);
		newhead = NULL;
	}
}

QDataType QueueFront(Queue* q)
{
	if (q->_front == NULL)
	{
		return -1;
	}
	return q->_front->_data;
}

QDataType QueueBack(Queue* q)
{
	if (q->_front == NULL)
	{
		return -1;
	}
	return q->_back->_data;
}

int QueueSize(Queue* q)
{
	QNode* pCur = q->_front;
	int count = 0;
	while (pCur != NULL)
	{
		pCur = pCur->_pNext;
		count++;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
	{
		return -1;
	}
	return 1;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
	{
		return;
	}
	QNode* pCur = q->_front;
	while (pCur != NULL)
	{
		q->_front= pCur->_pNext;
		free(pCur);
		pCur = NULL;
		pCur = q->_front;
	}

	q->_front = q->_back = NULL;
}

void QueueTest()
{
	Queue s;
	QueueInit(&s);
	QueuePush(&s, 1);
	QueuePush(&s, 2);
	QueuePush(&s, 3);
	QueuePush(&s, 4);

	QueuePop(&s);
	QueuePop(&s);
	QueuePop(&s);

	printf("size=%d\n",QueueSize(&s));

}

int main()
{
	QueueTest();
	return 0;
}

