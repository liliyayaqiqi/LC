//non recursion
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> preorderTraversal(TreeNode* root)
{
	vector<TreeNode*> nodeStack;
	vector<int> value;
	TreeNode* node = root;
	while (node)
	{
		value.push_back(node->val);
		if (node->right)
			nodeStack.push_back(node->right);
		node = node->left;
		while(node)
		{
			value.push_back(node->val);
			if(node->right)
				nodeStack.push_back(node->right);
			node = node->left;
		}
		if (nodeStack.size() > 0)
		{
			node = nodeStack.back();
			nodeStack.pop_back();
		}
		else
			node = NULL;
	}
	return value;
}