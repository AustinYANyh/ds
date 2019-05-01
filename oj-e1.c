#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

typedef int SLTDatatype;

typedef struct SListNode
{
	SLTDatatype _data;
	struct SListNode* _Next;

}Node,*PNode;

typedef struct SList 
{
	Node* _Head;
}SList;

void SListInit(SList* s)
{
	assert(s);
	s->_Head = NULL;
}

Node* BuySListNode(SLTDatatype data)
{
	PNode node = (PNode*)malloc(sizeof(Node));//给新节点申请内存空间
	assert(node);//检验申请的空间是否成功
	node->_data = data;
	node->_Next = NULL;//把相应的数据存到节点内
	return node;
}

void SListPushFront(SList* s,SLTDatatype data)
{
	assert(s);
	PNode node=BuySListNode(data);
	assert(node);
	node->_Next = s->_Head;//顺序不能颠倒,否则会破坏链表结构丢失数据
	s->_Head = node;
}

void SListPopFront(SList* s)
{
	assert(s);
	assert(s != NULL);
	s->_Head = s->_Head->_Next;
}

void SListPushBack(SList* s,SLTDatatype data)
{
	assert(s);
	PNode node = BuySListNode(data);
	node->_Next = NULL;
	PNode pCur = s->_Head;
	while (pCur->_Next!=NULL)
	{
		pCur = pCur->_Next;
	}
	pCur->_Next = node;
}


Node* SListFindPos(SList* s, SLTDatatype data)
{
	assert(s);
	assert(s->_Head != NULL);
	PNode pCur = s->_Head;
	if (data < 1)
	{
		return s->_Head;
	}
	for (int i = 0; i < data-1;++i)
	{
		pCur = pCur->_Next;
	}
	return pCur;
}



void SListRemove(SList* s, SLTDatatype data)
{
	assert(s);
	if (s->_Head == NULL)
	{
		return;
	}
	//if (s->_Head->_Next == NULL)
//	{
	//	if (s->_Head->_data == data)
//		{
//			free(s->_Head);
//			s->_Head = NULL;
//		}
//	}
	else
	{
			PNode pCur = s->_Head;
			while (pCur->_Next != NULL)
			{
				PNode pPre = pCur;//pPre记录的是pCur的上一个
				pCur = pCur->_Next;
				if (pCur->_data == data)
				{
					pPre->_Next = pCur->_Next;
					free(pCur);
					pCur = NULL;
					pCur = pPre;
				}
			}
	}
}

void SListPrint(SList* s)
{
	assert(s);
	if (s->_Head == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		PNode pCur = s->_Head;
		while (pCur != NULL)
		{
			printf("%d--->", pCur->_data);
			pCur = pCur->_Next;
		}
		printf("NULL\n");
	}
}

void TestSList()
{
	SList s;
	SListInit(&s);

	SListPushFront(&s, 1);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 2);
	SListPushBack(&s, 1);
	SListPushBack(&s, 1);//尾插测试

	SListRemove(&s,1);//删除掉值为1的所有节点
	SListPrint(&s);

	//SListSize(&s);
	//printf("有效节点的个数:%d \n", SListSize(&s));

	//SListEmpty(&s);
	//printf("%d\n", SListEmpty(&s));

	//SListClear(&s);
	//SListPrint(&s);

	//SListSize(&s);
	//printf("有效节点的个数:%d \n", SListSize(&s));

	//SListDestroy(&s);

}

int main()
{

	TestSList();

   system("pause");
   return 0;
}