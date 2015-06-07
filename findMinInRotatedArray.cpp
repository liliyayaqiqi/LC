//You may assume no duplicate exists in the array.
int findMin(vector<int>& nums) 
{
    if (nums.empty())
    	return 0;
    int start = 0;
    int end = nums.size() - 1;
    while (start < end)
    {
    	int mid = (start + end) / 2;
    	if (nums[mid] > nums[start])
    	{
            if (nums[mid] < nums[end])
                end = mid;
            else
                start = mid;
        }
        else
        {
    		if(mid == start && nums[mid] > nums[end])
                start = end;
            else
                end = mid;
        }
    }
    return nums[start];
}