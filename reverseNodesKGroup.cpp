/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.
*/

ListNode* reverseKGroup(ListNode* head, int k)
{
	int listLength = 0;
	ListNode* ptr = head;
	while (ptr)
	{
		listLength++;
		ptr = ptr->next;
	}
	int groups = listLength / k;
	if (groups < 1)
		return head;
	ptr = head;
	ListNode* pre = NULL;
	for (int i = 0; i < groups; i++)
	{
		ListNode* last = NULL;
		ListNode* firstNode = ptr;
		for (int j = 1; j < k; j++)
		{
			ListNode* tmp = ptr->next;
			ptr->next = last;
			last = ptr;
			ptr = tmp;
		}
		ListNode* tmp = ptr->next;
		ptr->next = last;
		if (!pre)
			head = ptr;
		else
			pre->next = ptr;
		pre = firstNode;
		ptr = tmp;
	}
	pre->next = ptr;
	return head;
}