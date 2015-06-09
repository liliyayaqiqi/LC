/* 00->01->10->00
*/
int singleNumber(vector<int>& nums) {
	int ones = 0;
	int twos = 0;
	int xthree = 0;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		twos |= ones & *it;
		ones ^= *it;
		xthree = ~(twos & ones);
		twos &= xthree;
		ones &= xthree;
	}
	return ones;
}
