/*
*	author:		richardjcy
*	created:	2020/09/26/08:26.04
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<int, ll>>> adj;
vector<int> color;
vector<bool> vis;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    adj = vector<vector<pair<int, ll>>>(n, vector<pair<int, ll>>());
    color = vector<int>(n);
    vis = vector<bool>(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        --x; --y;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    color[0] = 0;
    vis[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto p: adj[u])
        {
            int node = p.first;
            ll w = p.second;
            if (!vis[node])
            {
                vis[node] = true;
                if (w & 1)
                {
                    color[node] = 1 - color[u];
                    q.push(node);
                }
                else
                {
                    color[node] = color[u];
                    q.push(node);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << color[i] << endl;
    }
    return 0;
}