#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

ll p[maxn];
ll vis[maxn];
vector<vector<ll>> g;
vector<ll> cost;
vector<ll> ans;

void dfs(ll x)
{
    for (ll nei: g[x])
    {
        if (!vis[nei])
        {
            p[nei] = x;
            vis[nei] = 1;
            dfs(nei);
        }
    }
}

void solve(ll node, ll v)
{
    ans[node] = v + cost[node];
    vis[node] = 1;
    for (ll nei: g[node])
    {
        if (!vis[nei])
        {
            solve(nei, ans[node]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    cost = vector<ll>(n);
    ans = vector<ll>(n);
    g = vector<vector<ll>>(n, vector<ll>());
    vector<pair<ll, ll>> edges;
    memset(p, -1, sizeof p);
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        edges.push_back(make_pair(a, b));
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis[0] = 1;
    dfs(0);
    int m;
    cin >> m;
    vector<vector<ll>> q;
    ll delta = 0;
    for (int i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        --y;
        ll u = edges[y].first, v = edges[y].second;
        if (x == 1)
        {
            if (p[u] == v)
            {
                cost[u] += z;
            }
            else
            {
                cost[v] -= z;
                delta += z;
            }
        }
        else
        {
            if (p[u] == v)
            {
                cost[u] -= z;
                delta += z;
            }
            else
            {
                cost[v] += z;
            }
        }
    }
    memset(vis, 0, sizeof vis);
    solve(0, delta);
    for (ll i = 0; i < n; i++) 
    {
        cout << ans[i] << endl;
    }
    return 0;
}