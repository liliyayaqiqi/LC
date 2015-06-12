/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.
*/

void doRecursion(vector<vector<int>>& result, vector<int>& res, int curSum, int curNum, int k, int n, int index)
{
	if (curNum == k)
		return;
	for (int i = index; i <= 9; i++)
	{
		if (curNum == k - 1)
		{
			if (curSum + i == n)
			{
				res.push_back(i);
				result.push_back(res);
				res.pop_back();
			}
		}
		else
		{
			if (curSum + i < n)
			{
				res.push_back(i);
				doRecursion(result, res, curSum + i, curNum + 1, k, n, i + 1);
				res.pop_back();
			}
		}
	}
}
vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> result;
	vector<int> res;
	doRecursion(result, res, 0, 0, k, n, 1);
	return result;
}