#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    double sum = 0.0;
    int i;
    for (i = 0; i < n; i++)
    {
        sum += v[i].first * (v[i].second / 100.0);
        if (sum > x && abs(sum - x) > 1e-5) break;
    }
    if (i == n) cout << -1 << endl;
    else cout << i + 1 << endl;
    return 0;
}