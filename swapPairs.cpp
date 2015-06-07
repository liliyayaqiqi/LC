/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* swapPairs(ListNode* head) {
	if (!head)
		return NULL;
	if (!head->next)
		return head;
	ListNode* hptr = NULL;
	ListNode* ptr= head;
	ListNode* last_ptr = NULL;
	while(ptr)
	{
		if (!ptr->next)
		{
			ptr = ptr->next;
			continue;
		}
		else
		{
			if(!last_ptr)
			{
				hptr = ptr->next;
				ptr->next = ptr->next->next;
				hptr->next = ptr;
				last_ptr = ptr;
				ptr = ptr->next;
			}
			else
			{
				last_ptr->next = ptr->next;
				ListNode* tmp = ptr->next;
				ptr->next = ptr->next->next;
				tmp->next = ptr;
				last_ptr = ptr;
				ptr = ptr->next;
			}
		}
	}
	return hptr;       
}