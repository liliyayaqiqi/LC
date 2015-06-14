double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    int n_abs = abs(n);
    double result = 0;
    if (n_abs == 1)
        result = x;
    else if (n_abs % 2 == 0)
    {
        double half = myPow(x, n_abs/2);
        result = half * half;
    }
    else
    {
        double half = myPow(x, n_abs/2);
        result = x * half * half;
    }
    if (n > 0)
        return result;
    return 1/result;
}
