/*
Given an array S of n integers,
find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.
*/
int threeSumClosest(vector<int>& nums, int target)
{
	if (nums.size() < 3)
		return 0;
	sort(nums.begin(), nums.end());
	int closest = 0;
	int minDiff = INT_MAX;
	for(int i = 0; i < nums.size() - 2; i++)
	{
		int diff = target - nums[i];
		int low = i + 1;
		int high = nums.size() - 1;
		while(low < high)
		{
		    int newDiff = abs(diff - nums[low] - nums[high]);
			if (newDiff == 0)
				return target;
			if (newDiff < minDiff)
			{
				minDiff = newDiff;
				closest = nums[i] + nums[low] + nums[high];
			}
			if (nums[low] + nums[high] > diff)
				high--;
			else
				low++;
		}
	}
	return closest;      
}