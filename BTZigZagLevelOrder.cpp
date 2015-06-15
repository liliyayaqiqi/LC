/*
Given a binary tree, return the zigzag level order traversal of its nodes' values.
(ie, from left to right, then right to left for the next level and alternate between).
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
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	if (!root)
		return result;
	stack<TreeNode*> nodeS1;
	stack<TreeNode*> nodeS2;
	nodeS1.push(root);
	vector<int> level;
	int order = 0;
	while(!nodeS1.empty() || !nodeS2.empty())
	{
		level.clear();
		if (order == 0)
		{
			int num = nodeS1.size();
			for(int i = 0; i < num; i++)
			{
				TreeNode* ptr = nodeS1.top();
				level.push_back(ptr->val);
				nodeS1.pop();
				if (ptr->left)
					nodeS2.push(ptr->left);
				if (ptr->right)
					nodeS2.push(ptr->right);
			}
			order = 1;
		}
		else
		{
			int num = nodeS2.size();
			for(int i = 0; i < num; i++)
			{
				TreeNode* ptr = nodeS2.top();
				level.push_back(ptr->val);
				nodeS2.pop();
				if (ptr->right)
					nodeS1.push(ptr->right);
				if (ptr->left)
					nodeS1.push(ptr->left);
			}
			order = 0;
		}
		result.push_back(level);
	}
	return result;
}