#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = max({a * c, a * d, b * c, b * d});
    cout << ans << endl;

    return 0;
}