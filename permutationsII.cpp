/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
*/
void doRecursion(vector<vector<int>>& result, vector<int>& res, vector<int>& nums, vector<int>& flag, int index)
{
	if (index == nums.size())
	{
		result.push_back(res);
		return;
	}
	for(int i = 0; i < nums.size(); i++)
	{
		bool isValid = true;
		if (flag[i] == 1)
		    isValid = false;
		else
		{
		    int j = i - 1;
		    for(; j >= 0 && nums[j] == nums[i]; j--)
		    {
		        if (flag[j] == 0)
		        {
		            isValid = false;
		            break;
		        }
		    }
		}
		if (isValid)
		{
			flag[i] = 1;
			res.push_back(nums[i]);
			doRecursion(result, res, nums, flag, index + 1);
			flag[i] = 0;
			res.pop_back();
		}
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.empty())
		return result;
	sort(nums.begin(), nums.end());
	vector<int> res;
	vector<int> flag(nums.size(), 0);
	doRecursion(result, res, nums, flag, 0);
	return result;
}