/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* partition(ListNode* head, int x)
{
	ListNode* lowHead = NULL;
	ListNode* lowTail = NULL;
	ListNode* highHead = NULL;
	ListNode* highTail = NULL;
	ListNode* curPtr = head;
	while(curPtr)
	{
		if(curPtr->val < x)
		{
			if(!lowHead)
				lowHead = curPtr;
			if (lowTail)
				lowTail->next = curPtr;
			lowTail = curPtr;
			curPtr = curPtr->next;
		}
		else
		{
			if(!highHead)
				highHead = curPtr;
			if(highTail)
				highTail->next = curPtr;
			highTail = curPtr;
			curPtr = curPtr->next;
		}
	}
	if(highTail)
		highTail->next = NULL;
	if(lowTail)
		lowTail->next = highHead;
	return (lowHead != NULL? lowHead: highHead);
}