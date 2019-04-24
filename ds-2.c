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

// void SListDestroy()
// {
// 
// }

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

void SListPopBack(SList* s)
{
	assert(s);
	if (s->_Head->_Next == NULL)//ֻ��һ���ڵ�
	{
		SListPopFront(&s);
	}
	PNode pCur = s->_Head;
	while (pCur->_Next->_Next != NULL)//pcur����һ���ڵ��nextָ���,˵��pcur�ǵ����ڶ���
	{
		pCur = pCur->_Next;
	}
	free(pCur->_Next);
	pCur->_Next = NULL;
}

Node* SListFind(SList* s,SLTDatatype data)
{
	assert(s);
	assert(s->_Head != NULL);
	PNode pCur = s->_Head;
	int count = 0;
	for (pCur; pCur != NULL; pCur = pCur->_Next)
	{
		if (pCur->_data == data)
		{
			return count+1;
		}
		count++;
	}
	return 0;
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

void SListInsertAfter(PNode pos,SLTDatatype data)//��pos�����λ�ò���
{
		PNode node = BuySListNode(data);
		node->_Next = pos->_Next;
		pos->_Next = node;
}

void SListErase(PNode pos, SLTDatatype data)
{

}

void SListPrint(SList* s)
{
	assert(s);
	assert(s->_Head != NULL);
	PNode pCur = s->_Head;
	while (pCur != NULL)
	{
		printf("%d--->", pCur->_data);
		pCur = pCur->_Next;
	}
	printf("NULL\n");
}

void TestSList()
{
	SList s;
	SListInit(&s);
	SListPushFront(&s,1);
 	SListPushFront(&s,2);
 	SListPushFront(&s,3);
 	SListPushFront(&s,4);
 	SListPushFront(&s,5);//ͷ�����

	SListPrint(&s);

	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);//ͷɾ����

	SListPrint(&s);


	SListPushBack(&s, 0);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);//β�����

	SListPrint(&s);

	

	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);//βɾ����

	SListPrint(&s);

	SListPushFront(&s, 0); 
	SListPushFront(&s, 5);
	SListPushFront(&s, 9);
	SListPrint(&s);

	printf("����Ԫ���ǵ�%d��\n",SListFind(&s,1));

	//Ŀǰ����9--->5--->0--->2--->1--->NULL
	//�ڵڶ���Ԫ�غ������1
	SListInsertAfter(SListFindPos(&s,2), 1);
	SListPrint(&s);
	//Ŀǰ����9--->5--->1--->0--->2--->1--->NULL
	//�ڵ�5��Ԫ�غ������1
	SListInsertAfter(SListFindPos(&s,5), 1);
	SListPrint(&s);

}

int main()
{

	TestSList();

   system("pause");
   return 0;
}