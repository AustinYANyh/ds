#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

typedef int Datatype;

typedef struct DlistNode 
{
	Datatype data;
	struct DlistNode* _next;
	struct DlistNode* _prev;

}Node,*pNode;

pNode _head ;
 
void DlistInit(pNode *_head)
{
	assert(_head);
	*_head = (pNode)malloc(sizeof(Node));
	if (*_head == NULL)
	{
		assert(0);
		return ;
	}
	(*_head)->_next = *_head;
	(*_head)->_prev = *_head;
}

pNode BuyDListNode(Datatype data)
{
	pNode pnewNode = (pNode)malloc(sizeof(Node));
	if (pnewNode == NULL)
	{
		return 0;
	}
	pnewNode->_next = NULL;
	pnewNode->_prev = NULL;
	pnewNode->data = data;
	return pnewNode;
}

void DlistPushfront(pNode _head,Datatype data)
{
	assert(_head);
	pNode node = BuyDListNode(data);
	node->_prev = _head;
	node->_next = _head->_next;
	_head->_next = node;
	_head->_next->_prev = node;
}

void DlistPopfront(pNode _head)
{
	assert(_head);
	if (_head->_next == _head)
	{
		return;
	}
	pNode delnode = _head->_next;
	delnode->_next->_prev = _head;
	_head->_next = delnode->_next;
	free(delnode);
}

void DlistPushback(pNode _head,Datatype data)
{
	assert(_head);
	pNode node = NULL;
	node=BuyDListNode(data);
	node->_prev = _head->_prev;
	node->_next = _head;
	_head->_prev->_next = node;
	_head->_prev = node;
}

void DlistPopback(pNode _head)
{
	assert(_head);
	if (_head->_next == _head)
	{
		return;
	}
	pNode delnode = _head->_prev;
	delnode->_prev->_next = _head;
	_head->_prev = delnode->_prev;
	free(delnode);
}

int DlistFind(pNode _head)
{
	assert(_head);
	pNode pCur = _head;
	int count = 0;
	while (pCur->_next != _head)
	{
		++count;
		pCur = pCur->_next;
	}
	return count;
}

pNode DlistFindpos(pNode _head,int data)
{
	assert(_head);
	pNode pCur = _head;
	int count = 0;
	while (pCur->_next != _head)
	{
		if (count == data)
		{
			return pCur;
		}
		++count;
		pCur = pCur->_next;
	}
	return NULL;
}

void DListInsert(pNode pos, Datatype data)
{
	assert(pos);
	pNode node = BuyDListNode(data);
	node->_next = pos;
	node->_prev = pos->_prev;
	pos->_prev = node;
	node->_prev->_next = node;
}

void DListErase(pNode pos)
{
	assert(pos);
	pos->_next->_prev = pos->_prev;
	pos->_prev->_next = pos->_next;
	free(pos);
}


void DListClear(pNode pHead)
{
	assert(_head);
	pNode pCur = _head->_next;
	while (pCur != _head)
	{
		_head->_next = pCur->_next;
		pCur->_next->_prev = _head;
		free(pCur);
		pCur = _head->_next;
		if (pCur == _head)
		{
			_head->_next = _head;
			_head->_prev = _head;
		}
	}
}
void DListDestroy(pNode* _head)
{
	DListClear(*_head);
	free(*_head);
	*_head = NULL;
}

void DlistPrint(pNode _head)
{
	assert(_head);
	if (_head->_next == _head)
	{
		printf("Head\n");
	}
	else
	{
		pNode pCur = _head->_next;
		while (pCur != _head)
		{
			printf("%d--->", pCur->data);
			pCur = pCur->_next;
		}
		if (pCur == _head)
		{
			printf("Head\n");
		}
	}
}

void TestDlist()
{
	DlistInit(&_head);

	//尾插测试
	DlistPushback(_head, 1);
	DlistPushback(_head, 2);
	DlistPushback(_head, 3);
	DlistPrint(_head);

	//头插测试
	DlistPushfront(_head, 0);
	DlistPushfront(_head, 7);
	DlistPushfront(_head, 9);
	DlistPrint(_head);

	//头删测试
	DlistPopfront(_head);
	DlistPopfront(_head);
	DlistPopfront(_head);
	DlistPrint(_head);

	//尾删测试
	DlistPopback(_head);
	DlistPopback(_head);
	DlistPopback(_head);
	DlistPrint(_head);

#if(0)
	//查找节点的个数(头不算)
	DlistFind(_head);
	printf("当前节点个数:%d\n", DlistFind(_head));

	DlistPushfront(_head, 0);
	DlistPushfront(_head, 7);
	DlistPushfront(_head, 9);
	DlistPrint(_head);
	printf("当前节点个数:%d\n", DlistFind(_head));

	DlistFindpos(_head, 2);//查找第二个节点的位置
	printf("%p\n", DlistFindpos(_head, 2));
#endif

 	//Head
 	DListInsert(_head->_next, 2);
 	DlistPrint(_head);
 	// 2--->Head
 	DListInsert(_head->_next->_next, 3);
 	DlistPrint(_head);
 	//
 	DListInsert(_head->_next, 1);
 	DlistPrint(_head);

//  	DlistPushfront(_head, 0);
//  	DlistPushfront(_head, 7);
//  	DlistPushfront(_head, 9); 
//  	DlistPrint(_head);

	//在第二个节点插入27
	pNode pos = DlistFindpos(_head, 2);
	printf("%p\n", pos);
	DListInsert(pos, 27);
	DlistPrint(_head);

	pNode pos2 = DlistFindpos(_head, 2);
	DListInsert(pos2, 58);
	DlistPrint(_head);

	//清除第二个节点
	pNode pos3 = DlistFindpos(_head, 2);
	DListErase(pos3);
	DlistPrint(_head);

	//清空链表
// 	DListClear(_head);
// 	DlistPrint(_head);

	//销毁链表
// 	DListDestroy(&_head);
// 	DlistPrint(_head);

}     

int main()
{
	TestDlist();
   system("pause");
   return 0;
}