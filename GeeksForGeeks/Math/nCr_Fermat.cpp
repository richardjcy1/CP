#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef unsigned long long ull;

ull power(ull x, int y, int p)
{
    ull res = 1;
    x %= p;
    while (y > 0)
    {
        if (y & 1) res = (res * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}

ull modInverse(ull n, int p)
{
    return power(n, p - 2, p);
}

ull nCrModPFermat(ull n, int r, int p)
{
    if (r == 0) return 1;
    ull fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int main() 
{ 
    // p must be a prime greater than n. 
    int n = 10, r = 2, p = 13; 
    cout << "Value of nCr % p is "
         << nCrModPFermat(n, r, p); 
    return 0; 
} 