#include "Primality_testing.h"

int prime[11] = { 2,3,5,7,11,13,17,19,23,29,31 };

bool Primality_testing::Miller_Rabin(long long x)
{
    int i, j, k;
    int s = 0;
    long long t = x - 1;
    if (x == 2)  return true;   //2是素数 
    if (x < 2 || !(x & 1))  return false;     //如果x是偶数或者是0,1，那它不是素数 
    while (!(t & 1))  //将x分解成(2^s)*t的样子 
    {
        s++;
        t >>= 1;
    }
    for (i = 0; i < 11 && prime[i] < x; ++i)      //随便选一个素数进行测试 
    {
        int a = prime[i];
        int b = test.Quick_Power(a, t, x);      //先算出a^t
        for (j = 1; j <= s; ++j)    //然后进行s次平方 
        {
            k = test.Quick_Multiply(b, b, x);   //求b的平方 
            if (k == 1 && b != 1 && b != x - 1)     //用二次探测判断 
                return false;
            b = k;
        }
        if (b != 1)  return false;   //用费马小定律判断 
    }
    return true;   //如果进行多次测试都是对的，那么x就很有可能是素数 
}

bool Primality_testing::commontest(int x)
{
    int s = sqrt(x);
    for (int i = 2; i <= s; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
