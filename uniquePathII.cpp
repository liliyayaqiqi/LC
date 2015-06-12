/*
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
*/

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	if(obstacleGrid.empty())
		return 0;
	int row = obstacleGrid.size();
	int col = obstacleGrid[0].size();
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if (i == 0)
			{
				if (obstacleGrid[i][j] == 1 || (j > 0 && obstacleGrid[i][j-1] == 0))
					obstacleGrid[i][j] = 0;
				else
					obstacleGrid[i][j] = 1;
			}
			else if (j == 0)
			{
				if (obstacleGrid[i][j] == 1 || (i > 0 && obstacleGrid[i-1][j] == 0))
					obstacleGrid[i][j] = 0;
				else
					obstacleGrid[i][j] = 1;
			}
			else
			{
				if(obstacleGrid[i][j] == 1)
					obstacleGrid[i][j] = 0;
				else
					obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
			}
		}
	}
	return obstacleGrid[row-1][col-1];
}