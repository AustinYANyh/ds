
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