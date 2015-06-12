/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
// Recursion is stupid and slow in this case
void doRecursion(vector<vector<int>>& triangle, int row, int totalRow, int curSum, int& minSum)
{
	if (row == totalRow)
	{
		if (curSum < minSum)
			minSum = curSum;
		return;
	}
	for (int i = 0; i < row; i++)
	{
	    //if (curSum + triangle[row][i] < minSum)
		    doRecursion(triangle, row + 1, totalRow, curSum + triangle[row][i], minSum);
		//if (curSum + triangle[row][i+1] < minSum)
		    doRecursion(triangle, row + 1, totalRow, curSum + triangle[row][i + 1], minSum);
	}
}
int minimumTotal(vector<vector<int> > &triangle)
{
	if (triangle.empty())
		return 0;
	int totalRow = triangle.size();
	int row = 1;
	int curSum = triangle[0][0];
	int minSum = 99999999;
	doRecursion(triangle, row, totalRow, curSum, minSum);
	return minSum;
}
// Do not recurse
int minimumTotal(vector<vector<int> > &triangle)
{
	if (triangle.empty())
		return 0;
	int totalRow = triangle.size();
	if (totalRow == 1)
		return triangle[0][0];
	for(int row = totalRow - 2; row >= 0; row--)
	{
		for(int index = 0; index < row + 1; index++)
			triangle[row][index] += min(triangle[row+1][index], triangle[row+1][index+1]);
	}
	return triangle[0][0];
}
