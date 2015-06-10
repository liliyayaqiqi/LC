//Given numRows, generate the first numRows of Pascal's triangle.vector<vector<int>> generate(int numRows)
vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> result;
	vector<int> lastRow;
	for(int i = 1; i <= numRows; i++)
	{
		vector<int> row;
		if (i == 1)
		{
			row.push_back(1);
			result.push_back(row);
			lastRow = row;
			continue;
		}
		row.push_back(1);
		for (int k = 1; k < lastRow.size(); k++)
			row.push_back(lastRow[k] + lastRow[k - 1]);
		row.push_back(1);
		result.push_back(row);
		lastRow = row;
	}
	return result;
}