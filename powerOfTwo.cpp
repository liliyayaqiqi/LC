/*
Given an integer, write a function to determine if it is a power of two.
*/
bool isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;
	while (n > 1)
	{
		if (n & 1)
			return false;
		n >>= 1;
	}
	return true;
}