/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
/*
pigeon hole principle
Suppose you have n pigeons with labels and you put them into m holes based on their label with each hole of
the same size. Why bother putting pigeons into holes? Because you want to disregard the distance between pigeons
within each one hole. 

Only when at least one hole is empty can we disregard the distance
between pigeons within each one hole and compute the maximum gap solely by the distance between pigeons
in adjacent holes. We make sure that at least one hole is empty by using m=n-1
(i.e. n-2 pigeons in n-1 holes => at least one hole is empty).

*/
int maximumGap(vector<int>& nums)
{
	int n = nums.size();
	if (n < 2)
		return 0;
	int minVal = nums[0];
	int maxVal = nums[0];
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		if (*it > maxVal)
			maxVal = *it;
		if (*it < minVal)
			minVal = *it;
	}
	double interval = double(maxVal - minVal) / double(n - 1); // make sure that at least on slot is empty
	/*
	The maximum value will be the only element in the last slot
	The minimum value will be in the first slot
	The rest n - 2 elements will be distributed from slot 0 to slot n - 2 (n - 1 slots in total)
	so at least on slot is empty
	*/
	vector<int> min(n, -1);
	vector<int> max(n, -1);
	for (vector<int>::iterator it = nums.begin; it != nums.end(); it++)
	{
		int slot = (*it - minVal) / interaval;
		if (*it > max[slot] || max[slot] == -1)
			max[slot] = *it;
		if (*it < min[slot] || min[slot] == -1)
			min[slot] = *it;
	}
	int max_pre = max[0];
	int max_diff = -1;
	for (int i = 1; i < n - 1; i++)
	{
		if (min[i] != -1)
		{
			if (min[i] - max_pre > max_diff || max_diff == -1)
				max_diff = min[i] - max_pre;
			max_pre = max[i];
		}
	}
	return max_diff;
}