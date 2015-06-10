/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	if (!root)
		return result;
	queue<TreeNode*> nodeQ;
	nodeQ.push(root);
	while(!nodeQ.empty())
	{
		int num = nodeQ.size();
		vector<int> level;
		for(int i = 0; i < num; i++)
		{
			TreeNode* node = nodeQ.front();
			level.push_back(node->val);
			nodeQ.pop();
			if (node->left)
				nodeQ.push(node->left);
			if (node->right)
				nodeQ.push(node->right);
		}
		result.push_back(level);
	}
	return result;
}