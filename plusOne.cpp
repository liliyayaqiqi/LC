vector<int> plusOne(vector<int>& digits)
{
	vector<int> result;
	int carry = 0;
	if (digits.empty())
		return result;
	reverse(digits.begin(), digits.end());
	if (digits[0] == 9)
	{
		result.push_back(0);
		carry = 1;
	}
	else
		result.push_back(digits[0] + 1);
	int i = 1;
	while (i < digits.size())
	{
		if(carry)
		{
			if (digits[i] == 9)
				result.push_back(0);
			else
			{
				result.push_back(digits[i] + 1);
				carry = 0;
			}
		}
		else
		result.push_back(digits[i]);
		i++;
	}
	if (carry)
		result.push_back(1);
	reverse(result.begin(), result.end());
	return result;
}