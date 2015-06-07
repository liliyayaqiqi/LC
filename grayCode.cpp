vector<int> grayCode(int n) {
	int total = pow(2, n);
	vector<int> result;
	for (int i = 0; i < total; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			int cycle = pow(2, j);

			if ((i / cycle) % 2)
			{
				if ( i % cycle < cycle / 2)
					sum += pow(2, j - 1);
			}
			else
			{
				if (i % cycle >= cycle/2)
					sum += pow(2, j - 1);
			}
		}
		result.push_back(sum);
	}
	return result;       
}