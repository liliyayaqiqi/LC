/*
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.
 
For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3. 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* deleteDuplicates(ListNode* head)
{
	ListNode* newHead = NULL;
	ListNode* pre = NULL;
	ListNode* ptr = head;
	while (ptr)
	{
		int val = ptr->val;
		ListNode* tmp = ptr->next;
		int numDup = 0;
		while (tmp && tmp->val == val)
		{
			numDup++;
			tmp = tmp->next;
		}
		if (numDup == 0)
		{
			if (pre)
				pre->next = ptr;
			else
				newHead = ptr;
			pre = ptr;
		}
		ptr = tmp;
	}
	if (pre)
		pre->next = NULL;
	return newHead;
}