#include "bigmoden.h"

long long bigmoden::Quick_Multiply(long long a, long long b, long long c)
{
    long long ans = 0, res = a;
    while (b)
    {
        if (b & 1)
            ans = (ans + res) % c;
        res = (res + res) % c;
        b >>= 1;
    }
    return (long long)ans;
}

long long bigmoden::Quick_Power(long long a, long long b, long long c)
{
    long long ans = 1, res = a;
    while (b)
    {
        if (b & 1)
            ans = Quick_Multiply(ans, res, c);
        res = Quick_Multiply(res, res, c);
        b >>= 1;
    }
    return ans;
}
