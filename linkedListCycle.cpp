/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 bool hasCycle(ListNode *head) {
 	ListNode* slow_ptr = head;
 	ListNode* fast_ptr = head;
 	if (fast_ptr)
 		fast_ptr = fast_ptr->next;
 	while(fast_ptr != NULL)
 	{
 		if (fast_ptr == slow_ptr)
 			return true;
 		slow_ptr = slow_ptr->next;
 		fast_ptr = fast_ptr->next;
 		if (fast_ptr)
 			fast_ptr = fast_ptr->next;
 		else
 			return false;
 	}
 	return false;        
}