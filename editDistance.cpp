/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
(each operation is counted as 1 step.)
You have the following 3 operations permitted on a word: 
a) Insert a character
b) Delete a character
c) Replace a character
*/

int minDistance(string word1, string word2)
{
	if (word1.length() == 0)
		return word2.length();
	if (word2.length() == 0)
		return word1.length();
	vector<vector<int>> dp(word2.length(), (vector<int>(word1.length(), 0)));
	if (word1[0] == word2[0])
		dp[0][0] = 0;
	else
		dp[0][0] = 1;
	bool firstEq = true;
	for(int i = 1; i < word1.length(); i++)
	{
		if (word1[i] == word2[0] && firstEq && dp[0][0] != 0)
		{
			dp[0][i] = dp[0][i - 1];
			firstEq = false;
		}
		else
			dp[0][i] = dp[0][i - 1] + 1;
	}
	firstEq = true;
	for (int i = 1; i < word2.length(); i++)
	{
		if (word2[i] == word1[0] && firstEq && dp[0][0] != 0)
		{
			dp[i][0] = dp[i - 1][0];
			firstEq = false;
		}
		else
			dp[i][0] = dp[i - 1][0] + 1;
	}
	for (int i = 1; i < word2.length(); i++)
	{
		for (int j = 1; j < word1.length(); j++)
		{
			int up = dp[i - 1][j] + 1;
			int left = dp[i][j - 1] + 1;
			int diagonal = dp[i - 1][j - 1] + 1;
			if (word2[i] == word1[j])
				diagonal--;
			dp[i][j] = min(min(up, left), diagonal);
		}
	}
	return dp[word2.length() - 1][word1.length() - 1];
}

// Add more space to skip the additional work for border check

int minDistance(string word1, string word2)
{
	if (word1.length() == 0)
		return word2.length();
	if (word2.length() == 0)
		return word1.length();
	vector<vector<int>> dp(word2.length() + 1, (vector<int>(word1.length() + 1, 0)));
	for(int i = 0; i <= word1.length(); i++)
		dp[0][i] = i;
	for (int i = 1; i <= word2.length(); i++)
		dp[i][0] = i;
	for (int i = 1; i <= word2.length(); i++)
	{
		for (int j = 1; j <= word1.length(); j++)
		{
			int up = dp[i - 1][j] + 1;
			int left = dp[i][j - 1] + 1;
			int diagonal = dp[i - 1][j - 1] + 1;
			if (word2[i - 1] == word1[j - 1])
				diagonal--;
			dp[i][j] = min(min(up, left), diagonal);
		}
	}
	return dp[word2.length()][word1.length()];
}
