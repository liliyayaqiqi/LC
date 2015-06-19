/*
Implement Trie (Prefix Tree)
You may assume that all inputs are consist of lowercase letters a-z. 
*/
class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() : isWord(false)
	{
		memset(children, NULL, 26 * sizeof(TrieNode*));
	}
	bool isWord;
	TrieNode* children[26];
};

class Trie {
public:
	Trie()
	{
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string s)
	{
		TrieNode* ptr = root;
		for (int i = 0; i < s.length(); i++)
		{
			int index = s[i] - 'a';
			if (ptr->children[index] == NULL)
			{
				TrieNode* newNode = new TrieNode();
				ptr->children[index] = newNode;
				ptr = newNode;
			}
			else
				ptr = ptr->children[s[i] - 'a'];
		}
		if (ptr != root)
			ptr->isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string key)
	{
		TrieNode* ptr = root;
		bool isFound = true;
		for (int i = 0; i < key.length(); i++)
		{
			if (ptr->children[key[i] - 'a'] == NULL)
			{
				isFound = false;
				break;
			}
			else
				ptr = ptr->children[key[i] - 'a'];
		}
		if (ptr && ptr->isWord == false)
			isFound = false;
		return isFound;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix)
	{
		TrieNode* ptr = root;
		bool exist = true;
		for (int i = 0; i < prefix.length(); i++)
		{
			if (ptr->children[prefix[i] - 'a'] == NULL)
			{
				exist = false;
				break;
			}
			else
				ptr = ptr->children[prefix[i] - 'a'];
		}
		return exist;
	}
	void overView(TrieNode* ptr)
	{
		if (!ptr)
			return;
		bool isLeaf = true;
		for (int i = 0; i < 26; i++)
		{
			if (ptr->children[i])
			{
				char s = 'a' + i;
				cout << s;
				overView(ptr->children[i]);
				isLeaf = false;
			}
		}
		if (isLeaf)
			cout << endl;
	}
	void trieTrasversal()
	{
		overView(root);
	}
private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");