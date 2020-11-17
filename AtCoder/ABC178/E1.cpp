#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x1 = 0, y1 = 0, x2 = 0, y2 = 1e9 + 5;
    vector<pair<ll, ll>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b)
    {
        return a.first + a.second < b.first + b.second;
    });
    ll ans = abs(v[n - 1].first - v[0].first) + abs(v[n - 1].second - v[0].second);
    sort(v.begin(), v.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b)
    {
        return a.first + y2 - a.second < b.first + y2 - b.second;
    });
    ans = max(ans, abs(v[n - 1].first - v[0].first) + abs(v[n - 1].second - v[0].second));
    cout << ans << endl;
    return 0;
}