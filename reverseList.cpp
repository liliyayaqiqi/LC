// A linked list can either be reversed iteratively or recursively
// Implement both
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// iteratively
ListNode* reverseList(ListNode* head)
{
	ListNode* last = NULL;
	ListNode* cptr = head;
	while (cptr)
	{
		ListNode* tmp = cptr->next;
		cptr->next = last;
		last = cptr;
		cptr = tmp;
	}
	return last;
}
// recursively
ListNode* reverseList(ListNode* head)
{
	if (!head)
		return NULL;
	if (!head->next)
		return head;
	ListNode* lh = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return lh;
}