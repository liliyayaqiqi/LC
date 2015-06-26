/*
Given an array of n positive integers and a positive integer s,
find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
 the subarray [4,3] has the minimal length under the problem constraint. 

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

int minSubArrayLen(int s, vector<int>& nums)
{
	if (nums.empty())
		return 0;
	decltype(nums.size()) begin = 0;
	decltype(nums.size()) end = 0;
	int curLen = 0;
	int minLen = INT_MAX;
	int curSum = 0;
	while (end < nums.size())
	{
		while (end < nums.size() && curSum < s)
		{
			curSum += nums.at(end);
			curLen++;
			end++;
		}
		if (curSum >= s && curLen < minLen)
			minLen = curLen;
		while (begin < end && curSum >= s)
		{
			curLen--;
			curSum -= nums.at(begin);
			if (curSum >= s && curLen < minLen)
				minLen = curLen;
			begin++;
		}
	}
	if (minLen < INT_MAX)
		return minLen;
	return 0;
}