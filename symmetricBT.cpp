/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//To iterate is human, to recurse is divine ;)
// recursively
bool judge(TreeNode* left, TreeNode* right)
{
	if(!left || !right) return !left && !right;
	return left->val == right->val && judge(left->left, right->right) && judge (left->right, right->left);
}

bool isSymmetric(TreeNode* root)
{
	if(!root) return true;
	return judge(root->left, root->right);
}

// iteratively
bool isSymmetric(TreeNode* root)
{
	if(!root)
		return true;
	queue<TreeNode*> nodeQ;
	TreeNode* lptr = root->left;
	TreeNode* rptr = root->right;
	nodeQ.push(lptr);
	nodeQ.push(rptr);
	while(!nodeQ.empty())
	{
		lptr = nodeQ.front();
		nodeQ.pop();
		rptr = nodeQ.front();
		nodeQ.pop();
		if (!lptr || !rptr)
		{
			if ((!lptr && rptr) || (lptr && !rptr))
				return false;
		}
		else
		{
			if (lptr->val != rptr->val)
				return false;
			nodeQ.push(lptr->left);
			nodeQ.push(rptr->right);
			nodeQ.push(lptr->right);
			nodeQ.push(rptr->left);
		}
	}
	return true;
}