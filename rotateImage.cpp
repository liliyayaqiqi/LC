/*You are given an n x n 2D matrix representing an image.
 
Rotate the image by 90 degrees (clockwise).
 
Follow up:
 Could you do this in-place?*/
void rotate(vector<vector<int>>& matrix)
{
	int n = 0;
	if(!matrix.empty())
		n = matrix.size();
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		for (int i = 0; i < end - begin; i++)
		{
			int tmp = matrix[begin][begin + i];
			matrix[begin][begin + i] = matrix[end - i][begin];
			matrix[end - i][begin] = matrix[end][end - i];
			matrix[end][end - i] = matrix[begin + i][end];
			matrix[begin + i][end] = tmp;
		}
		begin++;
		end--;
	}
}