/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void doRecursion(TreeNode* node)
{
	if (!node)
		return;
	TreeNode* left = node->left;
	TreeNode* right = node->right;
	node->left = right;
	node->right = left;
	doRecursion(node->left);
	doRecursion(node->right);
}
TreeNode* invertTree(TreeNode* root)
{
	doRecursion(root);
	return root;
}