/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
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

 void doRecursion(vector<vector<int>>& result, vector<int>& res, TreeNode* ptr, int curSum, int sum)
 {
 	if (!ptr)
 		return;
 	if (!ptr->left && !ptr->right)
 	{
 		if (curSum + ptr->val == sum)
 		{
 			res.push_back(ptr->val);
 			result.push_back(res);
 			res.pop_back(ptr->val);
 		}
 		return;
 	}
 	res.push_back(ptr->val);
 	if (ptr->left)
 		doRecursion(result, res, ptr->left, curSum + ptr->val, sum);
 	if (ptr->right)
 		doRecursion(result, res, ptr->right, curSum + ptr->val, sum);
 	res.pop_back(ptr->val);
 }
vector<vector<int>> pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> result;
	vector<int> res;
	doRecursion(result, res, root, 0, sum);
	return result;
}