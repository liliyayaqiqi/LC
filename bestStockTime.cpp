int maxProfit(vector<int>& prices) {
	if (prices.empty())
		return 0;
	else
	{
		int min = prices[0];
		int maxProfit = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] < min)
				min = prices[i];
			else
			{
				if (prices[i] - min > maxProfit)
					maxProfit = prices[i] - min;
			}
		}
		return maxProfit;
	}
}