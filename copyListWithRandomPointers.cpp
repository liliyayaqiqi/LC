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
	RandomListNode* copiedNode = NULL;
	if (map.find(ptr) == map.end())
	{
		copiedNode = new RandomListNode(ptr->label);
		map[ptr] = copiedNode;
	}
	else
		return map[ptr];
	if (ptr->next)
		copiedNode->next = doCopy(map, ptr->next);
	if (ptr->random)
		copiedNode->random = doCopy(map, ptr->random);
	return copiedNode;
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
	}
	for (int i = 1; i < reserveNode.size(); i++)
	{
		ptr = reserveNode[i];
		reseveNode[i - 1]->next = ptr;
	}
	if (ptr)
		ptr->next = NULL:
	return newHead;
}
//solution 3
RandomListNode *copyRandomList(RandomListNode* head)
{
    RandomListNode *newHead = NULL;
	RandomListNode *ptr = head;
	while(ptr) // append the copied nodes to the original list
	{
		RandomListNode* copiedNode = new RandomListNode(ptr->label);
		copiedNode->next = ptr->next;
		ptr->next = copiedNode;
		ptr = copiedNode->next;
		if (!newHead)
			newHead = copiedNode;
	}
	ptr = head;
	while(ptr) // copy the random link
	{
		if (ptr->random)
			ptr->next->random = ptr->random->next;
		ptr = ptr->next->next;
	}
	ptr = head;
	while(ptr)
	{
		RandomListNode* tmp = ptr->next->next;
		if (tmp)
			ptr->next->next = ptr->next->next->next;
		ptr->next = tmp;
		ptr = ptr->next;
	}
	return newHead;
}

