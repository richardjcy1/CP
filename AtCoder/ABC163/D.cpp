#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for (ll i = k; i <= n + 1; i++)
    {
        ll mi = i * (i - 1) / 2;
        ll ma = (n * 2 - i + 1) * i / 2;
        ans += (ma - mi + 1);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}