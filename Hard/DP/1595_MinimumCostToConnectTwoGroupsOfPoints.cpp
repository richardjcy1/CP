const int INF = 0x3f3f3f3f;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m = cost.size(), n = cost[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int mask = 0; mask < 1 << n; mask++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (mask & (1 << j))
                    {
                        dp[i][mask] = min(dp[i][mask], dp[i][mask - (1 << j)] + cost[i - 1][j]);
                        dp[i][mask] = min(dp[i][mask], dp[i - 1][mask] + cost[i - 1][j]);
                        dp[i][mask] = min(dp[i][mask], dp[i - 1][mask - (1 << j)] + cost[i - 1][j]);
                    }
                }
            }
        }
        return dp[m][(1 << n) - 1];
    }
};