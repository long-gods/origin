#include "Primality_testing.h"

int prime[11] = { 2,3,5,7,11,13,17,19,23,29,31 };

bool Primality_testing::Miller_Rabin(long long x)
{
    int i, j, k;
    int s = 0;
    long long t = x - 1;
    if (x == 2)  return true;   //2������ 
    if (x < 2 || !(x & 1))  return false;     //���x��ż��������0,1�������������� 
    while (!(t & 1))  //��x�ֽ��(2^s)*t������ 
    {
        s++;
        t >>= 1;
    }
    for (i = 0; i < 11 && prime[i] < x; ++i)      //���ѡһ���������в��� 
    {
        int a = prime[i];
        int b = test.Quick_Power(a, t, x);      //�����a^t
        for (j = 1; j <= s; ++j)    //Ȼ�����s��ƽ�� 
        {
            k = test.Quick_Multiply(b, b, x);   //��b��ƽ�� 
            if (k == 1 && b != 1 && b != x - 1)     //�ö���̽���ж� 
                return false;
            b = k;
        }
        if (b != 1)  return false;   //�÷���С�����ж� 
    }
    return true;   //������ж�β��Զ��ǶԵģ���ôx�ͺ��п��������� 
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
