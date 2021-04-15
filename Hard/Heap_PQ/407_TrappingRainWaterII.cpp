int dirx[] = {0,0,1,-1};
int diry[] = {1,-1,0,0};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        const auto cmp = [&](const array<int, 3>& x, const array<int, 3>& y)
        {
            return x[2] > y[2];
        };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> pq(cmp);
        vector<vector<int>> vis(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    pq.push(array<int, 3>{i, j, h[i][j]});
                    vis[i][j] = 1;
                }
            }
        }
        int ans = 0;
        while (!pq.empty())
        {
            auto tmp = pq.top(); pq.pop();
            int x = tmp[0], y = tmp[1], z = tmp[2];
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny])
                {
                    if (z > h[nx][ny])
                    {
                        ans += (z - h[nx][ny]);
                    }
                    pq.push(array<int, 3>{nx, ny, max(z, h[nx][ny])});
                    vis[nx][ny] = 1;
                }
            }
        }
        return ans;
    }
};