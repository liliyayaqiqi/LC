/*
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
*/
//Could you come up with an one-pass algorithm using only constant space?
void swap (int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void sortColors(vector<int>& nums) 
{
	if (nums.empty())
		return;
	int p_zero = 0;
	int p_two = nums.size() - 1;
	int index = 0;
	while (index <= p_two)
	{
		if (nums[index] == 0)
		{
			while(nums[p_zero] == 0)
				p_zero++;
			if (p_zero > index)
			{
				index = p_zero;
				continue;
			}
			else
				swap(nums[index], nums[p_zero]);
		}
		if (nums[index] == 2)
		{
			while(nums[p_two] == 2)
				p_two--;
			if (p_two < index)
			{
				break;
			}
			else
				swap(nums[index], nums[p_two]);
		}
		if (nums[index] == 1)
			index++;
	}

}