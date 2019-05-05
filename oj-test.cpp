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

		//特殊情况,如果链表为空或者只有一个节点,返回是
		if (A == NULL || A->next == NULL)
		{
			return true;
		}
		//如果有多个节点,逆转链表

		//逆转之前先把原来的链表保存一份
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
		//如果逆转的链表和原链表一致,说明是回文结构
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