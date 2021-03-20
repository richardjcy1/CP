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
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    vector<int> degree(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(make_pair(y, i));
        g[y].push_back(make_pair(x, i));
        degree[x]++;
        degree[y]++;
    }
    int ma = 0, idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] > ma)
        {
            ma = degree[i];
            idx = i;
        }
    }
    int k = ma;
    vector<unordered_set<int>> color(n, unordered_set<int>());
    vector<int> vis(n);
    queue<int> q;
    q.push(idx);
    vis[idx] = 1;
    vector<int> edge(n - 1);
    while (!q.empty())
    {
        auto tmp = q.front(); q.pop();
        int i = 1;
        for (auto p: g[tmp])
        {
            int nei = p.first;
            int idx = p.second;
            if (vis[nei]) continue;
            while (color[tmp].find(i) != color[tmp].end() || color[nei].find(i) != color[nei].end()) i++;
            edge[idx] = i;
            // color[tmp][i] = color[nei][i] = 1;
            color[tmp].insert(i);
            color[nei].insert(i);
            i++;
            degree[nei]--;
            if (degree[nei]) 
            {
                vis[nei] = 1;
                q.push(nei);
            }
        }
    }
    cout << k << endl;
    for (int i = 0; i < edge.size(); i++) cout << edge[i] << endl;
    return 0;
}