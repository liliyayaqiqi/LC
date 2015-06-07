int calculate (int n, vector<int> &result)
{
	if (n < 0)
		return 0;
	if (n == 0)
	{
		result[0] = 1;
		return 1;
	}
	if (n == 1)
	{
		result[1] = 1;
		return 1;
	}
	int oneStep = result[n - 1];
	int twoStep = result[n - 2];
	oneStep = oneStep > 0? oneStep: calculate(n - 1, result);
	twoStep = twoStep > 0? twoStep: calculate(n - 2, result);
	result[n] = oneStep + twoStep;
	return result[n];
}


int climbStairs(int n) {
	vecotr<int> result;
	for (int i = 0; i < n + 1; i++)
		result.push_back(0);
	return calculate(n, result);   
}