/*
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

//So many corner cases to take into account

int reverse(int x)
{
	int result = 0;
	bool negative = false;
	int maxLimit = pow(2, 31) - 1;
	if (x < 0)
	{
		if (x == 0 - maxLimit - 1)
			return 0;
		else
			x = 0 - x;
		negative = true;
	}
	bool countZero = false;
	while (x)
	{
		int digit = x % 10;
		if (digit || countZero)
		{
			countZero = true;
			if (result > maxLimit / 10)
				return 0;
			result = result * 10 + digit;
		}
		x /= 10;
	}
	return negative? (0 - result): result;
}