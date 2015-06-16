/*
Given a string S and a string T, count the number of distinct subsequences of T in S.
 
A subsequence of a string is a new string which is formed from the original string by deleting some
(can be none) of the characters without disturbing the relative positions of the remaining characters.
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 
Here is an example:
 S = "rabbbit", T = "rabbit" 
Return 3. 
*/
void backtracking(string s, string t, int sIndex, int tIndex, int sLen, int tLen, int& result)
{
	if (sLen < tLen)
		return;
	if (tIndex == tLen)
	{
		result++;
		return;
	}
	for (int i = sIndex; i < s.length(); i++)
	{
		if (s[i] == t[tIndex])
		{
			if (tLen - tIndex > sLen - i)
				return;
			backtracking(s, t, i + 1, tIndex + 1, sLen, tLen, result);
		}
	}
}
int numDistinct(string s, string t)
{
	int result = 0;
	int sLen = s.length();
	int tLen = t.length();
	backtracking(s, t, 0, 0, sLen, tLen, result);
	return result;
}

// 递归超时
/*
动态规划，定义dp[i][j]为字符串i变换到j的变换方法。
如果S[i]==T[j]，那么dp[i][j] = dp[i-1][j-1] + dp[i-1][j]。意思是：如果当前S[i]==T[j]，那么当前这个字母即可以保留也可以抛弃，所以变换方法等于保留这个字母的变换方法加上不用这个字母的变换方法。
如果S[i]!=T[j]，那么dp[i][j] = dp[i-1][j]，意思是如果当前字符不等，那么就只能抛弃当前这个字符。
递归公式中用到的dp[i][0] = 1（把任意一个字符串变换为一个空串只有一个方法）
*/
int numDistinct(string s, string t) {
	int sLen = s.length();
	int tLen = t.length();
	if (sLen == 0 || sLen < tLen)
		return 0;
	vector<vector<int>> dp(sLen + 1, (vector<int>(tLen + 1, 0)));
	for (int i = 0; i < sLen; i++)
		dp[i][0] = 1;
	for (int j = 1; j <= tLen; j++)
	{
		for (int i = 1; i <= sLen; i++)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[sLen][tLen];
}

// reduce the dimensions of the DP table
/*
The idea is to implement a Finite State Machine (FSM) to track the number of distinct subsequences found at stage i.
In the following code, Num is the array and Num[j] is the number of distinct subsequences found for (S[0::i-1], T[0:j-1])
(i.e. how many ways we can get T[0::j-1] from S[0::i-1]) at stage i-1.
In the i for loop, it scans a new char S[i] and if S[i] == T[j] for some j,
then that means all the subsequences of (S[0::i-1], T[0:j-1]) can become the subsequences of (S[0::i], T[0:j]) at stage i.
So Num[j] = Num[j] + Num[j-1].
Otherwise, Num[j] keeps unchanged since no new subsequences are found.
What we need to do is to scan S and update Num accordingly and output Num[tl] at the end.
*/
int numDistinct(string s, string t) {
	int sLen = s.length();
	int tLen = t.length();
	if (sLen == 0 || sLen < tLen)
		return 0;
	vector<int> dp(tLen + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= sLen; i++)
	{
		for (int j = tLen; j >= 1; j--)
		{
			if (t[j - 1] == s[i - 1])
				dp[j] += dp[j - 1];
		}
	}
	return dp[tLen];
}

/*
动态规划法活用总结：
1 二维表：很多问题都可以转化为二维表
2 三维表：比较难理解，时间效率一般是O(n*n*n)
3 二维表变一维表：一般是简化二维表，不需要保存整个表
4 一维表变常量：一般是由一维表简化而来，一维表也不需要保存，只保存当前结果和当前结果需要用的变量就可以
5 逆向填表：根据表进一步抽象简化出来，可以让程序更加简洁，当然也更加更加难理解。

设计动态规划法算法，应该循序渐进，先设计二维表或三维表，然后再简化，进一步优化，再简化，不要一步就写最简化的程序。
熟练之后，可以直接设计表，根据表特征，翻译为程序。
熟练递归回溯法有助于动态规划法的深入理解。
When you see string problem that is about subsequence or matching,
dynamic programming method should come to your mind naturally.
*/