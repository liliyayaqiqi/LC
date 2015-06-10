/*
Given n non-negative integers representing an elevation map
where the width of each bar is 1, compute how much water it is able to trap after raining.
*/
int trap(vector<int>& height)
{
	int num = height.size();
	if (num < 2)
		return 0;
	int sum = 0;
	int low = 0;
	int high = num - 1;
	int bound0 = height[low];
	int bound1 = height[high];
	while(low < high)
	{
		if (bound0 < bound1)
		{
			int val = height[++low];
			if(val < bound0)
				sum += bound0 - val;
			else
				bound0 = val;
		}
		else
		{
			int val = height[--high];
			if (val < bound1)
				sum += bound1 - val;
			else
				bound1 = val;
		}
	}
	return sum;
}