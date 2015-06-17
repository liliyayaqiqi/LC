/*
Write a function to find the longest common prefix string amongst an array of strings. 
*/
/*void quickSortStrLen(vecotr<string>& strs, int begin, int end)
{
	if (begin >= end)
		return;
	int pivot = (begin + end) / 2;
	swap(strs[begin], strs[pivot]);
	int index = begin;
	int val = strs[begin].length();
	for (int i = begin + 1; i <= end; i++)
	{
		if (strs[i].length() < val)
			swap(strs[++index], strs[i]);
	}
	swap(strs[index], strs[begin]);
	quickSortStrLen(strs, begin, index - 1);
	quickSortStrLen(strs, index + 1, end);
}*/
string longestCommonPrefix(vector<string>& strs)
{
	string result = "";
	if (strs.empty())
		return result;
	int minLength = strs[0].length();
	string minStr = strs[0];
	int minInd = 0;
	for (int i = 1; i < strs.size(); i++)
	{
		if (strs[i].length() < minLength)
		{
			minLength = strs[i].length();
			minStr = strs[i];
			minInd = i;
		}
	}
	for (int i = 0; i < minStr.length(); i++)
	{
		int j = 0;
		for (; j < strs.size(); j++)
		{
			if (j != minInd && strs[j][i] != minStr[i])
				break;
		}
		if (j == strs.size())
			result += minStr[i];
		else
			break;
	}
	return result;
}