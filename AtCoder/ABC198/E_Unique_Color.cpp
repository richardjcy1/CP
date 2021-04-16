#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int n;
vector<int> c;
vector<vector<int> > g;
vector<int> vis(n);
vector<int> color(maxn);
vector<int> ans;

void dfs(int node)
{
    if (g[node].size() == 1 && vis[g[node][0]])
    {
        if (!color[c[node]]) ans.push_back(node);
        return;
    }
    vis[node] = 1;
    bool ok = !color[c[node]];
    if (ok)
    {
        ans.push_back(node);
        color[c[node]] = 1;
    }
    for (int nei: g[node])
    {
        if (!vis[nei])
        {
            dfs(nei);
        }
    }
    if (ok) color[c[node]] = 0;
    vis[node] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    c = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    g = vector<vector<int> >(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis = vector<int>(n);
    dfs(0);
    sort(ans.begin(), ans.end());
    for (int i: ans)
    {
        cout << i + 1 << '\n';
    }
    return 0;
}