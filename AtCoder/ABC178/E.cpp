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
    vector<pair<ll, ll>> v;
    vector<pair<ll, ll>> v2;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
        v2.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b)
    {
        return a.first + a.second < b.first + b.second;
    });
    sort(v2.begin(), v2.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b)
    {
        return a.first + (1e9 + 5 - a.second) < b.first + (1e9 + 5 - b.second);
    });
    ll ans1 = abs(v[n - 1].first - v[0].first) + abs(v[n - 1].second - v[0].second);
    ll ans2 = abs(v2[0].first - v2[n - 1].first) + abs(v2[0].second - v2[n - 1].second);
    cout << max(ans1, ans2) << endl;
    return 0;
}