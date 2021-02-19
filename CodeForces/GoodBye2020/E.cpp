#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll power(ll a, ll n, ll p)
{
    ll res = 1;
    a %= p;
    
    while (n)
    {
        if (n & 1) res = (res * a ) % p;
        n >>= 1;
        a = (a * a) % p;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<ll> cnt(64);
        for (int i = 0; i < n; i++)
        {
            ll x = a[i];
            int j = 0;
            while (x)
            {
                if (x & 1) cnt[j]++;
                x >>= 1;
                j++;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll x = 0, y = 0;
            for (int j = 0; j < 64; j++)
            {
                if (a[i] & ((ll)1 << j))
                {
                    x = (x + cnt[j] * power(2, j, mod) % mod) % mod;
                    y = (y + n * power(2, j, mod) % mod) % mod;
                }
                else
                {
                    y = (y + cnt[j] * power(2, j, mod) % mod) % mod;
                }
            }
            ans = (ans + x * y % mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}