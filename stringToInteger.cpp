class Solution {
public:
    int myAtoi(string str) {
        // trim white spaces
        int sign = 1;
        int result = 0;
        int i = 0;
        while (i < str.size() && str[i] == ' ')
        {
            ++i;
        }
        // sign info
        if (i < str.size() && str[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else if (i < str.size() && str[i] == '+')
        {
            ++i;
        }
        // calculate result
        while (i < str.size() && isdigit(str[i]))
        {
            int backup = result;
            result = result * 10 + (str[i] - '0');
            // overflow case
            if (result < 0 || backup != (result - (str[i] - '0')) / 10)
            {
                return sign == 1? INT_MAX : INT_MIN;
            }
            ++i;
        }
        return result * sign;
    }
};