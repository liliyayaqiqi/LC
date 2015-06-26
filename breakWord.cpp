/*
Given a string s and a dictionary of words dict,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.
For example, given
 s = "leetcode",
 dict = ["leet", "code"]. 
Return true because "leetcode" can be segmented as "leet code". 
Given a string s and a dictionary of words dict,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.
For example, given
 s = "leetcode",
 dict = ["leet", "code"]. 
Return true because "leetcode" can be segmented as "leet code". 
*/

//recursive solution: time exceeded.
bool doBreakingWord(string s, unordered_set<string>& wordDict, set<string::size_type> wordLen)
{
	if (s.empty())
		return true;
	set<string::size_type>::iterator it = wordLen.begin();
	if (s.length() < *it)
		return false;
	for (; it != wordLen.end(); it++)
	{
		if (s.length() < *it)
			break;
		string match = s.substr(0, *it);
		if (wordDict.find(match) != wordDict.end())
		{
			if (doBreakingWord(s.substr(*it), wordDict, wordLen))
				return true;
		}
	}
	return false;
}
bool wordBreak(string s, unordered_set<string>& wordDict)
{
	if (wordDict.empty() || s.empty())
		return false;
	set<string::size_type> wordLen;
	for (auto word : wordDict)
		wordLen.insert(word.length());
	return doBreakingWord(s, wordDict, wordLen);
}

// recursive solution: use a vector to record the results
// DP solution
//-> to solve the string matching problems, please always use the DP method
bool wordBreak(string s, unordered_set<string>& wordDict)
{
	if (wordDict.empty() || s.empty())
		return false;
	vector<int> result(s.length() + 1, 0);
	result[s.length()] = 1;
	unordered_set<string>::iterator it = wordDict.begin();
	auto min = it->length();
	auto max = it->length();
	for (auto word : wordDict)
	{
		if (word.length() < min)
			min = word.length();
		if (word.length() > max)
			max = word.length();
	}
	for (int i = s.length(); i >= 0; i--)
	{
		for (auto j = min; j <= max; j++)
		{
			if (i + j - 1 >= s.length())
				break;
			if (result[i + j] == 1)
			{
				string match = s.substr(i, j);
				if (wordDict.find(match) != wordDict.end())
				{
					result[i] = 1;
					break;
				}
			}
		}
	}
	return result[0] == 1;
}