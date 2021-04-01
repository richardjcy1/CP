const int maxn = 75;
int dp[maxn][maxn][maxn];

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dp, 0, sizeof dp);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                dp[m - 1][j][k] = j == k ? grid[m - 1][j] : grid[m - 1][j] + grid[m - 1][k];
            }
        }
        for (int i = m - 2; ~i; i--)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (j == k)
                    {
                        for (int u = -1; u <= 1; u++)
                        {
                            for (int v = -1; v <= 1; v++)
                            {
                                int new_j = j + u, new_k = k + v;
                                if (new_j >= 0 && new_j < n && new_k >= 0 && new_k < n)
                                {
                                    dp[i][j][k] = max(dp[i][j][k], grid[i][j] + dp[i + 1][new_j][new_k]);
                                }
                            }
                        }
                    }
                    else
                    {
                        for (int u = -1; u <= 1; u++)
                        {
                            for (int v = -1; v <= 1; v++)
                            {
                                int new_j = j + u, new_k = k + v;
                                if (new_j >= 0 && new_j < n && new_k >= 0 && new_k < n)
                                {
                                    dp[i][j][k] = max(dp[i][j][k], grid[i][j] + grid[i][k] + dp[i + 1][new_j][new_k]);
                                }
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][n - 1];
    }
};