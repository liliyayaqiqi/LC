/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s. 
*/
/* backTracking:
The problem has a nice structure that backtracking naturally fits in.
The structure is, given a starting position idx, we search from idx till the end of the string s.length() - 1.
Once we reach a position i such that the sub-string from idx to i (s.substr(idx, i - idx + 1)) is a palindrome, we add it to a temporary solution sol.
Then we recursively call the same function to process the remaining sub-string.
Once we reach the end of the string, we add sol into a record of the possible solutions res.
Then, backtracking happens!
Remember that at position i, we find s.substr(idx, i - idx + 1) to be a palindrome and we immediately add it to sol.
It is obvious that there may be some position j such that j > i and s.substr(idx, j - idx + 1) is also a palindrome.
So we need to return to the state of starting from position i and finding the next palindrome position after i.
And we simply need to pop s.substr(idx, i - idx + 1) out of the sol to make things work.
Putting these together, we can write down the following code, which is self-explanatory.
*/

void getPartition(vector<vector<string>>& result, vector<string>& solution, string s, int idx)
{
	if (idx == s.length())
	{
		result.push_back(solution);
		return;
	}
	for (int i = idx; i < s.length(); i++)
	{
		int l = idx, r = i;
		bool isPalindrome = true;
		while(l < r)
		{
			if (s[l++] != s[r--])
			{
				isPalindrome = false;
				break;
			}
		}
		if (isPalindrome)
		{
			solution.push_back(s.substr(idx, i - idx + 1));
			getPartition(result, solution, s, i + 1);
			solution.pop_back();
		}
	}
}
vector<vector<string>> partition(string s)
{
	vector<vector<string>> result;
	vector<string> solution;
	getPartition(result, solution, s, 0);
	return result;
}