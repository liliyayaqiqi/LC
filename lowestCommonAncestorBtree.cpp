/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 
According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes v and w as the lowest node in T that
has both v and w as descendants (where we allow a node to be a descendant of itself).”
         _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

 For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3.
 Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according
 to the LCA definition.
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

void getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, bool& found)
{
	if (root && !found)
	{
		if (root == target)
		{
			path.push_back(root);
			found = true;
			return;
		}
		else
		{
			path.push_back(root);
			if (root->left && !found)
				getPath(root->left, target, path, found);
			if (root->right && !found)
				getPath(root->right, target, path, found);
			if (!found)
				path.pop_back();
		}
	}
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	bool found = false;
	vector<TreeNode*> path_p;
	vector<TreeNode*> path_q;
	getPath(root, p, path_p, found);
	if (!found)
		return NULL;
	found = false;
	getPath(root, q, path_q, found);
	if (!found)
		return NULL;
	int i = 0;
	while (i < min(path_p.size(), path_q.size()) && path_p[i] == path_q[i])
		i++;
	if (i > 0)
		i--;
	else
		return NULL;
	return path_p[i];
}
