int maxProfit(vector<int>& prices) {
	int size = prices.size();
	int maxVal = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		if (prices[i] < prices[i+1])
			maxVal += prices[i+1] - prices[i];
	}
	return maxVal;
}