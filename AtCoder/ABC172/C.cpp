#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    a.insert(a.begin(), 0);
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<ll> sum(m + 1);
    for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + b[i - 1];
    ll ans = 0;
    ll tot = 0;
    for (int i = 0; i <= n; i++)
    {
        tot += a[i];
        if (tot > k) break;
        auto it = lower_bound(sum.begin(), sum.end(), k - tot);
        //cout << i << " " << distance(sum.begin(), it) << endl;
        if (it == sum.end()) 
        {
            ans = max(ans, (ll)i);
        }
        else if (*it == k - tot)
        {
            ans = max(ans, (ll)i + distance(sum.begin(), it));
        }
        else
        {
            ans = max(ans, (ll)i + distance(sum.begin(), it) - 1);
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}