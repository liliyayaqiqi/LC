/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values.
 (ie, from left to right, level by level from leaf to root).
*/

 vector<vector<int>> levelOrderBottom(TreeNode* root) 
 {
 	vector<vector<int>> result;
 	vector<vector<int>> buffer;
 	queue<TreeNode*> nodeQ;
 	TreeNode* ptr = root;
 	if(root)
 		nodeQ.push(ptr);
 	while(!nodeQ.empty())
 	{
 		int num = nodeQ.size();
 		vector<int> level;
 		for(int i = 0; i < num; i++)
 		{
 			ptr = nodeQ.front();
 			level.push_back(ptr->val);
 			nodeQ.pop();
 			if (ptr->left)
 				nodeQ.push(ptr->left);
 			if (ptr->right)
 				nodeQ.push(ptr->right);
 		}
 		buffer.push_back(level);
 	}
 	while(!buffer.empty())
 	{
 		result.push_back(buffer.back());
 		buffer.pop_back();
 	}
 	return result;
 }

 //second solution: using reverse()
 vector<vector<int>> levelOrderBottom(TreeNode* root) 
 {
 	vector<vector<int>> result;
 	queue<TreeNode*> nodeQ;
 	TreeNode* ptr = root;
 	if(root)
 		nodeQ.push(ptr);
 	while(!nodeQ.empty())
 	{
 		int num = nodeQ.size();
 		vector<int> level;
 		for(int i = 0; i < num; i++)
 		{
 			ptr = nodeQ.front();
 			level.push_back(ptr->val);
 			nodeQ.pop();
 			if (ptr->left)
 				nodeQ.push(ptr->left);
 			if (ptr->right)
 				nodeQ.push(ptr->right);
 		}
 		result.push_back(level);
 	}
 	reverse(result.begin(), result.end());

 	return result;
 }
