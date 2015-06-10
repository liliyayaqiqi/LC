/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void connect(TreeLinkNode *root)
{
	queue<TreeLinkNode*> nodeQ;
	if (root)
		nodeQ.push(root);
	while(!nodeQ.empty())
	{
		TreeLinkNode* last = NULL;
		int num = nodeQ.size();
		for(int i = 0; i < num; i++)
		{
			TreeLinkNode* ptr = nodeQ.front();
			nodeQ.pop();
			if (ptr->left)
				nodeQ.push(ptr->left);
			if (ptr->right)
				nodeQ.push(ptr->right);
			if(last)
				last->next = ptr;
			last = ptr;
		}
	}
}