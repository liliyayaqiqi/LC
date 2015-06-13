//Bonus points if you could solve it both recursively and iteratively.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//sove it recursively
bool isSymmetric(TreeNode* root)
{
	if (!root)
		return false;
	if (!root->left && !root->right)
		return true;
	bool left = isSymmetric(root->left);
	bool right = isSymmetric(root->right);
	if (!(left && right))
		return false;
	if (!root->left && !root->right && root->left->val == root->right->val)
		return true;
	return false;        
}