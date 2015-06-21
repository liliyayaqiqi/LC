/*
Given two binary strings, return their sum (also a binary string). 
For example,
 a = "11"
 b = "1"
 Return "100".
*/
string addBinary(string a, string b)
{
	if (a.empty())
		return b;
	if (b.empty())
		return a;
	int carryover = 0;
	int aLen = a.length();
	int bLen = b.length();
	int aInd = aLen - 1;
	int bInd = bLen - 1;
	string result = "";
	while (aInd >= 0 && bInd >= 0)
	{
		if (a[aInd] == b[bInd])
		{
			if (a[aInd] == '0')
			{
				if (carryover)
				{
					result += '1';
					carryover--;
				}
				else
					result += '0';
			}
			else
			{
				if (carryover)
					result += '1';
				else
				{
					result += '0';
					carryover++;
				}
			}
		}
		else
		{
			if (carryover)
				result += '0';
			else
				result += '1';
		}
		aInd--;
		bInd--;
	}
	string leftStr;
	int index;
	if (bInd >= 0 || aInd >= 0)
	{
		if (bInd < 0)
		{
			leftStr = a;
			index = aInd;
		}
		else
		{
			leftStr = b;
			index = bInd;
		}
		while (index >= 0)
		{
			if (leftStr[index] == '0')
			{
				if (carryover)
				{
					result += '1';
					carryover--;
				}
				else
					result += '0';
			}
			else
			{
				if (carryover)
					result += '0';
				else
					result += '1';
			}
			index--;
		}
	}
	if (carryover)
		result += '1';
	reverse(result.begin(), result.end());
	return result;
}