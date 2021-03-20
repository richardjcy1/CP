#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
// int s[maxn], e[maxn];
ll n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int kase = 1;
    while (t--)
    {
        cin >> n >> k;
        vector<pair<ll, ll>> v;
        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        sort(v.begin(), v.end());
        ll ans = ceil((v[0].second - v[0].first) / (k + 0.0));
        ll last = v[0].first + ans * k;
        for (int i = 1; i < n; i++)
        {
            if (v[i].first >= last)
            {
                ll tmp = ceil((v[i].second - v[i].first) / (k + 0.0));
                ans += tmp;
                last = v[i].first + tmp * k;
            }
            else
            {
                ll tmp = ceil((v[i].second - last) / (k + 0.0));
                ans += tmp;
                last = last + tmp * k;
            }
            // cout << ans << " " << last << endl;
        }
        cout << "Case #" << kase++ << ": " << ans << endl;
    }
    return 0;
}