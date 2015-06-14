/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
*/

bool canJump(vector<int>& nums)
{
	if (nums.empty())
		return false;
	int front = 0;
	int last = nums.size() - 1;
	for (int i = 0; i <= last; i++)
	{
		if (front == last)
			return true;
		if (front == i && nums[i] == 0)
			return false;
		if (front < i + nums[i])
			front = i + nums[i];
	}
}