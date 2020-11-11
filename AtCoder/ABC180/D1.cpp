#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll ans = 0;
    while ((double)x * a <= x + b && (double)x * a < y)
    {
        x *= a;
        ++ans;
    }
    if (x < y) ans += (y - x - 1) / b;
    cout << ans << endl;
    return 0;
}