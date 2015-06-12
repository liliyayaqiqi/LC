/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
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
vector<TreeNode*> doRecursion(int start, int end)
{
	vector<TreeNode*> result;
	if(start > end)
	{
		result.push_back(NULL);
		return result;
	}
	for (int i = start; i <= end; i++)
	{		
		vector<TreeNode*> leftRoots = doRecursion(start, i - 1);
		vector<TreeNode*> rightRoots = doRecursion(i + 1, end);
		
		for(int j = 0; j < leftRoots.size(); j++)
		{
			TreeNode* left = leftRoots[j];
			for(int k = 0; k < rightRoots.size(); k++)
			{
				TreeNode* right = rightRoots[k];
				TreeNode* root = new TreeNode(i);
				root->left = left;
				root->right = right;
				result.push_back(root);
			}
		}
	}
	return result;
}
vector<TreeNode*> generateTrees(int n) 
{
	return doRecursion(1, n);
}