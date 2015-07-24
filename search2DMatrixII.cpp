/*
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:
•Integers in each row are sorted in ascending from left to right.
•Integers in each column are sorted in ascending from top to bottom. 
For example, 
Consider the following matrix: 
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true. 
Given target = 20, return false.
*/
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.empty())
		return false;
	int row = 0;
	int col = matrix[0].size() - 1;
	while (row < matrix.size() && col >= 0)
	{
		if (matrix[row][col] == target)
			return true;
		if (matrix[row][col] < target)
			row++;
		else
			col--;
	}
	return false;
}

// another solution
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.empty())
		return false;
	int row_size = matrix.size();
	int col_size = matrix[0].size();
	int row = 0;
	while (row < row_size)
	{
		int col_begin = 0;
		int col_end = col_size - 1;
		if (target == matrix[row][0])
			return true;
		if (target < matrix[row][0])
			return false;
		if (target > matrix[row_mid][col_end])
		{
			row++;
			continue;
		}
		while (col_begin <= col_end)
		{
			
			int col_mid = col_begin + (col_end - col_begin) / 2;
			if (target == matrix[row][col_mid])
				return true;
			if (target < matrix[row][col_mid])
				col_end = col_mid - 1;
			else
				col_begin = col_mid + 1;
		}
		row++;
	}
	return false;
}