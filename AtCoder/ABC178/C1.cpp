#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


ll power(ll a, ll n, ll p)
{
    a %= p;
    ll res = 1;
    while (n)
    {
        if (n & 1)
        {
            res *= a;
            res %= p;
        }
        a = (a * a) % p;
        n >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll ans = power(10, n, mod) - 2 * power(9, n, mod) % mod;
    ans = (ans + mod) % mod;
    ans += power(8, n, mod);
    ans %= mod;
    cout << ans << endl;
    return 0;
}