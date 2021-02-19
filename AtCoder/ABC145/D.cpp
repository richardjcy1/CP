#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef unsigned long long ull;

ull power(ull x, ull y, ull p)
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

ull modInverse(ull n, ull p)
{
    return power(n, p - 2, p);
}

ull nCrModPFermat(ull n, ull r, ull p)
{
    if (r == 0) return 1;
    ull fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll x, y;
    cin >> x >> y;
    if ((x + y) % 3) cout << 0 << endl;
    else
    {
        ll m = y - (x + y) / 3;
        ll n = x - (x + y) / 3;
        if (m < 0 || n < 0) cout << 0 << endl;
        else
        {
            ull ans = nCrModPFermat(m + n, m, mod);
            cout << ans << endl;
        }
    }
    return 0;
}