int findPeakElement(vector<int>& nums)
{
	int n = nums.size();
	if (n == 0)
		return -1;
	if (n == 1)
		return 0;
	if (nums[0] > nums[1])
		return 0;
	if (nums[n-1] > nums[n-2])
		return n - 1;
	int index = 0;
	while(index < n - 1 && nums[index] < nums[index + 1])
		index++;
	return index;
}