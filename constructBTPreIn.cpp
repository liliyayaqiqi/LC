/*
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree. 
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
TreeNode* doRecursion(vector<int>& preorder, vector<int>& inorder, int preBegin, int inBegin, int inEnd)
{	
	if (inBegin == inEnd)
	{
	    int val = inorder[inBegin];
	    TreeNode* root = new TreeNode(val);
	    return root;
	}
	if (inBegin > inEnd)
		return NULL;
	int val = preorder[preBegin];
	TreeNode* root = new TreeNode(val);
	int index = inBegin;
	while (index <= inEnd)
	{
		if (inorder[index] == val)
			break;
		index++;
	}
	int leftLen = index - inBegin;
	root->left = doRecursion(preorder, inorder, preBegin + 1, inBegin, index - 1);
	root->right = doRecursion(preorder, inorder, preBegin + leftLen + 1, index + 1, inEnd);
	return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	TreeNode* root = doRecursion(preorder, inorder, 0, 0, inorder.size() - 1);
	return root;
}