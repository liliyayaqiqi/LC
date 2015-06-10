/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.
*/
void doRecursion(TreeNode* node, int& minDepth, int curDepth)
{
	if(!node)
		return;
	if(!node->left && !node->right)
	{
		if (minDepth == 0)
			minDepth = curDepth + 1;
		else
			minDepth = minDepth > curDepth + 1? curDepth + 1: minDepth;
		return;
	}
	if (minDepth > 0 && minDepth < curDepth)
		return;
	if (node->left)
		doRecursion(node->left, minDepth, curDepth + 1);
	if (node->right)
		doRecursion(node->right, minDepth, curDepth + 1);
}
int minDepth(TreeNode* root)
{
	int minDepth = 0;
	doRecursion(root, minDepth, 0);
	return minDepth;
}