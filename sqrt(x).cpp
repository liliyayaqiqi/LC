/*
Implement int sqrt(int x).
Compute and return the square root of x.
*/
// newtons function is very mathematical. please refer to online sources.
int mySqrt(int x)
{
	if (x < 0)
		return 0;
	if (x == 0 || x == 1)
		return x;
	int begin = 1;
	int end = min(x / 2 + 1, 46340);
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		int tmp = mid * mid;
		if (tmp == x)
			return mid;
		if (tmp < x)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	return end;
}