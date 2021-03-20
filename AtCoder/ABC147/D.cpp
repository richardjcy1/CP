#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> v(64);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            if (1 & (a[i] >> j)) v[j]++;
        }
    }
    ll ans = 0;
    vector<ll> b(64);
    b[0] = 1;
    for (int i = 1; i < 64; i++)
    {
        b[i] = 2 * b[i - 1];
        b[i] %= mod;
    }
    for (int i = 0; i < 64; i++)
    {
        ans = (ans + v[i] * (n - v[i]) % mod * b[i]) % mod;
    }
    cout << ans << endl;
    return 0;
}