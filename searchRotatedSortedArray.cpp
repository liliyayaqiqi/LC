/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

//idea: keep searching the half that is in order

int search(vector<int>& nums, int target)
{
	if (nums.empty())
		return -1;
	int start = 0;
	int end = nums.size() - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (nums[mid] == target)
			return mid;
		if (nums[start] <= nums[mid]) // the left part is in order
		{
			if (target >= nums[start] && target < nums[mid])
				end = mid - 1;
			else
				start = mid + 1;
		}
		else
		{
			if (target <= nums[end] && target > nums[mid])
				start = mid + 1;
			else
				end = mid -1;
		}
	}
	return -1;
}