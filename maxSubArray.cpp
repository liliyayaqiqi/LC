/*Find the contiguous subarray within an array 
(containing at least one number) which has the largest sum.*/
int maxSubArray(vector<int>& nums) {
    int sum = 0;
	int maxSum = 0;
	if (!nums.empty())
	maxSum = nums[0];
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		if (sum + *it > 0)
		{	
		    sum += *it;
		    maxSum = sum > maxSum? sum: maxSum;
		}
		else
		｛
		    if (sum == 0 && *it > maxSum)
		    maxSum = *it;
		    sum = 0;
		 ｝
	}
	return maxSum;
}    