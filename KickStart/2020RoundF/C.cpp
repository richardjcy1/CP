#include <bits/stdc++.h>
using namespace std;

const int maxn = 7;
const int INF = 0x3f3f3f3f;
int dirx[] = {0,0,-1,1};
int diry[] = {-1,1,-1,1};

int n, c;
int ra, pa, rb, pb;
int g[maxn][maxn][maxn][maxn];
int vis[maxn][maxn];

int dfs(int x, int y, int a, int b, bool flag)
{
    bool ok = false;
    int ans = -INF;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dirx[i], ny = y + diry[i];
        if (!vis[nx][ny] && nx >= 1 && nx <= n && ny >= 1 && ny <= 2 * nx - 1 && g[x][y][nx][ny])
        {
            ok = true;
            vis[nx][ny] = 1;
            ans = max(ans, 1 - dfs(a, b, nx, ny, flag));
            vis[nx][ny] = 0;
        }
    }
    if (!ok && !flag)
    {
        ans = -dfs(a, b, x, y, true);
    }
    else if (!ok && flag)
    {
        ans = 0;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int kase = 1;
    while (t--)
    {
        memset(g, 0, sizeof g);
        memset(vis, 0, sizeof vis);
        cin >> n >> ra >> pa >> rb >> pb >> c;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 2 * i - 1; j++)
            {
                if (j & 1)
                {
                    if (i + 1 <= n)
                    {
                        g[i][j][i + 1][j + 1] = 1;
                        
                    }
                    if (j - 1 >= 1) 
                    {
                        g[i][j][i][j - 1] = 1;
                        
                    }
                    if (j + 1 <= 2 * i - 1) 
                    {
                        g[i][j][i][j + 1] = 1;
                        
                    }
                }
                else
                {
                    if (i - 1 >= 1) g[i][j][i - 1][j - 1] = 1;
                    if (j - 1 >= 1) g[i][j][i][j - 1] = 1;
                    if (j + 1 <= 2 * i - 1) g[i][j][i][j + 1] = 1;
                }
            }
        }
        for (int i = 0; i < c; i++)
        {
            int x, y;
            cin >> x >> y;
            if (y & 1)
            {
                if (y + 1 <= n)
                {
                    g[x][y][x + 1][y + 1] = 0;
                    g[x + 1][y + 1][x][y] = 0;
                    
                }
                if (y - 1 >= 1) 
                {
                    g[x][y][x][y - 1] = 0;
                    g[x][y - 1][x][y] = 0;
                }
                if (y + 1 <= 2 * x - 1) 
                {
                    g[x][y][x][y + 1] = 0;
                    g[x][y + 1][x][y] = 0;
                }
            }
            else
            {
                if (x - 1 >= 1) 
                {
                    g[x][y][x - 1][y - 1] = 0;
                    g[x - 1][y - 1][x][y] = 0;
                }
                if (y - 1 >= 1) 
                {
                    g[x][y][x][y - 1] = 0;
                    g[x][y - 1][x][y] = 0;
                }
                if (y + 1 <= 2 * x - 1) 
                {
                    g[x][y][x][y + 1] = 0;
                    g[x][y + 1][x][y] = 0;
                }
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= 2 * i - 1; j++)
        //     {
        //         for (int u = 1; u <= 6; u++)
        //         {
        //             for (int v = 1; v <= 6; v++)
        //             {
        //                 cout << i << " " << j << " " << u << " " << v << " " << g[i][j][u][v] << endl;
        //             }
        //         }
        //     }
        // }
        vis[ra][pa] = 1;
        vis[rb][pb] = 1;
        int ans = dfs(ra, pa, rb, pb, false);
        cout << "Case #" << kase++ << ": " << ans << endl;
    }

    return 0;
}