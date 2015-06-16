/*
Given an array of integers and an integer k,
find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j]
and the difference between i and j is at most k. 
*/

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_map<int, int> numMap; //if use map directly, it will be an ordered map by default
	for(int i = 0; i < nums.size(); i++)
	{
		int val = nums[i];
		if (numMap.find(val) == numMap.end())
			numMap[val] = i;
		else
		{
			if (i - numMap[val] <= k)
				return true;
			numMap[val] = i;
		}
	}
	return false;
}