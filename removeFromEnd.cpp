/*
Given a linked list, remove the nth node from the end of list and return its head.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 ListNode* removeNthFromEnd(ListNode* head, int n)
 {
 	ListNode* ptr1 = head;
 	ListNode* ptr2 = head;
 	ListNode* last = NULL;
 	for(int i = 0; i < n; i++)
 		ptr1 = ptr1->next;
 	while(ptr1)
 	{
 		ptr1 = ptr1->next;
 		last = ptr2;
 		ptr2 = ptr2->next;
 	}
 	if (last)
 		last->next = ptr2->next;
 	else
 		head = ptr2->next;
 	delete ptr2;
 	return head;
 }