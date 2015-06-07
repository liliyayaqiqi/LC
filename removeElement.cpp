//The order of elements can be changed. It doesn't matter what you leave beyond the new length.

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int removeElement(vector<int>& nums, int val)
{
	if(nums.empty())
		return 0;
	int last_pos = nums.size() - 1;
	int index = 0;
	while (index <= last_pos)
	{
		if (nums[index] != val)
			index++;
		else
		{
			while(nums[last_pos] == val)
				last_pos--;
			if (last_pos < index)
				break;
			else
			{
				swap(nums[last_pos], nums[index]);
				index++;
			}
		}
	}
	return last_pos + 1;

}