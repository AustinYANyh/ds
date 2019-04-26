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
	
	 pNode node = buynode(data);
	 node->_next = s->_head;
	 s->_head = node;
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
	slistPrint(&s);

}

int main()
{
	testlist();
   system("pause");
   return 0;
}