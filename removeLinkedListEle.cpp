/*
Remove all elements from a linked list of integers that have value val.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* removeElements(ListNode* head, int val)
{
	ListNode* last = NULL;
	ListNode* ptr = head;
	while(ptr)
	{
		if (ptr->val == val)
		{
			if (!last)
				head = ptr->next;
			else
				last->next = ptr->next;
			ptr = ptr->next;
		}
		else
		{
			last = ptr;
			ptr = ptr->next;
		}
	}
	return head;
}