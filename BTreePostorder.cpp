//Recursive solution is trivial, could you do it iteratively?
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> postorderTraversal(TreeNode* root) {
	TreeNode* last_pop = NULL;
	TreeNode* ptr = root;
	vector<TreeNode*> stack;
	vector<int> value;
	while(!ptr || !stack.empty())
	{
		while(ptr)
		{
			stack.push_back(ptr);
			ptr = ptr->left;
		}
		ptr = stack.back();
		if(ptr->right == NULL || ptr->right == last_pop)
		{
			value.push_back(ptr->val);
			stack.pop_back();
			last_pop = ptr;
			ptr = NULL:
		}
		else
			ptr = ptr->right;
	}
	return value;       
}