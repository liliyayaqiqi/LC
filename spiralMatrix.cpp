vector<vector<int>> generateMatrix(int n) 
{
	vector<vector<int>> matrix;
	for (int i = 0; i < n; i++)
	{
		vector<int> row;
		for(int j = 0; j < n; j++)
			row.push_back(0);
		matrix.push_back(row);
	}
	int val = 1;
	int begin = 0;
	int end = n - 1;
	while (begin <= end)
	{
		for (int i = 0; i < end - begin + 1; i++)
			matrix[begin][begin+i] = val++;
		for (int i = 1; i < end - begin + 1; i++)
			matrix[begin + i][end] = val++;
		for (int i = 1; i < end - begin + 1; i++)
			matrix[end][end - i] = val++;
		for (int i = 1; i < end - begin; i++)
			matrix[end - i][begin] = val++;
		begin++;
		end--;
	}
	return matrix;
}