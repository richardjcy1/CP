#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m, t;
    cin >> n >> m >> t;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    ll ans = n - v[0].first;
    if (ans <= 0)
    {
        cout << "No" << endl;
        return 0;
    }
    bool ok = true;
    for (int i = 0; i < m; i++)
    {
        if (i) ans -= (v[i].first - v[i - 1].second);
        if (ans <= 0)
        {
            ok = false;
            break;
        }
        ans += v[i].second - v[i].first;
        if (ans > n) ans = n;
    }
    if (!ok)
    {
        cout << "No" << endl;
        return 0;
    }
    ans -= (t - v.back().second);
    if (ans <= 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}