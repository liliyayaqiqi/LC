/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 
Note:
 
•Elements in a subset must be in non-descending order.
•The solution set must not contain duplicate subsets.

*/
void doRecursion(vector<vector<int>>& result, vector<int>& res, vector<int>& nums, int k, int index)
{
	if (k == 0)
	{
		result.push_back(res);
		return;
	}
	for (int i = index; i < nums.size(); i++)
	{
		if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
		{
			int nextDiff = i + 1;
			while (nextDiff < nums.size() && nums[nextDiff] == nums[nextDiff - 1])
				nextDiff++;
			int cnt = 0;
			for (int j = i; k > 0 && j < nextDiff; j++)
			{
				cnt++;
				k--;
				res.push_back(nums[j]);
				doRecursion(result, res, nums, k, nextDiff);
			}
			for (int j = 0; j < cnt; j++)
			{
				k++;
				res.pop_back();
			}
		}
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	vector<int> res;
	for (int i = 0; i <= nums.size(); i++)
	{
		res.clear();
		doRecursion(result, res, nums, i, 0);
	}
	return result;
}