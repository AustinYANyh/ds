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

//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
//�ظ��Ľ�㲻��������������ͷָ�롣 
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

pNode erasesame(pNode head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	//��������ָ��
	pNode pCur = head->next;
	pNode pPre = head;
	//����ָ��һǰһ��ͬʱ��,����һ��ָ���data������ͬ,һ��ͣ��,��һ��������
	
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