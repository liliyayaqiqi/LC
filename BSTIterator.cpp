/*
Implement an iterator over a binary search tree (BST). 
Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
public:
	vector<TreeNode*> nodeStack;
	TreeNode* currentNode;
    BSTIterator(TreeNode *root)
    {
    	currentNode = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        if (currentNode || !nodeStack.empty())
        	return true;
        return false;
    }

    /** @return the next smallest number */
    int next()
    {
    	int value = 0;
        while(currentNode)
        {
        	nodeStack.push_back(currentNode);
        	currentNode = currentNode->left;
        }
        if(!nodeStack.empty())
        {
        	currentNode = nodeStack.back();
        	value = currentNode->val;
        	nodeStack.pop_back();
        	currentNode = currentNode->right;
        }
        return value;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */