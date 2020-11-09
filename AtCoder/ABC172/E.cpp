#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int gcdExtended(int a, int b, int* x, int* y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

ll modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    ll res = (x % m + m) % m;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ll fac[m + 1];
    fac[0] = 1;
    for (int i = 1; i <= m; i++) 
    {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }
    ll ans = fac[m] * modInverse(fac[m - n], mod);
    ans = (ans + mod) % mod;
    ll tmp = 0, sign = 1;
    for (int i = 0; i <= n; i++)
    {
        ll x = fac[m - i] * fac[n] % mod;
        x = x * modInverse(fac[i], mod) % mod * modInverse(fac[n - i], mod) % mod * modInverse(fac[m - n], mod) % mod;
        x *= sign;
        x = (x % mod) + mod;
        tmp += x;
        tmp = (tmp + mod) % mod;
        sign *= -1;
    }
    ans *= tmp;
    ans = (ans + mod) % mod;
    cout << ans << endl;
    return 0;
}