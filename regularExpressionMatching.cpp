/**
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 */

// Below is a wrong answer. DP is the right way to solve the problem.
class Solution {
public:
    bool isMatch(string s, string p) {
        int indexS = 0;
        int indexP = 0;
        while (indexS < s.size() && indexP < p.size())
        {
            if (s[indexS] == p[indexP]
                || p[indexP] == '.')
            {
                ++indexS;
                ++indexP;
            }
            else if (p[indexP] == '*')
            {
                if (indexP == 0)
                {
                    return false;
                }
                else if (p[indexP - 1] == '.')
                {
                    ++indexS;
                }
                else if (p[indexP - 1] == s[indexS])
                {
                    ++indexS;
                }
                else
                {
                    ++indexP;
                }
            }
            else if (indexP + 1 < p.size() && p[indexP + 1] == '*')
            {
                indexP += 2;
            }
            else
            {
                return false;
            }
        }
        if (indexS != s.size() || (p.size() > 0 && p[p.size() - 1] != '*' && indexP != p.size()))
        {
            return false;
        }
        return true;
    }
};

//DP solution
/**
 * Assume D[i][j] is the state indicatin if S[0, i) matches P[0, j), Then the state transfer function is
 * D[i][j] = D[i - 1][j - 1], if P[j - 1] == '.'
 * D[i][j] = D[i - 1][j - 1] && P[j - 1] == S[i - 1], if P[j - 1] is from a~z
 * if P[j - 1] == '*', then
 * D[i][j] = D[i][j - 2]   ->no matching pattern found
 *           || D[i - 1][j] && (P[j - 2] == S[i - 1] || P[j - 2] == '.') -> one or more matching pattern found
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> D(s.size() + 1, vector<bool>(p.size() + 1, false));
        D[0][0] = true;
        for (int i = 0; i <= s.size(); ++i)
        {
            for (int j = 1; j <= p.size(); ++j)
            {
                if (p[j - 1] == '*')
                {
                    D[i][j] = (j > 1 && D[i][j - 2]) || (i > 0 && D[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
                }
                else
                {
                    D[i][j] = i > 0 && D[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
                }
            }
        }
        return D[s.size()][p.size()];
    }
};
