/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
*/

int rangeBitwiseAnd(int m, int n)
{
	int mask = ~0;
	while (mask)
	{
		if ((mask & m) == (mask &n))
			break;
		mask <<= 1;
	}
	return (mask & m);
}