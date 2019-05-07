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


//���������ⳣ�õ��ĸ�����(��ʱ�����ǿ�������ڴ�й©)

//ͷ��
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

//����ָ��(����һ��ָ������k��,Ȼ��ͬʱ��)
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

//��ָ�뷨ɾ���������ظ�������
void ThreeP(pNode head)
{
	pNode first = (pNode)malloc(sizeof(Node));
	if (first == NULL)
	{
		return;
	}
	//�����µ�ͷ�ڵ�
	first->next = head;
	pNode newhead = first;
	pNode mid = head;
	pNode second = head->next;
	// 1 2 3 4 4 5
	//mid ���ڽڵ��ֵ�� second һ��,���ظ�
	while (second != NULL)
	{
		//�ظ���ʱ��mid����,second ������,ֵ��һ��˵���ҵ��ظ�����
		while (second != NULL&&mid->data == second->data)
		{
			second = second->next;
		}
		if (mid->next != second)//˵���м����ظ���
		{
			//ִ��ɾ���Ĺ���,ѭ����������mid�ѱ�ɾ����
			while (mid != second)
			{
				first->next = mid->next;
				free(mid);
				mid = NULL;//Ұָ����Ϊ��
				mid = first->next;
			}
			//mid ��ʱ�� second ��ͬһλ��,���seco!=NULL,˵��û������
			if (second != NULL)
			{
				second = second->next;
			}
		}
		//���û���ظ���
		else
		{
			//ͷָ�����mid,mid ��second ������
			//ͷָ��ִ��ɾ����ʱ��Ҫ��,����Ҫ����mid������
			first = mid;
			mid = mid->next;
			second = second->next;
		}
	}
	//�½���һ��ͷָ��,�����Լ������ͷ�ڵ��next����ͷָ��λ��
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