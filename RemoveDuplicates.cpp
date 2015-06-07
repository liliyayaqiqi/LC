/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode* currentNode = head;
    	ListNode* lastNode = NULL;
    	while (currentNode)
    	{
    		if (lastNode != NULL && currentNode->val == lastNode->val)
    		{
    			ListNode* tmp = currentNode->next;
    			lastNode->next = tmp;
    			delete(currentNode);
    			currentNode = tmp;
    		}
    		else
    		{
    			lastNode = currentNode;
    			currentNode = currentNode->next;
    		}
    	}
    	return head;   
    }
};