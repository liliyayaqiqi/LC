/*Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T. 
Each number in C may only be used once in the combination. 
Note: 
•All numbers (including target) will be positive integers.
 •Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 •The solution set must not contain duplicate combinations.
 */

void sortNumVect(vector<int>& nums, int begin, int end)
{
	if (begin >= end)
		return;
	int pivot = (begin + end) / 2;
	swap(nums[begin], nums[pivot]);
	int index = begin;
	for (int i = begin + 1; i <= end; i++)
	{
		if (nums[i] < nums[begin])
			swap(nums[++index], nums[i]);
	}
	swap(nums[index], nums[begin]);
	sortNumVect(nums, begin, index - 1);
	sortNumVect(nums, index + 1, end);
}

void backtracking(vector<vector<int>>& result, vector<int>& sol, vector<int>& candidates, int target, int index, int curSum)
{
	while (index < candidates.size())
	{
		int val = candidates[index];
		int nextEle = index;
		while (nextEle < candidates.size() && candidates[nextEle] == val)
			nextEle++;
		int numPush = 0;
		for (int k = index; k < nextEle; k++)
		{
			if (curSum + val > target)
				break;
			else if (curSum + val == target)
			{
				numPush++;
				curSum += val;
				sol.push_back(val);
				result.push_back(sol);
				break;
			}
			else
			{
				numPush++;
				sol.push_back(val);
				curSum += val;
				backtracking(result, sol, candidates, target, nextEle, curSum);
			}
		}
		if (numPush == 0)
			break;
		for (int t = 0; t < numPush; t++)
		{
			sol.pop_back();
			curSum -= val;
		}
		index = nextEle;
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	vector<vector<int>> result;
	vector<int> sol;
	sortNumVect(candidates, 0, candidates.size() - 1);
	backtracking(result, sol, candidates, target, 0, 0);
	return result;
}