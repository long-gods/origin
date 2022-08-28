// rsa.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include "bigmoden.h"
#include<vector>
using namespace std;

int main()
{
    vector<long long> miwen;
    string str;
    cin >> str;
    bigmoden b;
    long long p = 48539, q = 48079;
    long long N = p * q;
    long long Nn = (p - 1) * (q - 1);
    long long e= 65537;
    long long d;
    for (int i = 2; i < Nn; i++)
        if (b.Quick_Multiply(i, e, Nn) == 1) {
            d = i;
            break;
        }
    unsigned char c;
    for (auto s : str)
    {
        c = (unsigned char)s;
        miwen.push_back(b.Quick_Power(c, e, N));
    }
    for (auto m : miwen)
        cout << m;
    cout << endl;
    for (auto m : miwen)
    {
        cout << (signed char)b.Quick_Power(m, d, N);
    }
    cout << endl;
}
