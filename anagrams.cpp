/*
Given an array of strings, return all groups of strings that are anagrams. 
Note: All inputs will be in lower-case.
note: the strings in the array have the same length.
*/
void sortString(string& str, int begin, int end)
{
	if (begin >= end)
		return;
	int pivot = (begin + end) / 2;
	swap(str[begin], str[pivot]);
	int index = begin;
	for (int i = begin + 1; i <= end; i++)
	{
		if (str[i]< str[begin])
			swap(str[++index], str[i]);
	}
	swap(str[index], str[begin]);
	sortString(str, begin, index - 1);
	sortString(str, index + 1, end);
}
vector<string> anagrams(vector<string>& strs)
{
	vector<string> result;
	if (strs.empty())
		return result;
	unordered_map<string, int> strMap;
	for (int i = 0; i < strs.size(); i++)
	{
		string s = strs[i];
		sortString(s, 0, s.length() - 1);
		if (strMap.find(s) == strMap.end())
		{
			strMap[s] = i;
		}	
		else
		{
			if (strMap[s] >= 0)
			{
				result.push_back(strs[strMap.find(s)->second]);
				strMap[s] = -1;
			}
			result.push_back(strs[i]);
		}
	}
	return result;
}