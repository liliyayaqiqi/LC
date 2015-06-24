/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
int maxProfit(vector<int>& prices)
{
	if (prices.empty())
		return 0;
	vector<int> leftMaxProfit(prices.size(), 0);
	vector<int> rightMaxProfit(prices.size(), 0);
	int maxProfit = 0;
	int min = prices.at(0);
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices.at(i) < min)
			min = prices.at(i);
		else
		{
			if (prices.at(i) - min > maxProfit)
				maxProfit = prices.at(i) - min;
		}
		leftMaxProfit.at(i) = maxProfit;
	}
	maxProfit = 0;
	int max = prices.at(prices.size() - 1);
	for (int i = prices.size() - 2; i >= 0; i--)
	{
		if (prices.at(i) > max)
			max = prices.at(i);
		else
		{
			if (maxProfit < max - prices.at(i))
				maxProfit = max - prices.at(i);
		}
		rightMaxProfit.at(i) = maxProfit;
	}
	maxProfit = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		if (leftMaxProfit.at(i) + rightMaxProfit.at(i) > maxProfit)
			maxProfit = leftMaxProfit.at(i) + rightMaxProfit.at(i);
	}
	return maxProfit;
}