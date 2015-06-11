/*
Given a set of distinct integers, nums, return all possible subsets. 

Note:
 
•Elements in a subset must be in non-descending order.
 •The solution set must not contain duplicate subsets.
*/

void doRecursion(vector<vector<int>>& result, vector<int>& nums, vector<int>& res, vector<int>& flag, int curNum, int n)
{
	if (curNum == n)
	{
		result.push_back(res);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (flag[i] == 0 && (res.empty() || nums[i] >= res.back()))
		{
			res.push_back(nums[i]);
			flag[i] = 1;
			doRecursion(result, nums, res, flag, curNum + 1, n);
			res.pop_back();
			flag[i] = 0;
		}
	}
}
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<vector<int>> result_tmp;
	vector<int> res_tmp;
	result.push_back(res_tmp);
	vector<int> flag(nums.size(), 0);
	for (int i = 1; i <= nums.size(); i++)
	{
		doRecursion(result_tmp, nums, res_tmp, flag, 0, i);
		while (!result_tmp.empty())
		{
			result.push_back(result_tmp.back());
			result_tmp.pop_back();
		}
	}
	return result;
}