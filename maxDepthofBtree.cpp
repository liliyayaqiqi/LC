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
	void calculateDep(int &maxDep, int currentDep, TreeNode* node)
	{
		if (node == NULL)
		{
			maxDep = (currentDep > maxDep)? currentDep : maxDep;
			return;
		}
		calculateDep(maxDep, currentDep + 1, node->left);
		calculateDep(maxDep, currentDep + 1, node->right);
	}
    int maxDepth(TreeNode* root) {
        int maxDep = 0;
        int currentDep = 0;
        calculateDep(maxDep, currentDep, root);
        return maxDep;
    }
};