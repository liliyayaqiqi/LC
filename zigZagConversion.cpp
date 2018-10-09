class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0)
        {
            return "";
        }
        if (numRows == 1)
        {
            return s;
        }
        string result;
        for (int i = 0; i < numRows; ++i)
        {
            int gapOdd = 2 * (numRows - 1 - i);
            int gapEven = 2 * i;
            if (gapOdd == 0)
            {
                gapOdd = gapEven;
            }
            if (gapEven == 0)
            {
                gapEven = gapOdd;
            }
            int j = 0;
            int index = i;
            while (index < s.size())
            {
                result += s[index];
                ++j;
                if (j % 2 == 1)
                {
                    index += gapOdd;
                }
                else
                {
                    index += gapEven;
                }
            }
        }
        return result;
    }
};

// another faster solution

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows >= s.size() || numRows == 1) return s;
        string rets;
        vector<string> v(numRows);
        int iter = 0;
        bool down = true;
        for (int i = 0;i<s.size();i++) {
            v[iter] += s[i];
            if (iter == 0) down = true;
            if (iter == numRows - 1) down = false;
            if (down) iter++;
            if (!down) iter--;
        }
        for (int i = 0;i<numRows;i++)
            rets += v[i];
        return rets;
    }
};
