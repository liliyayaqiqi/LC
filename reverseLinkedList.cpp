/*
Reverse a linked list from position m to n. Do it in-place and in one-pass. 

For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4, 

return 1->4->3->2->5->NULL. 

Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (!head || m == n)
		return head;
	int index = 1;
	ListNode* last = NULL;
	ListNode* ptr = head;
	while(index < m)
	{
		last = ptr;
		ptr = ptr->next;
		index++;
	}
	ListNode* first = ptr;
	ListNode* end = NULL;
	ListNode* prePtr = ptr;
	ptr = ptr->next;
	index++;
	while(index < n)
	{
		ListNode* tmp = ptr->next;
		ptr->next = prePtr;
		prePtr = ptr;
		ptr = tmp;
		index++;
	}
	end = ptr->next;
	ptr->next = prePtr;
	if (!last)
		head = ptr;
	else
		last->next = ptr;
	first->next = end;
	return head;
}
