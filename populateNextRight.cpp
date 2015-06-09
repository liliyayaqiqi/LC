<<<<<<< HEAD
/* You may assume that the tree is a perfect binary tree. All leaves are at the
same level and every parent has two children
you can only use constant etra space.
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
    void connect(TreeLinkNode *root) {
    	TreeLinkNode* first_ptr = root;
    	while (first_ptr)
    	{
    		TreeLinkNode* tmp_ptr= first_ptr;
    		first_ptr = first_ptr->left;
    		if (tmp_ptr->left != NULL)
    		{
    			TreeLinkNode* last_right = NULL;
    			while (tmp_ptr)
    			{
    				if (last_right)
    					last_right->next = tmp_ptr->left;
    				tmp_ptr->left->next = tmp_ptr->right;
    				last_right = tmp_ptr->right;
    				tmp_ptr = tmp_ptr->next;
    			}
    			last_right->next = NULL;
    		}
    	}       
    }
=======
/* You may assume that the tree is a perfect binary tree. All leaves are at the
same level and every parent has two children
you can only use constant etra space.
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
    void connect(TreeLinkNode *root) {
    	TreeLinkNode* first_ptr = root;
    	while (first_ptr)
    	{
    		TreeLinkNode* tmp_ptr= first_ptr;
    		first_ptr = first_ptr->left;
    		if (tmp_ptr->left != NULL)
    		{
    			TreeLinkNode* last_right = NULL;
    			while (tmp_ptr)
    			{
    				if (last_right)
    					last_right->next = tmp_ptr->left;
    				tmp_ptr->left->next = tmp_ptr->right;
    				last_right = tmp_ptr->right;
    				tmp_ptr = tmp_ptr->next;
    			}
    			last_right->next = NULL;
    		}
    	}       
    }
>>>>>>> 87b75386303b622fbe386c6ffdfa4ffe0e201c52
