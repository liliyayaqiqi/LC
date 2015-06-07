// Exceed the max possible time


class Solution {
public:
	void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	void msort(vector<int>& prices, vector<int>& sortedIndex, int low, int high)
	{
		if (low < high)
		{
			int mid = (low + high) / 2;
			int pivot = prices[mid];
			swap(prices[low], prices[mid]);
			swap(sortedIndex[low], sortedIndex[mid]);
			int last = low;
			int ptr = high;
			while (ptr > last)
			{
				if (prices[ptr] >= pivot)
					ptr--;
				else
				{
					last++;
					swap(prices[last], prices[ptr]);
					swap(sortedIndex[last], sortedIndex[ptr]);
				}
			}
			swap(prices[last], prices[low]);
			swap(sortedIndex[last], sortedIndex[low]);
			msort(prices, sortedIndex, low, last - 1);
			msort(prices, sortedIndex, last + 1, high);
		}
	}
    int maxProfit(vector<int>& prices) {
    	vector<int> sortedIndex;
    	int size = prices.size();
    	for (int i = 0; i < size; i++)
    		sortedIndex.push_back(i+1);
    	msort(prices, sortedIndex, 0, size - 1);
    	int index = 0;
    	int maxVal = 0;
    	while (index < size && sortedIndex[index] > sortedIndex[index - 1])
    		index++;
    	if (index < size - 1)
    		maxVal = prices[size - 1] - prices[index];
    	index = size - 1;
    	while (index > 0 && sortedIndex[index] < sortedIndex [0])
    		index--;
    	if (index > 0)
    		maxVal = (prices[index] - prices[0] > maxVal)? prices[index] - prices[0]: maxVal;
        return maxVal;
    }
};