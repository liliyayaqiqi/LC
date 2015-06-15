/*
Sort a linked list using insertion sort.
*/

ListNode* insertionSortList(ListNode* head)
{
	ListNode* ptr = head;
	ListNode* newHead = head;
	ListNode* ptr_pre = NULL;
	while (ptr)
	{
		if (!ptr_pre)
		{
			ptr_pre = ptr;
			ptr = ptr->next;
		}
		while (ptr && ptr->val > ptr_pre->val)
		{
			ptr_pre = ptr;
			ptr = ptr->next;
		}
		if (ptr)
		{
			ListNode* last = NULL;
			ListNode* tmp = newHead;
			while (tmp != ptr_pre && tmp->val < ptr->val)
			{
				last = tmp;
				tmp = tmp->next;
			}
			if (last)
				last->next = ptr;
			else
				newHead = ptr;
			ptr_pre->next = ptr->next;
			ptr->next = tmp;
			ptr = ptr_pre->next;
		}
	}
	return newHead;
}