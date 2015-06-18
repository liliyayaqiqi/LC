/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

ListNode* deleteDuplicates(ListNode* head)
{
	ListNode* ptr = head;
	ListNode* pre = NULL;
	ListNode* newHead = NULL;
	while(ptr)
	{
		int duplication = 0;
		ListNode* tmp = ptr->next;
		while(tmp && tmp->val == ptr->val)
		{
			duplication++;
			tmp = tmp->next;
		}
		if(duplication == 0)
		{
			if(pre)
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