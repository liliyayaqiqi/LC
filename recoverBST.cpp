/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure. 
Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
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

 void findNodes(TreeNode* root, TreeNode* &ptr1, TreeNode* &ptr2, TreeNode*& prev)
 {
 	if (!root)
 		return;
 	if (root->left)
 		findNodes(root->left, ptr1, ptr2, prev);
 	if (prev != NULL && prev->val > root->val)
 	{
 		if (!ptr1)
 			ptr1 = prev;
 		ptr2 = root;
 		if (cnt == 2)
 			return;
 	}
 	prev = root;
 	if (root->right)
 		findNodes(root->right, ptr1, ptr2, prev);
 }
 void recoverTree(TreeNode* root)
 {
 	TreeNode *ptr1 = NULL, *ptr2 = NULL, *prev = NULL;
 	findNodes(root, ptr1, ptr2, prev);
 	swap(ptr1->val, ptr2->val);       
 }
