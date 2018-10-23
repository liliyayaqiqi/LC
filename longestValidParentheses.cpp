/**
 * Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses substring
 *
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() < 2)
       {
          return 0;
       }
       int maxLen = 0;
       stack<int> tmp;
       tmp.push(-1);
       for (int i = 0; i < s.length(); ++i)
       {
          if (s[i] == '(')
          {
             tmp.push(i);
          }
          else
          {
             tmp.pop();
             if (tmp.empty())
             {
                tmp.push(i);
             }
             else
             {
                maxLen = max(maxLen, i - tmp.top());
             }
          }
       }
       return maxLen;
    }
};
