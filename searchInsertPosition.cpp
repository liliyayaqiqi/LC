int searchInsert(vector<int>& nums, int target) {
	if (nums.empty())
		return 0;
	int start = 0;
	int end = nums.size() - 1;
	while (start < end)
	{
		int mid = (end + start) / 2;
		if (nums[mid] < target)
			start = mid + 1;
		else
		{
			if (nums[mid] == target)
				return mid;
			end = mid - 1;
		}
	}
	if (nums[start] == target)
		return start;
	else
	{
		if (nums[start] < target)
			return start + 1;
		return start;
	}
}