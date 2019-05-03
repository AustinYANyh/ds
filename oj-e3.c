#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

typedef struct SlistNode
{
	struct SlistNode* next;
	datatype data;

}Node,*pNode;

pNode head;

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
//重复的结点不保留，返回链表头指针。 
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

pNode erasesame(pNode head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	//创建两个指针
	pNode pCur = head->next;
	pNode pPre = head;
	//两个指针一前一后同时走,其中一个指针的data与其相同,一个停下,另一个继续走
	
	while (pCur!=NULL)
	{
		if (pCur->data != pCur->next->data)
		{
			while (pCur->data != pCur->next->data)
			{
				pCur = pCur->next;
				pPre = pPre->next;
			}
			pPre->next = pCur->next;
		}
		if (pCur->data == pCur->next->data)
		{
			pPre = pPre;
			pCur = pCur->next;
		}
}


int main()
{
	
	
 
   system("pause");
   return 0;
}