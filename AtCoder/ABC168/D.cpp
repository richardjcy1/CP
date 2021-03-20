#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> vis(n + 1);
    vector<int> p(n + 1);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int tmp = q.front(); q.pop();
        for (int nei: g[tmp])
        {
            if (!vis[nei])
            {
                p[nei] = tmp;
                q.push(nei);
                vis[nei] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += vis[i];
    if (cnt != n)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        for (int i = 2; i <= n; i++) cout << p[i] << endl;
    }
    return 0;
}