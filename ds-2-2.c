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

void SListPopBack(SList* s)
{
	assert(s);
	if (s->_Head->_Next == NULL)//只有一个节点
	{
		SListPopFront(&s);
	}
	PNode pCur = s->_Head;
	while (pCur->_Next->_Next != NULL)//pcur的下一个节点的next指向空,说明pcur是倒数第二个
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

void SListInsertAfter(PNode pos,SLTDatatype data)//在pos后面的位置插入
{
		PNode node = BuySListNode(data);
		node->_Next = pos->_Next;
		pos->_Next = node;
}

void SListEraseAfter(PNode pos)
{
	if (pos->_Next == NULL)
	{
		return;
	}
	else
	{
		PNode node = pos->_Next->_Next;
		free(pos->_Next);
		pos->_Next = node;
	}
}

void SListRemove(SList* s, SLTDatatype data)
{
	assert(s);
	if (s->_Head == NULL)
	{
		return;
	}
	if (s->_Head->_Next == NULL)
	{
		free(s->_Head);
		s->_Head = NULL;
	}
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
					pCur = pPre;
				}
			}
	}
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
 	SListPushFront(&s,5);//头插测试

	SListPrint(&s);

	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);//头删测试

	SListPrint(&s);


	SListPushBack(&s, 0);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);//尾插测试

	SListPrint(&s);

	

	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);//尾删测试

	SListPrint(&s);

	SListPushFront(&s, 0); 
	SListPushFront(&s, 5);
	SListPushFront(&s, 9);
	SListPrint(&s);

	printf("所查元素是第%d个\n",SListFind(&s,1));

	//目前链表9--->5--->0--->2--->1--->NULL
	//在第二个元素后面插入1
	SListInsertAfter(SListFindPos(&s,2), 1);
	SListPrint(&s);
	//目前链表9--->5--->1--->0--->2--->1--->NULL
	//在第5个元素后面插入1
	SListInsertAfter(SListFindPos(&s,5), 1);
	SListPrint(&s);

	SListEraseAfter(SListFindPos(&s, 3));//把第三个元素后面的删掉
	SListPrint(&s);

	SListRemove(&s,1);//删除掉值为1的所有元素
	SListPrint(&s);
}

int main()
{

	TestSList();

   system("pause");
   return 0;
}