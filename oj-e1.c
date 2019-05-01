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
	PNode node = (PNode*)malloc(sizeof(Node));//���½ڵ������ڴ�ռ�
	assert(node);//��������Ŀռ��Ƿ�ɹ�
	node->_data = data;
	node->_Next = NULL;//����Ӧ�����ݴ浽�ڵ���
	return node;
}

void SListPushFront(SList* s,SLTDatatype data)
{
	assert(s);
	PNode node=BuySListNode(data);
	assert(node);
	node->_Next = s->_Head;//˳���ܵߵ�,������ƻ�����ṹ��ʧ����
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
				PNode pPre = pCur;//pPre��¼����pCur����һ��
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
	SListPushBack(&s, 1);//β�����

	SListRemove(&s,1);//ɾ����ֵΪ1�����нڵ�
	SListPrint(&s);

	//SListSize(&s);
	//printf("��Ч�ڵ�ĸ���:%d \n", SListSize(&s));

	//SListEmpty(&s);
	//printf("%d\n", SListEmpty(&s));

	//SListClear(&s);
	//SListPrint(&s);

	//SListSize(&s);
	//printf("��Ч�ڵ�ĸ���:%d \n", SListSize(&s));

	//SListDestroy(&s);

}

int main()
{

	TestSList();

   system("pause");
   return 0;
}