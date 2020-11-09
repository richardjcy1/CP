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
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        ans += (a + b) * (b - a + 1) / 2;
    }
    cout << ans << endl;

    return 0;
}