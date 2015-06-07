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
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> value;
    	vector<TreeNode*> nodeStack;
    	TreeNode* node = root;
    	while (node != NULL || !nodeStack.empty())
    	{
    		while (node)
    		{
    			nodeStack.push_back(node);
    			node = node->left;
    		}
    		if(!nodeStack.empty())
    		{
    			node = nodeStack.back();
    			nodeStack.pop_back();
    			value.push_back(node->val);
    			node = node->right;
    		}
    	}
    	return value;
        
    }
};