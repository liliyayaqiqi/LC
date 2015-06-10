vector<int> getRow(int rowIndex)
{
	if (rowIndex < 0)
	{
		vector<int> res;
		return res;
	}
	vector<int> result(rowIndex + 1, 1);
	if (rowIndex == 0)
	{
		result[0] = 1;
		return result;
	}
	for (int i = 1; i < rowIndex; i++)
	{
		int t1 = result[0];
		int t2 = result[1];
		for (int j = 1; j <= i; j++)
		{
			result[j] = t1 + t2;
			t1 = t2;
			t2 = result[j + 1];
		}
	}
	return result;
}