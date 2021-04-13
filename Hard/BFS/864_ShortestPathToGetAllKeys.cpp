// Use (row, col, state) to represent a state
// then do BFS
// Time complexity: O(m*n*64)
// Space complexity: O(m*n)
int dirx[] = {0,0,1,-1};
int diry[] = {1,-1,0,0};
const int INF = 0x3f3f3f3f;
int vis[35][35][70];

class Solution {
public:
    int shortestPathAllKeys(vector<string>& g) {
        int m = g.size(), n = g[0].size();
        int startx , starty;
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] == '@')
                {
                    startx = i;
                    starty = j;
                }
                else if (g[i][j] >= 'a' && g[i][j] <= 'f') ++cnt;
            }
        }
        int ans = INF, tot = (1 << cnt) - 1;
        queue<array<int, 4>> q;
        q.push({startx, starty, 0, 0});
        memset(vis, 0, sizeof vis);
        vis[startx][starty][0] = 1;
        while (!q.empty())
        {
            auto p = q.front(); q.pop();
            int x = p[0], y = p[1], state = p[2], d = p[3];
            if (state == tot)
            {
                ans = min(ans, d);
                continue;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] != '#')
                {
                    if (g[nx][ny] >= 'A' && g[nx][ny] <= 'F')
                    {
                        if ((state & (1 << (g[nx][ny] - 'A'))) == 0) continue;
                    }
                    int nstate = (g[nx][ny] >= 'a' && g[nx][ny] <= 'f') ? (state | (1 << (g[nx][ny] - 'a'))) : state;
                    if (!vis[nx][ny][nstate])
                    {
                        vis[nx][ny][nstate] = 1;
                        q.push({nx, ny, nstate, d + 1});
                    }
                }
            }
        }
        return ans == INF ? -1 : ans;
    }
};