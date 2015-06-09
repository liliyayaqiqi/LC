/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head = NULL;
	ListNode* current = NULL;
	if (l1 && l2)
	{
		if (l1->val <= l2->val)
		{
			head = l1;
			l1 = l1->next;
			current = head;
		}
		else
		{
			head = l2;
			l2 = l2->next;
			current = head;
		}
	}
	else
	{
		if (l1)
			return l1;
		else
			return l2;
	}
	while (l1 || l2)
	{
		if (!l1)
		{
			current->next = l2;
			l2 = l2->next;
			current = current->next;
		}
		else
		{
			if(!l2)
			{
				current->next = l1;
				l1 = l1->next;
				current = current->next;
			}
			else
			{
				if (l1->val <= l2->val)
				{
					current->next = l1;
					l1 = l1->next;
					current = current->next;
				}
				else
				{
					current->next = l2;
					l2 = l2->next;
					current = current->next;
				}
			}
		}
	}
	current->next = NULL;
	return head;
}
