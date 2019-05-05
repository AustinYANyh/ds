#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <iostream>

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

ListNode* A;

class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here

		//�������,�������Ϊ�ջ���ֻ��һ���ڵ�,������
		if (A == NULL || A->next == NULL)
		{
			return true;
		}
		//����ж���ڵ�,��ת����

		//��ת֮ǰ�Ȱ�ԭ����������һ��
		ListNode* pp = A;
		int count = 0;
		while (pp != NULL)
		{
			++count;
			pp = pp->next;
		}
		int* copyhead = (int*)malloc(900 * sizeof(int));
		int i = 0;
		for (i = 0; i<count && A != NULL; i++)
		{
			copyhead[i] = A->val;
			A = A->next;
		}

		ListNode* result = NULL;
		ListNode* pCur = A;
		while (pCur != NULL)
		{
			pCur->next = result;
			result = pCur;
			pCur = pCur->next;
		}
		//�����ת�������ԭ����һ��,˵���ǻ��Ľṹ
		int* copyhead2 = (int*)malloc(900 * sizeof(int));
		for (i = 0; i<count && result != NULL; i++)
		{
			copyhead2[i] = result->val;
			result = result->next;
		}

		for (int j = 0; j<count; j++)
		{
			if (copyhead[j] != copyhead2[j])
			{
				return false;
			}
		}
		return true;
	}

	void ListInit(ListNode* A)
	{
		assert(A);
		A = NULL;
	}

	struct ListNode* BuyNode(int data)
	{
		assert(A);
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = data;
		newNode->next = NULL;
	}

	void PushFront(ListNode* A,int data)
	{
		assert(A);
		ListNode* newnode = BuyNode(data);
		if (A == NULL)
		{
			A = newnode;
		}
		else
		{
			newnode->next = A->next;
			A->next = newnode;
		}
	}

	void TestList(ListNode* A)
	{
		ListInit(A);
		PushFront(A, 1);
		PushFront(A, 1);
		PushFront(A, 1);
		PushFront(A, 1);
		PushFront(A, 1);

	}
};

void TestList(ListNode* A);

int main()
{
	TestList(A);


	system("pause");
	return 0;
}