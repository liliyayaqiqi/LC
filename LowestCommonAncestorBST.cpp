/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST
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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if (!root)
		return root;
	if (!p || !q)
		return NULL;
	while (root)
	{
		if ((p->val < root->val && q->val > root->val) || (q->val < root->val && p->val > root->val))
			return root;
		if (p->val == root->val || q->val == root->val)
			return root;
		if (p->val < root->val)
			root = root->left;
		else
			root = root->right;
	}
	return root;
}