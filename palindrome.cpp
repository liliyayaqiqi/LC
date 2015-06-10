/*
Determine whether an integer is a palindrome. Do this without extra space.
*/
bool isPalindrome(int x)
{
	int digitNum = 0;
	if (x < 0)
		x = -x;
	int tmp = x;
	while(tmp)
	{
		digitNum++;
		tmp /= tmp;
	}
	tmp = x;
	int high = digitNum - 1;
	int low = 0;
	while (low < high)
	{
		int h = (x / pow(10, high--)) % 10;
		int l = tmp % 10;
		if (h != l)
			return false;
		tmp /=tmp;
		low++;
	}
	return true;
}

//more clean solution
bool isPalindrome(int x)
{
	if (x < 0)
		return false;
	int p1 = 0;
	int p2 = x;
	while(p2)
	{
		p1 = p1 * 10 + p2 % 10;
		p2 /= 10;
	}
	return p1 == x;
}
