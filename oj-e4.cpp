
//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
//�ظ��Ľ�㲻��������������ͷָ�롣 
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

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
			//�м��п�϶,˵���м����ظ�����
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