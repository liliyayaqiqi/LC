/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).
*/

 vector<int> searchRange(vector<int>& nums, int target)
 {
    int start = 0;
	int end = nums.size() - 1;
	int mid = 0;
	while(start <= end)
	{
		mid = (start + end) / 2;
		if (nums[mid] == target)
			break;
		else if (nums[mid] < target)
			start = mid + 1;
		else
			end = mid - 1;

	}
	vector<int> result;
	if (start > end)
	{
		result.push_back(-1);
		result.push_back(-1);
	}
	else
	{
		int left = mid;
		int right = mid;
		while (left - 1 >= 0 && nums[left - 1] == target)
			left--;
		while (right + 1 < nums.size() && nums[right + 1] == target)
			right++;
		result.push_back(left);
		result.push_back(right);
	}
	return result;
}