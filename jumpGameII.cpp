/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position. 
Your goal is to reach the last index in the minimum number of jumps. 
For example:
 Given array A = [2,3,1,1,4] 
The minimum number of jumps to reach the last index is 2.
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */
// The solution below will result in time exceeding
// The time complexity in worst case is o(n^2)
 int jump(vector<int>& nums)
 {
 	if (nums.empty())
 		return 0;
 	vector<int> front(nums);
 	int cnt = 0;
 	int lastIndex = -1;
 	for (int i = 0; i < front.size(); i++)
 	{
 		front[i] += i;
 		if (front[i] >= front.size() - 1)
 		{
 			lastIndex = i;
 			break;
 		}
 	}
 	if (lastIndex == -1)
 		return 0;
 	cnt++;
 	while (lastIndex > 0)
 	{
 		int index = -1;
 		for (int i = 0; i < lastIndex; i++)
 		{
 			if (front[i] >= lastIndex)
 			{
 				index = i;
 				break;
 			}
 		}
 		if (index < 0)
 			return 0;
 		lastIndex = index;
 		cnt++;
 	}
 	return cnt;
 }

 //to traverse the array forward
int jump(vector<int>& nums)
{
	if (nums.size() <= 1)
		return 0;
	int pos = 0;
	int maxjump = 0;
	int nextPos = 0;
	int cnt = 0;
	while (nums[pos] + pos < nums.size() - 1)
	{
		int tmp = nums[pos] + pos;
		nextPos = tmp;
		for (int i = pos + 1; i < tmp; i++)
		{
			if (nums[i] + i > nextPos + nums[nextPos])
				nextPos = i;
		}
		pos = nextPos;
		cnt++;
	}
	return cnt + 1;
}
