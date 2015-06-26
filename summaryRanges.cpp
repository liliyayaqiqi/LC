/*
Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
*/
string num2Str(int num)
{
	string res;
	int tmp = num;
	if (tmp > INT_MIN && tmp < 0)
		tmp = 0 - tmp;
	else
	{
		if (tmp == INT_MIN)
			tmp = INT_MAX;
	}
	while (tmp)
	{
		char digit = '0' + tmp % 10;
		res = digit + res;
		tmp /= 10;
	}
	if (num < 0)
		res = '-' + res;
	if (num == INT_MIN)
		res[res.size() - 1]++;
	if (num == 0)
		res += '0';
	return res;
}
vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> result;
	if (nums.empty())
		return result;
	int currPos = 1;
	int lastPos = 0;
	while (currPos < nums.size())
	{
		if (nums[currPos - 1] < INT_MAX && nums[currPos] == nums[currPos - 1] + 1)
			currPos++;
		else
		{
			string res = num2Str(nums[lastPos]);
			if (currPos - 1 > lastPos)
			{
				res += "->";
				res += num2Str(nums[currPos - 1]);
			}
			result.push_back(res);
			lastPos = currPos;
			currPos++;
		}
	}
	string res = num2Str(nums[lastPos]);
	if (currPos - 1 > lastPos)
	{
		res += "->";
		res += num2Str(nums[currPos - 1]);
	}
	result.push_back(res);
	return result;
}
