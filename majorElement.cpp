/*You may assume that the array is non-empty 
and the majority element always exist in the array.*/
// Use moore's vote algorithm


int majorityElement(vector<int>& nums) {
	int cnt = 0;
	int majority = 0;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		if (cnt == 0)
		{
			majority = *it;
			cnt ++;
		}
		else
		{
			*it == majority ? cnt++ : cnt--;
			if (cnt > nums.size() / 2)
				return majority;
		}
	}
	return majority;       
 }