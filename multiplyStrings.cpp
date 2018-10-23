/**
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2,
 * also represented as a string.
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 *
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())
        {
            return "";
        }
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        if (num1 == "1")
        {
            return num2;
        }
        if (num2 == "1")
        {
            return num1;
        }
        string a = num1.length() < num2.length() ? num2 : num1;
        string b = num1.length() < num2.length() ? num1 : num2;
        vector<string> tmpSums;
        for (int i = b.length() - 1; i >= 0; --i)
        {
            int carryout = 0;
            string tmpSum(b.length() - 1 - i, '0');
            for (int j = a.length() - 1; j >= 0; --j)
            {
                int mul = (a[j] - '0') * (b[i] - '0') + carryout;
                tmpSum = static_cast<char>(mul % 10 + '0') + tmpSum;
                carryout = mul / 10;
            }
            if (carryout)
            {
                tmpSum = static_cast<char>(carryout + '0') + tmpSum;
            }
            tmpSums.push_back(tmpSum);
        }
        while (tmpSums.size() > 1)
        {
            string sum1 = tmpSums.back();
            tmpSums.pop_back();
            string sum2 = tmpSums.back();
            tmpSums.pop_back();
            int i = sum1.length() - 1;
            int j = sum2.length() - 1;
            string newSum;
            int carryout = 0;
            while (j >= 0)
            {
                int sum = (sum1[i] - '0') + (sum2[j] - '0') + carryout;
                newSum = static_cast<char>(sum % 10 + '0') + newSum;
                carryout = sum / 10;
                --i;
                --j;
            }
            while (i >= 0)
            {
                int sum = (sum1[i] - '0') + carryout;
                newSum = static_cast<char>(sum % 10 + '0') + newSum;
                carryout = sum / 10;
                --i;
            }
            if (carryout)
            {
                newSum = static_cast<char>(carryout + '0') + newSum;
            }
            tmpSums.push_back(newSum);
       }
       return tmpSums[0];
    }
};

// The above solution is extremely slow (only beats 11% of the total submission).
// use location index to save string copy
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())
        {
            return "";
        }
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        if (num1 == "1")
        {
            return num2;
        }
        if (num2 == "1")
        {
            return num1;
        }
        vector<int> mult(num1.size() + num2.size(), 0);
        int i1 = 0, i2 = 0;
        for (int i = num1.length() - 1; i >= 0; --i)
        {
            int carryout = 0;
            i2 = 0;
            for (int j = num2.length() - 1; j >= 0; --j)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0') + mult[i1 + i2] + carryout;
                mult[i1 + i2] = mul % 10;
                carryout = mul / 10;
                ++i2;
            }
            if (carryout)
            {
                mult[i1 + i2] = carryout;
            }
            ++i1;
        }
        int index = mult.size() - 1;
        for (; index >= 0 && mult[index] == 0; --index);
        string result;
        for (; index >= 0; --index)
        {
            result += static_cast<char>(mult[index] + '0');
        }
        return result;
    }
};
