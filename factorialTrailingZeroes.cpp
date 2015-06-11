/*
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
*/
/*
idea: compute the number of the factors of 5
j = n/5 + n/25 + n/5^3 + n/5^4 + ...
*/
int trailingZeroes(int n)
{
	int cnt = 0;
	while(n >= 5)
	{
		cnt += n/5;
		n = n/5;
	}
	return cnt;
}
