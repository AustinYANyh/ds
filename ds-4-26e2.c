#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

typedef int datatype;

typedef struct slistnode
{ 
	datatype _data;
	struct slistnode* _next;
}node,*pNode;

typedef struct slist
{
	node* _head;
}slist;

void slistInit(slist* s)
{
	assert(s);
	s->_head = NULL;
}


node* buynode(datatype data)
{
	pNode node = (pNode*)malloc(sizeof(node));
	node->_data = data;
	node->_next = NULL;
	return node;
}

void slistPushfront(slist* s,datatype data)
{
	assert(s);
	 pNode node = buynode(data);
	 node->_next = s->_head;
	 s->_head = node;
}

void slistPopfront(slist* s)
{
	s->_head = s->_head->_next;
}

void slistPushback(slist* s,datatype data)
{
	assert(s);
	pNode node = buynode(data);
	node->_next = NULL;
	pNode pCur = s->_head;
	while (pCur->_next != NULL)
	{
		pCur = pCur->_next;
	}
	pCur->_next = node;
}

void slistPopback(slist* s)
{
	assert(s);
	pNode node = s->_head;
	while (node->_next->_next != NULL)
	{
		node = node->_next;
	}
	node->_next = NULL;
}

void slistPospush(node* pos,datatype data)
{
	assert(pos);
	pNode node = buynode(data);
	node->_next = pos->_next;
	pos->_next = node;
}

node* slistFind(slist* s,datatype data)
{
	pNode pCur = s->_head;
	while (pCur->_next != NULL)
	{
		if (pCur->_data == data)
		{
			return pCur;
		}
		pCur = pCur->_next;
	}
}

node* slistFindPos(slist* s, datatype data)
{
	pNode pCur = s->_head;
	int count = 1;
	while (pCur->_next != NULL)
	{
		if (data == count)
		{
			return pCur;
		}
		count++;
		pCur = pCur->_next;
	}
}

void slistPrint(slist* s)
{
	pNode pCur = s->_head;
	while (pCur != NULL)
	{
		printf("%d--->", pCur->_data);
		pCur = pCur->_next;
	}
	printf("NULL\n");
}

void testlist()
{
	slist s;
	slistInit(&s);
	slistPushfront(&s, 1);
	slistPushfront(&s, 4);
	slistPushfront(&s, 7);
	slistPushfront(&s, 1);
	slistPushfront(&s, 1);  
	slistPrint(&s);	//1 1 7 4 1

	slistPopfront(&s);
	slistPopfront(&s);
	slistPopfront(&s);
	slistPrint(&s);	// 4  1

	slistPushback(&s, 1);
	slistPushback(&s, 2);
	slistPushback(&s, 3);
	slistPrint(&s);	// 4  1  1  2  3 

	slistPopback(&s);
	slistPopback(&s);
	slistPopback(&s);
	slistPrint(&s);	// 4  1

	slistFind(&s, 4);
	printf("%p\n", slistFind(&s, 4));//查找数值为4的节点位置

	slistFindPos(&s, 1);
	printf("%p\n", slistFindPos(&s, 1));//查找第1个节点的位置

	slistPushback(&s, 1);
	slistPrint(&s);	// 4  1  1

	//在第二个节点后插入5
	slistPospush(slistFindPos(&s, 2), 5);
	slistPrint(&s);

}

int main()
{
	testlist();
   system("pause");
   return 0;
}