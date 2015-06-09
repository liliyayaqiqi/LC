/*
What if duplicates are allowed at most twice?
*/
int removeDuplicates(vector<int>& nums)
{
	if (nums.size() < 2)
		return nums.size();
	vector<int>::iterator curPos = nums.begin();
	vector<int>::iterator nextPos = nums.begin();
	curPos++;
	while(curPos != nums.end())
	{
		if(*curPos == *nextPos)
			*(++nextPos) = *(curPos++);
		while(curPos != nums.end() && *nextPos == *curPos)
			curPos++;
		if (curPos != nums.end())
		*(++nextPos) = *(curPos++);
	}
	return nextPos - nums.begin() + 1;
}