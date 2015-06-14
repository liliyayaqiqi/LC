/*
Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.
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

vector<int> rightSideView(TreeNode* root)
{
	TreeNode* ptr = root;
	vector<int> result;
	queue<TreeNode*> nodeQ;
	if (ptr)
		nodeQ.push(ptr);
	while(!nodeQ.empty())
	{
		int num = nodeQ.size() - 1;
		for(int i = 0; i < num; i++)
		{
			ptr = nodeQ.front();
			if (ptr->left)
				nodeQ.push(ptr->left);
			if(ptr->right)
				nodeQ.push(ptr->right);
			nodeQ.pop();
		}
		ptr = nodeQ.front();
		nodeQ.pop();
		if (ptr->left)
			nodeQ.push(ptr->left);
		if(ptr->right)
			nodeQ.push(ptr->right);
		result.push_back(ptr->val);
	}
	return result;
}