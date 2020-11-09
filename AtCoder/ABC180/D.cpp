#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll power(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1) res = (res * a );
        n >>= 1;
        a = (a * a);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll ans = 0;
    while ((double)a * x <= 2e18 && a * x <= x + b && a * x < y)
    {
        ++ans;
        x *= a;
    }
    ans += (y - x - 1) / b;
    cout << ans << endl;

    return 0;
}