//题目理解错误
int maxProfit(vector<int>& prices) {
	int size = prices.size();
	if (size == 0)
		return 0;
	int min = prices[0];
	int max = prices[0];
	int minIndex = 0;
	int maxIndex = 0;
	int maxVal = 0;
	for (int i = 0; i < size; i++)
	{
		if (prices[i] < min)
		{
			min = prices[i];
			minIndex = i;
		}
		if (prices[i] > max)
		{
			max = prices[i];
			maxIndex = i;
		}
	}
	if (minIndex < maxIndex)
		maxVal = max - min;
	else
	{
		max = 0;
		for (int i = minIndex; i < size; i++)
		{
			if (prices[i] > max)
				max = prices[i];
		}
		maxVal = max - min;
		max = prices[maxIndex];
		min = max;
		for (int i = 0; i < maxIndex; i++)
		{
			if (prices[i] < min)
				min = prices[i];
		}
		maxVal = (max - min > maxVal) ? max - min : maxVal;
	}
	return maxVal;
}