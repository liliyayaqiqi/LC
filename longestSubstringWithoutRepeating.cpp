class Solution {
public:
   int lengthOfLongestSubstring(string s) {
      if (s.empty())
      {
         return 0;
      }
      std::vector<int> hash(256, -1);
      int result = 0;
      int start = 0;
      int end = 0;
      for (int i = 0; i < s.size(); ++i)
      {
         int index = hash[s[i]];
         //no duplicate found
         if (index < start)
         {
            end = i;
         }
         else
         {
            result = result < end - start + 1? end - start + 1: result;
            start = index + 1;
         }
         hash[s[i]] = i;
      }
      result = result < end - start + 1? end - start + 1: result;
      return result;
   }
};