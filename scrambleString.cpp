/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively. 
To scramble the string, we may choose any non-leaf node and swap its two children. 
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

// recursive method
bool isScramble(string s1, string s2)
{
	if (s1.length() != s2.length())
		return false;
	if (s1 == s2)
		return true;
	int charSet[26] = { 0 };
	for (int i = 0; i < s1.length(); i++)
		charSet[s1[i] - 'a']++;
	for (int i = 0; i < s2.length(); i++)
		charSet[s2[i] - 'a']--;
	for (int i = 0; i < 26; i++)
	{
		if (charSet[i] != 0)
			return false;
	}
	bool result = false;
	for (int i = 1; i < s1.length(); i++)
	{
		result = (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
			|| (isScramble(s1.substr(0, i), s2.substr(s2.length() - i, i)) && isScramble(s1.substr(i), s2.substr(0, s2.length() - i)));
		if (result)
			break;
	}
	return result;
}

//three dimensional DP-> very very slow
bool isScramble(string s1, string s2)
{
	if (s1.length() != s2.length())
		return false;
	if (s1 == s2)
		return true;
	int len = s1.length();
	vector<vector<vector<bool>>> dpTable(len + 1, vector<vector<bool>>(len, vector<bool>(len, false)));
	for (int i = len - 1; i >= 0; i--)
	{
		for (int j = len - 1; j >= 0; j--)
		{
			for (int n = 1; n <= min(len - i, len - j); n++)
			{
				if (s1.substr(i + n) == s2.substr(j + n))
					dpTable[n][i][j] = true;
				else
				{
					for (int k = 1; k < n; k++)
					{
						dpTable[n][i][j] = (dpTable[k][i][j] && dpTable[n - k][i + k][j + k])
							|| (dpTable[k][i][j + n - k] && dpTable[n - k][i + k][j]);
						if (dpTable[n][i][j])
							break;
					}
				}
			}
		}
	}
	return dpTable[len][0][0];
}