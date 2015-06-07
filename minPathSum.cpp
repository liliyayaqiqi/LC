int minPathSum(vector<vector<int>>& grid) 
{
	if (grid.empty() || grid[0].empty())
		return 0;
	int row = grid.size();
	int col = grid[0].size();
	for (int i = 0; i < row - 1; i++)
		grid[i+1][0] += grid[i][0];
	for (int i = 0; i < col - 1; i++)
		grid[0][i+1] += grid[0][i];
	for (int i = 1; i < row; i++)
	{
		for(int j = 1; j < col; j++)
		{
			if(grid[i-1][j] < grid[i][j-1])
				grid[i][j] += grid[i-1][j];
			else
				grid[i][j] += grid[i][j-1];
		}
	}
	return grid[row-1][col-1];
}