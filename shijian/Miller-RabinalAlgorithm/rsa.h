#ifndef RSA_H
#define RSA_H
#include<string>
using namespace std;
#define LL long long


class rsa
{
public:

    rsa();
    LL E = 65537;

    LL P = 48539, Q = 48079;

    LL N = P * Q;

    LL Nn = (P - 1) * (Q - 1);

    LL SecretKey = 0;

    unsigned int gcd(unsigned int a, unsigned int b) {  //辗转相除
        if (a < b) {
            int temp = a;

            b = a;
            a = temp;
        }
        else if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    LL GetPulicKey() {  //默认公钥
        return E;
    }

    LL GetPulicKey(LL e) {  //用户设定公钥
        if (e <= 1)
            return -1;
        else if (gcd(e, Nn) == 1)
            return e;
        return -1;
    }

    bool Exgcd(LL a, LL b, LL& x, LL& y) {    //ax + by = gcd(a,b) = 1
        if (b == 0) {
            x = 1;
            y = 0;
            return (bool)a;
        }
        bool d = Exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }

    LL GetSecretKey() {
        LL x = 0, y = 0;
        bool isTry = Exgcd(E, (-1) * Nn, x, y);
        return x;
    }

    LL pow(LL a, LL p, LL mod) {    //快速幂
        LL r = 1, base = a;

        for (; p; p >>= 1) {
            if (p % 2)
                r = (r % mod) * (base % mod) % mod;
            base = (base % mod )* (base % mod) % mod;
        }
        return r;
    }

    LL* Encrypt(string M) {
        int l = M.length(), i = 0;
        unsigned char c;
        LL* C = new LL[l]{0};

        for (; l--; i++) {
            c = (unsigned char)M[i];
            C[i] = pow(c, E, N);
        }
        return C;
    }

    string Decrypt(LL* C, int l) {
        int i = 0;
        string M(l + 1, '\0');

        for (; l--; i++) {
            M[i] = (signed char)pow(C[i], GetSecretKey(), N);
        }
        return M;
    }
};

#endif // RSA_H
