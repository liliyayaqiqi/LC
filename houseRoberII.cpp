/*
This time, all houses at this place are arranged in a circle.
Break the circle, sub problems: if we rob the first house or not
*/
int rob(vector<int>& nums)
{
	int size = nums.size();
	if (size == 0)
		return 0;
	if (size == 1)
		return nums[0];
	if (size == 2)
		return max(nums[0], nums[1]);
	int robFirst, notRobFirst;
	vector<int> v2(nums);
	v2[0] = 0;
	nums[1] = max(nums[0], nums[1]);
	for (int i = 2; i < size; i++)
		nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);
	robFirst = nums[size - 2];
	for (int i = 2; i < size; i++)
		v2[i] = max(v2[i - 2] + v2[i], v2[i - 1]);
	notRobFirst = v2[size - 1];
	return max(robFirst, notRobFirst);
}