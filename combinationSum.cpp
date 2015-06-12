/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
The same repeated number may be chosen from C unlimited number of times. 

Note:
 
•All numbers (including target) will be positive integers.
•Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
•The solution set must not contain duplicate combinations.

*/ 
//solution one

void doRecursion(vector<vector<int>>& result, vector<int>& res, int index, int curNum, vector<int>& candidates, int target)
{
	if (curNum == target)
	{
		result.push_back(res);
		return;
	}
	if (curNum > target)
		return;
	for(int i = index; i < candidates.size(); i++)
	{
		int k = (target - curNum) / candidates[i];
		for (int j = 0; j < k; j++)
		{
			res.push_back(candidates[i]);
			curNum += candidates[i];
			doRecursion(result, res, index + 1, curNum, candidates, target);
		}
		for (int j = 0; j < k; j++)
		{
			res.pop_back();
			curNum -= candidates[i];
		}
		index++;
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<int> res;
	vector<vector<int>> result;
	sort(candidates.begin(), candidates.end());
	doRecursion(result, res, 0, 0, candidates, target);
	return result;
}

//solution 2
//减小递归深度会加快计算时间
void doRecursion(vector<vector<int>>& result, vector<int>& res, int index, vector<int>& candidates, int target)
{
	for(int i = index; i < candidates.size(); i++)
	{
		if (target == candidates[i])
		{
			res.push_back(candidates[i]);
			result.push_back(res);
			res.pop_back();
		}
		if (target > candidates[i])
		{
			res.push_back(candidates[i]);
			doRecursion(result, res, i, candidates, target - candidates[i]);
			res.pop_back();
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<int> res;
	vector<vector<int>> result;
	sort(candidates.begin(), candidates.end());
	doRecursion(result, res, 0, 0, candidates, target);
	return result;
}

//solution3: don't need to sort the candidates array
void doRecursion(vector<vector<int>>& result, vector<int>& res, int curNum, vector<int>& candidates, int target)
{
	if (curNum == target)
	{
		result.push_back(res);
		return;
	}
	if (curNum > target)
		return;
	for (int i = 0; i < candidates.size(); i++)
	{
		if (res.empty()||(!res.empty() && candidates[i] > res.back()))
		{
			int k = (target - curNum) / candidates[i];
			for (int j = 0; j < k; j++)
			{
				res.push_back(candidates[i]);
				curNum += candidates[i];
				doRecursion(result, res, curNum, candidates, target);
			}
			for (int j = 0; j < k; j++)
			{
				res.pop_back();
				curNum -= candidates[i];
			}
		}
	}
}
