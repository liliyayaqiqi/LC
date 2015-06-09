/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* createBST(vector<int>& nums, int begin, int end)
{
	if (begin == end)
	{
		TreeNode* node = new TreeNode(nums[begin]);
		return node;
	}
	if (begin > end)
		return NULL;
	else
	{
		int mid = (begin + end) / 2;
		TreeNode* node = new TreeNode(nums[mid]);
		node->left = createBST(nums, begin, mid - 1);
		node->right = createBST(nums, mid + 1, end);
		return node;
	}
}
 TreeNode* sortedArrayToBST(vector<int>& nums) {
 	if (nums.empty())
 		return NULL;
 	int begin = 0;
 	int end = nums.size() - 1;
 	TreeNode* root = createBST(nums, begin, end);
 	return root;
}