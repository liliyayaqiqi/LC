int removeDuplicates(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	vector<int>::iterator next = nums.begin();
	vector<int>::iterator it = nums.begin();
	while(it != nums.end())
	{
		while (it != nums.end() && *next == *it)
			it++;
		if (it == nums.end())
			break;
		*(++next) = *(it++);
	}
	return next - nums.begin() + 1;
}