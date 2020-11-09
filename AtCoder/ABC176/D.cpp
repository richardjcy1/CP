#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

struct State
{
    int x, y, cnt;
};

int n, m;
int sx, sy;
int ex, ey;
char g[2000][2000];
bool st[2000][2000];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
int ans = INF;

void bfs()
{
    deque<State> q;
    q.push_back({sx, sy, 0});
    
    while (!q.empty())
    {
        auto tmp = q.front(); q.pop_front();
        int x = tmp.x, y = tmp.y, cnt = tmp.cnt;
        if (x == ex && y == ey)
        {
            ans = cnt;
            return;
        }
        if (st[x][y]) continue;
        st[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || g[tx][ty] == '#') continue;
            q.push_front({tx, ty, cnt});
        }
        for (int i = x - 2; i <= x + 2; i++)
        {
            for (int j = y - 2; j <= y + 2; j++)
            {
                if (i < 1 || i > n || j < 1 || j > m || g[i][j] == '#') continue;
                q.push_back({i, j, cnt + 1});
            }
        }
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    // n = read();
    // m = read();
    // sx = read();
    // sy = read();
    // ex = read();
    // ey = read();
    cin >> n >> m >> sx >> sy >> ex >> ey;

    for (int i = 1; i <= n; i++)
    {
        scanf("%s", g[i] + 1);
    }
    bfs();
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}