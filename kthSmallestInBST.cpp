/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
Follow up:
 What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 Follow up:
 What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:
1.Try to utilize the property of a BST.
2.What if you could modify the BST node's structure?
3.The optimal runtime complexity is O(height of BST).

*/

// solution one: without modifying the structure of the BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //recursive solution
 void doRecurtion(TreeNode* root, int k, int& cnt, int& val)
 {
 	if (!root && cnt < k)
 	{
 		doRecurtion(root->left, k, cnt, val);
 		cnt++;
 		if (cnt == k)
 		{
 			val = root->val;
 			return;
 		}
 		doRecurtion(root->right, k, cnt, val);
 	}
 }
 int kthSmallest(TreeNode* root, int k)
 {
 	int cnt = 0;
 	int val = 0;
 	doRecurtion(root, k, cnt, val);
 	return val;
 }

 // non-recursive solution
 int kthSmallest(TreeNode* root, int k)
 {
 	vector<TreeNode*> temp_stack;
 	TreeNode* ptr = root;
 	int counter = 0;
 	while (ptr || !temp_stack.empty())
 	{
 		while (ptr)
 		{
 			temp_stack.push_back(ptr);
 			ptr = ptr->left;
 		}
 		ptr = temp_stack.back();
 		temp_stack.pop_back();
 		counter++;
 		if (counter == k)
 			return ptr->val;
 		ptr = ptr->right;
 	}
 	return 0;
 }