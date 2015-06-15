// classic practice of backtracking
// for-loop + recursion = backtracking ?
void backtracking(vector<vector<string>>& result, vector<string>& sol, int n, int rowInd, vector<int>& flag)
{
	if (rowInd == n)
	{
		result.push_back(sol);
		return;
	}
	string rowStr(n, '.');
	for (int j = 0; j < n; j++)
	{
		bool isValid = true;
		if (flag[j] == 1)
			isValid = false;
		else
		{
			int r = rowInd - 1, c = j - 1;
			while (r >= 0 && c >= 0)
			{
				if (sol[r--][c--] == 'Q')
				{
					isValid = false;
					break;
				}
			}
			if (isValid)
			{
				r = rowInd - 1, c = j + 1;
				while (r >= 0 && c < n)
				{
					if (sol[r--][c++] == 'Q')
					{
						isValid = false;
						break;
					}
				}
			}
		}
		if (isValid)
		{
			rowStr[j] = 'Q';
			flag[j] = 1;
			sol.push_back(rowStr);
			backtracking(result, sol, n, rowInd + 1, flag);
			rowStr[j] = '.';
			flag[j] = 0;
			sol.pop_back();
		}
	}
}
vector<vector<string> > solveNQueens(int n)
{
	vector<vector<string>> result;
	vector<string> sol;
	vector<int> flag(n, 0);
	backtracking(result, sol, n, 0, flag);
	return result;
}