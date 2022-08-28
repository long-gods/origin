#include "bigmoden.h"

int bigmoden::Quick_Multiply(int a, int b, int c)
{
    long long ans = 0, res = a;
    while (b)
    {
        if (b & 1)
            ans = (ans + res) % c;
        res = (res + res) % c;
        b >>= 1;
    }
    return (int)ans;
}

int bigmoden::Quick_Power(int a, int b, int c)
{
    int ans = 1, res = a;
    while (b)
    {
        if (b & 1)
            ans = Quick_Multiply(ans, res, c);
        res = Quick_Multiply(res, res, c);
        b >>= 1;
    }
    return ans;
}
