/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void doSum(int& sum, int num, TreeNode* node)
{
	if(!node)
		return;
	if (!node->left && !node->right)
	{
		sum += num * 10 + node->val;
		return;
	}
	if (node->left)
		doSum(sum, num * 10 + node->val, node->left);
	doSum(sum, num * 10 + node->val, node->right);

}
int sumNumbers(TreeNode* root)
{
	int sum  = 0;
	int num = 0;
	doSum(sum, num, root);
	return sum;
}
