/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 The binary tree can be any kind of binary trees.
 You can only use constant space.
 */
void connect(TreeLinkNode *root)
{
	TreeLinkNode* parent_node = root;
	while(parent_node)
	{
		TreeLinkNode* first = NULL;
		TreeLinkNode* cptr = NULL;
		while(parent_node && !parent_node->left && !parent_node->right)
			parent_node = parent_node->next;
		if(!parent_node)
			break;
		else if (parent_node->left)
		{
			first = parent_node->left;
			cptr = first;
		}
		else
		{
			first = parent_node->right;
			cptr = first;
		}
		TreeLinkNode* last = NULL;
		while(cptr)
		{
			if(last)
				last->next = cptr;
			last = cptr;
			if (parent_node->right && cptr != parent_node->right)
				cptr = parent_node->right;
			else
			{
				parent_node = parent_node->next;
				while(parent_node && !parent_node->left && !parent_node->right)
					parent_node = parent_node->next;
				if (!parent_node)
					cptr = NULL;
				else
					cptr = parent_node->left != NULL? parent_node->left: parent_node->right;
			}
		}
		parent_node = first;
	}
}

/* use queue to solve this problem
Each iteration will process one level of the binary tree.*/
void connect(TreeLinkNode *root)
{
	queue<TreeLinkNode*> nodeQ;
	if(root)
		nodeQ.push(root);
	while(!nodeQ.empty())
	{
		int num = nodeQ.size();
		TreeLinkNode* last = NULL;
		TreeLinkNode* cur = NULL;
		for(int i = 0; i < num; i++)
		{
			cur = nodeQ.front();
			nodeQ.pop();
			if (last)
				last->next = cur;
			last = cur;
			if(cur->left) nodeQ.push(cur->left);
			if(cur->right) nodeQ.push(cur->right);
		}
	}
}