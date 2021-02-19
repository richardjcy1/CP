#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i <= 2 * n; i++)
    {
        if (n % i == 0 && i & 1) ++ans;
        ll x = 2 * n / i;
        if (x != i && n % x == 0 && x & 1) ++ans;
        if (i % 2 == 0 && n % i != 0 && (2 * n) % i == 0) ++ans;
        if (x != i && x % 2 == 0 && n % x != 0 && (2 * n) % x == 0) ++ans;
    }
    cout << ans << endl;
    return 0;
}