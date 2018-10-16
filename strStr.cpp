/**
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * Example 1
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
        {
            return 0;
        }
        if (haystack.empty())
        {
            return -1;
        }
        for (int i = 0; i < haystack.size(); ++i)
        {
            int lastStart = i;
            int j = 0;
            int matches = 0;
            int k = i;
            while (k < haystack.size() && j < needle.size() && haystack[k] == needle[j])
            {
                ++k;
                ++j;
                ++matches;
            }
            if (matches == needle.size())
            {
                return lastStart;
            }
        }
        return -1;
    }
};

// The above solution is relatively slower. Use early stop to make it faster
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
        {
            return 0;
        }
        // needle cannot be in the haystack if haystack is empty
        if (haystack.empty())
        {
            return -1;
        }
        if (needle.length() > haystack.length())
        {
            return -1;
        }
        if (haystack.length() == needle.length())
        {
            return (haystack == needle) - 1;
        }
        for (int i = 0; i < haystack.length(); ++i)
        {
            if (haystack[i] == needle.front()
                && i + needle.length() - 1 < haystack.length()
                && haystack[i + needle.length() - 1] == needle.back())
            {
                int j = 0;
                while (j < needle.length() && haystack[i + j] == needle[j])
                {
                    ++j;
                }
                if (j == needle.length())
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
