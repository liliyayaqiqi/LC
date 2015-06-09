/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void judgeSameTree(TreeNode*p, TreeNode*q, bool &isSame)
	{
		if (isSame == false)
			return;
		if (p == NULL)
		{
			if (q == NULL)
				return;
			else
			{
				isSame = false;
				return;
			}
		}
		if (q == NULL)
		{
			isSame = false;
			return;
		}
		if (p->val != q->val)
		{
			isSame = false;
			return;
		}
		judgeSameTree(p->left, q->left, isSame);
		judgeSameTree(p->right, q->right, isSame);
	}
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	bool isSame = true;
    	judgeSameTree(p, q, isSame);
    	return isSame;      
    }
};