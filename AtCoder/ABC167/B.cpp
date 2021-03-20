#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll ans = 0;
    if (k <= a) ans = k;
    else if (k <= a + b) ans = a;
    else ans = a - (k - a - b);
    cout << ans << endl;
    return 0;
}