/*
Given a binary tree and a sum, 
determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum
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
void doRecursion(TreeNode* node, int sum, int curSum, bool& hasPath)
{
	if (!node)
		return;
	if(!node->left && !node->right)
	{
		if(curSum + node->val == sum)
			hasPath = true;
		return;
	}
	if(node->left)
		doRecursion(node->left, sum, curSum + node->val, hasPath);
	doRecursion(node->right, sum, curSum + node->val, hasPath);
}
bool hasPathSum(TreeNode* root, int sum)
{
	int curSum = 0;
	bool hasPath = false;
	doRecursion(root, sum, curSum, hasPath);
	return hasPath;
}