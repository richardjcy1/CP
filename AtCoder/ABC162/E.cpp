#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll pw(ll a, ll n, ll p)
{
    ll res = 1;
    a %= p;
    while (n)
    {
        if (n & 1) res = (res * a) % p;
        n >>= 1;
        a = (a * a) % p;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    ll ans = 0;
    vector<ll> dp(k + 1);
    for (int i = k; i >= 1; i--)
    {
        ll tmp = pw(k / i, n, mod);
        for (int j = 2; j * i <= k; j++)
        {
            tmp -= dp[j * i];
            tmp = (tmp + mod) % mod;
        }
        dp[i] = tmp % mod;
    }
    for (int i = 1; i <= k; i++)
    {
        ans = (ans + i * dp[i] % mod);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}