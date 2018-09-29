class Solution {
public:
   //Use DP
   string longestPalindrome(string s) {
      int n = s.size();
      string result;
      if (n == 0)
      {
         return result;
      }
      bool dp[n][n] = {false};
      for (int i = 0; i < n; ++i)
      {
         dp[i][i] = true;
         if (i < n-1)
         {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            if (dp[i][i + 1] && result.size() < 2)
            {
               result = s.substr(i, 2);
            }
         }
         if (dp[i][i] && result.size() < 1)
         {
            result = s[i];
         }
      }
      for (int i = n - 3; i >= 0; --i)
      {
         for (int j = i + 2; j < n; ++j)
         {
            dp[i][j] = dp[i + 1][j - 1] & (s[i] == s[j]);
            if (dp[i][j] && (j - i + 1) > result.size())
            {
               result = s.substr(i, j - i + 1);
            }
         }
      }
      return result;
   }
};