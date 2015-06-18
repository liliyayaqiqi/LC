/*The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ... */
string countAndSay(int n)
{
	string currStr = "1";
	if (n <= 0)
		return "";
	string lastStr = "1";
	int seqCnt = 1;
	for (; seqCnt < n; seqCnt++)
	{
		currStr = "";
		int index = 1;
		char charVal = lastStr[0];
		char charCnt = '1';
		while (index < lastStr.length())
		{
			if (lastStr[index] != charVal)
			{
				currStr.append(1, charCnt);
				currStr.append(1, charVal);
				charCnt = '1';
				charVal = lastStr[index];
			}
			else
				charCnt++;
			index++;
		}
		currStr.append(1, charCnt);
		currStr.append(1, charVal);
		lastStr = currStr;
	}
	return currStr;
}