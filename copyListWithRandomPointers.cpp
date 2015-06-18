/*
A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.
Return a deep copy of the list.
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 // solution 1
RandomListNode* doCopy(unordered_map<RandomListNode*, RandomListNode*>& map, RandomListNode* ptr)
{
	if (!ptr)
		return NULL;
	RandomListNode* copyedNode = NULL;
	if (map.find(ptr) == map.end())
	{
		copyedNode = new RandomListNode(ptr->label);
		map[ptr] = copyedNode;
	}
	else
		copyedNode = map[ptr];
	if (ptr->next)
		copyedNode->next = doCopy(map, ptr->next);
	if (ptr->random)
		copyedNode->random = doCopy(map, ptr->random);
	return copyedNode;
}
RandomListNode *copyRandomList(RandomListNode *head)
{
	unordered_map<RandomListNode*, RandomListNode*> map;
	RandomListNode* newHead = doCopy(map, head);
	return newHead;
}

//solution 2
RandomListNode *copyRandomList(RandomListNode* head)
{
	RandomListNode *newHead = NULL;
	RandomListNode *ptr = head;
	vector<RandomListNode*> reserveNode;
	RandomListNode *lastCopied = NULL;
	while(ptr)
	{
		reserveNode.push_back(ptr);
		RandomListNode* tmp = ptr->next;
		RandomListNode* copiedNode = new RandomListNode(ptr->label);
		ptr->next = copiedNode;
		if (lastCopied)
			lastCopied->next = copiedNode;
		else
			newHead = copiedNode;
		lastCopied = copiedNode;
		ptr = tmp;
	}
	for(int i = 0; i < reserveNode.size(); i++)
	{
		ptr = reserveNode[i];
		if (ptr->random)
			ptr->next->random = ptr->random->next;
		if (i > 0)
			reserveNode[i - 1]->next = reserveNode[i];
	}
	return newHead;
}
