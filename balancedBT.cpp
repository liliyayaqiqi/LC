/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 For this problem, a height-balanced binary tree is defined as 
 a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
 */
/*int getHeight(TreeNode* node, bool& isBalanced)
{
	if (!node)
		return 0;
	int left_height = 0;
	int right_height = 0;
	if (node->left)
		left_height = getHeight(node->left, isBalanced);
	if (node->right)
		right_height = getHeight(node->right, isBalanced);
	int delta = left_height > right_height? left_height - right_height: right_height - left_height;
	if (delta > 1)
		isBalanced = false;
	return left_height > right_height? left_height + 1: right_height + 1;
}
bool isBalanced(TreeNode* root)
{
	bool result = true;
	int height = getHeight(root, result);
	return result;
}*/

// below is another solution, more abbreviated but with the same speed.

int height(TreeNode* node)
{
	if (!node)
		return 0;
	int hl = height(node->left);
	int hr = height(node->right);
	if (hl == -1 || hr == -1 || abs(hl - hr) > 1)
		return -1;
	return hl > hr? hl + 1: hr + 1;
}
bool isBalanced(TreeNode* root)
{
	if(height(root) != -1)
		return true;
	return false;
}