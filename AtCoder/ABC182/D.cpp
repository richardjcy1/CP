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
    vector<ll> sum(n + 1);
    vector<ll> ma(n + 1);
    ma[0] = -INF;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i - 1];
        ma[i] = max(ma[i - 1], sum[i]);
    }
    ll ans = 0;
    ll tot = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, tot + ma[i]);
        tot += sum[i];
    }
    cout << ans << endl;
    return 0;
}