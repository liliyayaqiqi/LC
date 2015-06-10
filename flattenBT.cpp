/*
Given a binary tree, flatten it to a linked list in-place.
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
void flatten(TreeNode* root)
{
	vector<TreeNode*> nodeStack;
	TreeNode* ptr = root;
	TreeNode* last = NULL;
	while(ptr || !nodeStack.empty())
	{
		while(ptr)
		{
			if(last)
			{
				last->right = ptr;
				last->left = NULL;
			}
			if(ptr->right)
				nodeStack.push_back(ptr->right);
			last = ptr;
			ptr = ptr->left;
		}
		if(!nodeStack.empty())
		{
			ptr = nodeStack.back();
			nodeStack.pop_back();
		}
	}
}
// solution that do not use nodeStack
void flatten(TreeNode* root)
{
	while(root)
	{
		TreeNode* ptr = root->left;
		if (root->left && root->right)
		{
			while(ptr->right)
				ptr = ptr->right;
			ptr->right = root->right;
		}
		if (root->left)
		{
			root->right = root->left;
			root->left = NULL;
		}
		root = root->right;
	}
}