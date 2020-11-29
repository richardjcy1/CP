#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int dirx[] = {1,-1,0,0};
int diry[] = {0,0,1,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    for (int i = 0; i < h; i++)
    {
        string s;
        cin >> s;
        v[i] = s;
    }
    int startx, starty, endx, endy;
    unordered_map<char, vector<pair<int, int>>> mp;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (v[i][j] >= 'a' && v[i][j] <= 'z')
            {
                mp[v[i][j]].push_back(make_pair(i, j));
            }
            else if (v[i][j] == 'S')
            {
                startx = i;
                starty = j;
            }
            else if (v[i][j] == 'G')
            {
                endx = i;
                endy = j;
            }
        }
    }
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(startx, starty, 0));
    int ans = INF;
    vector<vector<bool>> vis(h, vector<bool>(w));
    vis[startx][starty] = true;
    while (!q.empty())
    {
        auto tmp = q.front(); q.pop();
        int x = get<0>(tmp), y = get<1>(tmp);
        if (x == endx && y == endy)
        {
            ans = min(ans, get<2>(tmp));
            continue;
        } 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && v[nx][ny] != '#')
            {
                vis[nx][ny] = true;
                q.push(make_tuple(nx, ny, get<2>(tmp) + 1));
            }
        }
        if (v[x][y] >= 'a' && v[x][y] <= 'z')
        {
            for (auto p: mp[v[x][y]])
            {
                if (!(p.first == x && p.second == y) && !vis[p.first][p.second])
                {
                    vis[p.first][p.second] = true;
                    q.push(make_tuple(p.first, p.second, get<2>(tmp) + 1));
                }
            }
            mp.erase(v[x][y]);
        }
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}