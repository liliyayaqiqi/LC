/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
Nodes are labeled uniquely. 
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
unordered_map<int, UndirectedGraphNode*> nodeMap;
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	if (!node)
		return NULL;
	unordered_map<int, UndirectedGraphNode*>::iterator it = nodeMap.find(node->label);
	if (it == nodeMap.end())
	{
		UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
		nodeMap[node->label] = newNode;
		for (int i = 0; i < node->neighbors.size(); i++)
			newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
		return newNode;
	}
	return it->second;
}