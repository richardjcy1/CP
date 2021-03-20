/*
*	author:		richardjcy
*	created:	2020/09/25/21:07.58
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
vector<vector<int>> adj;
vector<bool> vis;
int dp[maxn];

int dfs(int node)
{
    if (adj[node].size() == 1 && vis[adj[node][0]])
    {
        dp[node] = n - 1;
        return 1;
    }
    vis[node] = true;
    int ans = 0, tot = 0;
    for (int i: adj[node])
    {
        if (!vis[i])
        {
            int l = dfs(i);
            tot += l;
            ans = max(ans, l);
        }
    }
    dp[node] = max(ans, n - 1 - tot);
    return tot + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof dp);
        cin >> n;
        adj = vector<vector<int>>(n, vector<int>());
        vis = vector<bool>(n);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            --x; --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(0);
        int idx1 = -1, idx2 = -1;
        int ma = INF;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] < ma)
            {
                idx1 = i;
                ma = dp[i];
                idx2 = -1;
            }
            else if (dp[i] == ma)
            {
                idx2 = i;
            }
        }
        if (idx2 == -1)
        {
            cout << 1 << " " << adj[0][0] + 1 << endl;
            cout << 1 << " " << adj[0][0] + 1 << endl;
        }
        else
        {
            int j = -1, mi = INF;
            for (int i: adj[idx2])
            {
                if (i != idx1)
                {
                    if (dp[i] < mi)
                    {
                        mi = dp[i];
                        j = i;
                    }
                }
            }
            cout << idx2 + 1 << " " << j + 1 << endl;
            cout << idx1 + 1 << " " << j + 1 << endl;
        }
    }
    return 0;
}