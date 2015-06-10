/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 
For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 
Your algorithm should run in O(n) complexity. 
*/
//solution: using unordered_set. The realization of unordered_set is based on Hash table
// so the time comlexity is linear. The overall complexity is O(n)

int longestConsecutive(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	unordered_set<int> numSet(nums.begin(), nums.end());
	unordered_set<int>::iterator it = numSet.begin();
	int max = 1;
	while(it != numSet.end())
	{
		int curVal = *it;
		numSet.erase(it);
		int value = curVal;
		int ascending = 1;
		while((it = numSet.find(++value)) != numSet.end())
		{
			ascending++;
			numSet.erase(it);
		}
		value = curVal;
		int descending = 0;
		while((it = numSet.find(--value)) != numSet.end())
		{
			descending++;
			numSet.erase(it);
		}
		max = ascending + descending > max? ascending + descending: max;
		it = numSet.begin();
	}
	return max;
}