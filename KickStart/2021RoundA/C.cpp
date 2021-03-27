#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int kase = 0;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> a(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                 cin >> a[i][j];
            }
        }
        vector<vector<int>> vis(m, vector<int>(n));
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                q.push({a[i][j], i * n + j});
            }
        }
        int dirx[] = {0,0,1,-1};
        int diry[] = {1,-1,0,0};
        ll ans = 0;
        while (!q.empty())
        {
            auto v = q.top(); q.pop();
            int x = v.second / n, y = v.second % n;
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny])
                {
                    if (a[nx][ny] < a[x][y] - 1)
                    {
                        ans += (a[x][y] - 1 - a[nx][ny]);
                        a[nx][ny] = a[x][y] - 1;
                    }
                    vis[nx][ny] = 1;
                    q.push({a[nx][ny], nx * n + ny});
                }
            }
        }
        cout << "Case #" << ++kase << ": " << ans << '\n';
    }
    return 0;
}