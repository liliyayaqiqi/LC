//Given a linked list, return the node where the cycle begins. If there is no cycle, return null. 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Please refer to http://blog.sina.com.cn/s/blog_6f611c300101fs1l.html
ListNode *detectCycle(ListNode *head)
{
	ListNode* fast = head;
	ListNode* slow = head;
	bool first = true;
	while(fast && fast->next)
	{
		if(!first)
		{
			if(fast == slow)
			{
				fast = head;
				while(fast != slow)
				{
					fast = fast->next;
					slow = slow->next;
				}
				return slow;
			}
		}
		fast = fast->next->next;
		slow = slow->next;
		first = false;
	}
	return NULL;
}