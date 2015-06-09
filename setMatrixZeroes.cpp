//a constant space solution
void setZeroes(vector<vector<int>>& matrix)
{
	if (matrix.empty())
		return;
	int row = matrix.size();
	int col = matrix[0].size();
	bool rowFlag = false;
	bool colFlag = false;
	for (int i = 0; i < col; i++)
	{
		if (matrix[0][i] == 0)
		{
			rowFlag = true;
			break;
		}
	}
	for (int i = 0; i < row; i++)
	{
		if (matrix[i][0] == 0)
		{
			colFlag = true;
			break;
		}
	}
	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}
	for (int i = 1; i < row; i++)
	{
		if (matrix[i][0] == 0)
			fill(matrix[i].begin(), matrix[i].end(), 0);
	}
	for (int i = 0; i < col; i++)
	{
		if (matrix[0][i] == 0)
		{
			for (int k = 0; k < row; k++)
				matrix[k][i] = 0;
		}
	}
	if (rowFlag)
		fill(matrix[0].begin(), matrix[0].end(), 0);
	if (colFlag)
	{
		for (int k = 0; k < row; k++)
			matrix[k][0] = 0;
	}
}