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


PNode SListRemoveall(SList* s, SLTDatatype data)
{
	assert(s);
	PNode pCur = s->_Head;
	PNode result = NULL;//结果链表的第一个节点
	PNode last = NULL;//结果链表的最后一个节点
	while (pCur != NULL)
	{
		if (pCur->_data != data)
		{
			if (last==NULL)
			{
				result = last=pCur;
			}
			else
			{
				last->_Next=pCur;
				last = pCur;
			}
		}
		pCur = pCur->_Next;
	}
	if (last != NULL)
	{
		last->_Next = NULL;
	}
	return result;
}

//头插思想
PNode Reverse(SList*s)
{
	PNode result = NULL;
	PNode pCur = s->_Head;
	while (pCur != NULL)
	{
		PNode next = pCur->_Next;
		pCur->_Next = result;
		result = pCur;
		pCur = next;
	}
	return result;
}

void Changeandupdate(SList* l1, SList* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	PNode result = NULL;
	PNode last = NULL;
	PNode C1 = l1;
	PNode C2 = l2;
	while (C1 != NULL&&C2 != NULL)
	{
		if (C1->_data <= C2->_data)
		{
			if (result == NULL)
			{
				result = C1 = last;
			}
			else
			{
				last->_Next = C1;
				last = C1;
			}
			C1 = C1->_Next;
		}
		else
		{
			if (result == NULL)
			{
				result = C2 = last;
			}
			else
			{
				last->_Next = C2;
				last = C2;
			}
			C2 = C2->_Next;
		}
	}
	if (C1 != NULL)
	{
		last->_Next = C1;
	}
	if (C2 != NULL)
	{
		last->_Next = C2;
	}
}

PNode partition(SList* s, int x)
{
	PNode result1 = NULL; 
	PNode last1 = NULL;
	PNode last2 = NULL;
	PNode result2 = NULL;
	PNode pCur = s->_Head;
	while (pCur != NULL)
	{
		if (pCur->_data < x)
		{
			if (result1 == NULL)
			{
				result1 = last1 = pCur;
			}
			else
			{
				last1->_Next = pCur;
				last1 = pCur;
			}
		}
		else
		{
			if (result2 == NULL)
			{
				result2 = last2 = pCur;
			}
			else
			{
				last2->_Next = pCur;
				last2 = pCur;
			}
		}
	}
	
	if (last1 != NULL)
	{
		last1->_Next = result2;
	}
	if (last2 != NULL)
	{
		last2->_Next = NULL;
	}
	if (last1 != NULL)
	{
		return result1;
	}
	else
	{
		return result2;
	}
	return result1;
}

int main()
{

   system("pause");
   return 0;
}