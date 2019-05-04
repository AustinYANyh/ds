
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
//重复的结点不保留，返回链表头指针。 
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		ListNode* first = (ListNode*)malloc(sizeof(ListNode));
		first->next = pHead;
		ListNode* newhead = first;
		ListNode* mid = pHead;
		ListNode* second = pHead->next;
		while (second != NULL)
		{
			while (second != NULL&&mid->val == second->val)
			{
				second = second->next;
			}
			//中间有空隙,说明中间有重复区间
			if (mid->next != second)
			{
				while (mid != second)
				{
					first->next = mid->next;
					free(mid);
					mid = NULL;
					mid = first->next;
				}
				if (second != NULL)
				{
					second = second->next;
				}
			}
			else
			{
				first = mid;
				second = second->next;
				mid = mid->next;
			}
		}
		ListNode* head = newhead->next;
		free(newhead);
		newhead = NULL;
		return head;
	}
};


/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/

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
};