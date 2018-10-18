/**
 * You are given a string, s, and a list of words, words, that are all of the same length.
 * Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and
 * without any intervening characters.
 *
 * Input:
 * s = "barfoothefoobarman",
 * words = ["foo","bar"]
 * Output: [0,9]
 */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty())
        {
            return result;
        }
        int wordLen = words[0].length();
        int wordSize = words.size();
        if (s.length() < wordLen * wordSize)
        {
            return result;
        }
        unordered_map<string, int> wordMap;
        for (const auto & word: words)
        {
            ++wordMap[word];
        }
        unordered_map<string, int> wordCounter;
        for (int i = 0; i < s.length() - wordLen * wordSize + 1; ++i)
        {
            wordCounter = wordMap;
            int j = i;
            while (j - i < wordLen * wordSize)
            {
                string curString = s.substr(j, wordLen);
                if (wordCounter.find(curString) == wordCounter.end())
                {
                    break;
                }
                if (wordCounter[curString] == 0)
                {
                    break;
                }
                --wordCounter[curString];
                j += wordLen;
            }
            if (j == i + wordLen * wordSize)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};