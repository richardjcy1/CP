#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int maxn = 2e5 + 5;
vector<vector<int>> g;
int tot[maxn];
int dis[maxn];
vector<bool> vis;

int dfs(int node, int d)
{
    vis[node] = true;
    dis[node] = d;
    int ans = 1;
    for (int nei: g[node])
    {
        if (!vis[nei])
        {
            ans += dfs(nei, d + 1);
        }
    }
    tot[node] = ans;
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    g = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dis, 0, sizeof dis);
    memset(tot, 0, sizeof tot);
    vis = vector<bool>(n);
    dfs(0, 0);
    vector<tuple<int, int, int>> v;
    for (int i = 1; i < n; i++)
    {
        v.push_back(make_tuple(dis[i], tot[i], i));
        //cout << dis[i] << " " << tot[i] << " " << i << endl;
    }
    sort(v.begin(), v.end(), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b)
    {
        return get<0>(a) - get<1>(a) > get<0>(b) - get<1>(b); 
    });
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        //cout << get<2>(v[i]) << " " << get<0>(v[i]) << " " << get<1>(v[i]) << endl;
        ans += get<0>(v[i]);
        ans -= (get<1>(v[i]) - 1);
    }
    cout << ans << endl;

    return 0;
}