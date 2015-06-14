/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
TreeNode* doRecursion(vector<int>& inorder, vector<int>& postorder, int inBegin, int inEnd, int postBegin, int postEnd)
{
    if (inBegin < 0 || inEnd > inorder.size() - 1 || inBegin > inEnd)
        return NULL;
    if (postBegin < 0 || postEnd > postorder.size() - 1 || postBegin > postEnd)
        return NULL;
    int val = postorder[postEnd];
    int index = inBegin;
    for (; index <= inEnd; index++)
    {
        if (inorder[index] == val)
            break;
    }
    int leftLength = index - inBegin;
    int rightLength = inEnd - index;
    TreeNode* root = new TreeNode(val);
    root->left = doRecursion(inorder, postorder, inBegin, index - 1, postBegin, postBegin + leftLength - 1);
    root->right = doRecursion(inorder, postorder, index + 1, inEnd, postEnd - rightLength, postEnd - 1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    int inBegin = 0;
    int inEnd = inorder.size() - 1;
    int postBegin = 0;
    int postEnd = inEnd;
    TreeNode* root = doRecursion(inorder, postorder, inBegin, inEnd, postBegin, postEnd);
    return root;
}
