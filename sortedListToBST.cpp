/*
Given a singly linked list where 
elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* doRecursion(ListNode* start, ListNode* end)
{
	if (!start || start == end)
		return NULL;
	if(start->next == end)
		return (new TreeNode(start->val));
	ListNode* ptr1 = start;
	ListNode* ptr2 = start;
	while(ptr2->next != end && ptr2->next->next != end)
	{
		ptr2 = ptr2->next->next;
		ptr1 = ptr1->next;
	}
	TreeNode* root = new TreeNode(ptr1->val);
	root->left = doRecursion(start, ptr1);
	root->right = doRecursion(ptr1->next, end);
	return root;
}
TreeNode* sortedListToBST(ListNode* head)
{
	TreeNode* root = doRecursion(head, NULL);
	return root;
}