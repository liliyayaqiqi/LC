/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if(matrix.empty())
		return false;
	int row = matrix.size();
	int col = matrix[0].size();
	int rbegin = 0;
	int rend = row - 1;
	while(rbegin <= rend)
	{
		int rmid = (rbegin + rend) / 2;
		if (matrix[rmid][0] == target)
			return true;
		else if (matrix[rmid][0] > target)
			rend = rmid - 1;
		else
			rbegin = rmid + 1;
	}
	int rIndex = 0;
	if (rend < 0)
		rIndex = 0;
	else
		rIndex = rend;
	int cbegin = 0;
	int cend = col - 1;
	while(cbegin <= cend)
	{
		int cmid = (cbegin + cend) / 2;
		if (matrix[rIndex][cmid] == target)
			return true;
		else if (matrix[rIndex][cmid] > target)
			cend = cmid - 1;
		else
			cbegin = cmid + 1;
	}
	return false;
}