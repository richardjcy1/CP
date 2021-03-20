#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll left = 0, right = 2e5 + 5;
    auto check = [&](ll mid)
    {
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            // auto it = lower_bound(a.begin(), a.end(), mid - a[i]);
            // if (it != a.end())
            // {
            //     int d = distance(a.begin(), it);
            //     cnt += (n - d);
            // }
            cnt += (a.end() - lower_bound(a.begin(), a.end(), mid - a[i]));
        }
        // cout << "mid: " << mid << " " << cnt << endl;
        return cnt > m;
    };
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (check(mid))
        {
            left = mid + 1;
        }
        else right = mid - 1;
    }
    --left;
    // cout << "left: " << left << endl;
    ll ans = 0;
    vector<ll> sum(n + 1);
    ll rest = m;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(a.begin(), a.end(), left - a[i]) - a.begin();
        ans += (sum[n] - sum[it] + (n - it) * a[i]);
        rest -= n - it;
    }
    ans += rest * left;
    cout << ans << endl;
    return 0;
}