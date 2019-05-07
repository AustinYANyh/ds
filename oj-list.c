#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

typedef struct SlistNode
{
	struct SlistNode* next;
	datatype data

}Node,*pNode;



pNode BuyNode(datatype data)
{
	pNode newnode = (pNode)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		return;
	}
	newnode->data = data;
	newnode->next = NULL;
}


//链表面试题常用的四个操作(暂时不考虑空链表和内存泄漏)

//头插
void PushFront(pNode head,datatype data)
{
	assert(head);
	pNode node = BuyNode(data);
	node->next = head;
	head->next = node;
}

pNode FindPos(pNode head)
{
	assert(head);
	pNode pCur = head;
	while (pCur != NULL)
	{
		pCur = pCur->next;
	}
	return pCur;
}

void PushBack(pNode head, datatype data)
{
	pNode last = FindPos(head);
	pNode node = BuyNode(data);
	node->next = NULL;
	last->next = node;
	last = node;
}

//快慢指针(其中一个指针先走k步,然后同时走)
void FastandSlowP(pNode head,unsigned int k)
{
	pNode pCur = head;
	pNode pPre = head;
	while (k > 0 && pCur != NULL)
	{
		k--;
		pCur = pCur->next;
	}
}

//三指针法删除链表中重复的区间
void ThreeP(pNode head)
{
	pNode first = (pNode)malloc(sizeof(Node));
	if (first == NULL)
	{
		return;
	}
	//创建新的头节点
	first->next = head;
	pNode newhead = first;
	pNode mid = head;
	pNode second = head->next;
	// 1 2 3 4 4 5
	//mid 所在节点的值和 second 一样,即重复
	while (second != NULL)
	{
		//重复的时候mid不动,second 继续走,值不一样说明找到重复区间
		while (second != NULL&&mid->data == second->data)
		{
			second = second->next;
		}
		if (mid->next != second)//说明中间有重复的
		{
			//执行删除的过程,循环结束代表mid已被删除完
			while (mid != second)
			{
				first->next = mid->next;
				free(mid);
				mid = NULL;//野指针置为空
				mid = first->next;
			}
			//mid 此时和 second 在同一位置,如果seco!=NULL,说明没遍历完
			if (second != NULL)
			{
				second = second->next;
			}
		}
		//如果没有重复的
		else
		{
			//头指针跟随mid,mid 和second 往后走
			//头指针执行删除的时候要用,所以要根据mid来更新
			first = mid;
			mid = mid->next;
			second = second->next;
		}
	}
	//新建立一个头指针,我们自己定义的头节点的next就是头指针位置
	pNode head1 = newhead->next;
	free(newhead);
	newhead = NULL;
	return head1;
}

int main()
{

   system("pause");
   return 0;
}