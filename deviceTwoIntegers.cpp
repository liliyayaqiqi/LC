/**
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 * Return the quotient after dividing dividend by divisor.
 * The integer division should truncate toward zero.
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        if (dividend == 0)
        {
            return 0;
        }
        if (divisor == 1)
        {
            return dividend;
        }
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        if (divisor == INT_MIN)
        {
            return dividend == INT_MIN;
        }
        int result = 0;
        if (dividend == INT_MIN)
        {
            ++result;
            dividend += abs(divisor);
        }
        int sign = 1;
        if ((dividend > 0 && divisor < 0)
            || (dividend < 0 && divisor > 0))
        {
            sign = -1;
        }
        int residue = abs(dividend);
        while (residue >= abs(divisor))
        {
            ++result;
            residue -= abs(divisor);
        }
        return sign * result;
    }
};

// use variant of binary search to accelerate the solution

class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        if (dividend == 0)
        {
            return 0;
        }
        if (divisor == 1)
        {
            return dividend;
        }
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        if (divisor == INT_MIN)
        {
            return dividend == INT_MIN;
        }
        int result = 0;
        if (dividend == INT_MIN)
        {
            ++result;
            dividend += abs(divisor);
        }
        int sign = (dividend < 0) ^ (divisor < 0)? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= divisor)
        {
            int m = 1;
            int a = divisor;
            while ((a << 1) > 0 && (a << 1 < dividend))
            {
                m <<= 1;
                a <<= 1;
            }
            result += m;
            dividend -= a;
        }
        return sign * result;
    }
};
