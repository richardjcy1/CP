#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll h, w, m;
    cin >> h >> w >> m;
    vector<vector<ll>> v(h, vector<ll>());
    vector<vector<ll>> u(w, vector<ll>());
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        --x; --y;
        v[x].push_back(y);
        u[y].push_back(x);
    }
    for (int i = 0; i < h; i++)
    {
        if (!v[i].empty())
        {
            v[i].push_back(w);
            sort(v[i].begin(), v[i].end());
        }
    }
    for (int i = 0; i < w; i++)
    {
        if (!u[i].empty())
        {
            u[i].push_back(h);
            sort(u[i].begin(), u[i].end());
        }
    }
    ll tot = 0;
    for (ll i = 0; i < h, i++)
    {
        if (!v[i].empty())
        {
            for (ll j = 0; j < v[i].size() - 1; j++)
            {
                tot += v[i][j + 1] - v[i][j] - 1;
            }
        }
    }
    for (ll i = 0; i < w; i++)
    {
        if (!u[i].empty())
        {
            for (ll j = 0; j < u[i].size() - 1; j++)
            {
                tot += u[i][j + 1] - u[i][j] - 1;
            }
        }
    }
    ll ans = h * w - tot - m;
    cout << ans << endl;
    return 0;
}