void doPermute(vector<int>& nums, vector<int>& flag, int curNum, vector<int>& cur, vector<vector<int>>& result)
{
	if (curNum > nums.size() - 1)
	{
		result.push_back(cur);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (flag[i] == 0)
		{
			flag[i] = 1;
			cur.push_back(nums[i]);
			doPermute(nums, flag, curNum + 1, cur, result);
			flag[i] = 0;
			cur.pop_back();
		}
	}
}
vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<int> flag;
	vector<int> cur;
	for (int i = 0; i < nums.size(); i++)
		flag.push_back(0);
	doPermute(nums, flag, 0, cur, result);
	return result;
}