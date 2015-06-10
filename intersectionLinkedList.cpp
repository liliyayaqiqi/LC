/*
Write a program to find the node at which the intersection of two singly linked lists begins.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
 {
 	if(!headA || !headB)
 		return NULL;
 	int lengthA = 0;
 	ListNode* pa = headA;
 	while(pa)
 	{
 		lengthA++;
 		pa = pa->next;
 	}
 	int lengthB = 0;
 	ListNode* pb = headB;
 	while(pb)
 	{
 		lengthB++;
 		pb = pb->next;
 	}
 	pa = headA;
 	pb = headB;
 	if(lengthA > lengthB)
 	{
 		for(int i = 0; i < lengthA - lengthB; i++)
 			pa = pa->next;
 	}
 	else
 	{
 		for(int i = 0; i < lengthB - lengthA; i++)
 			pb = pb->next;
 	}
 	while (pa && pb)
 	{
 		if (pa == pb)
 			return pa;
 		pa = pa->next;
 		pb = pb->next;
 	}
 	return NULL;
 }