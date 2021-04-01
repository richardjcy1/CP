const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
        int n = costs.size(), m = costs[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INF));
        for (int j = 0; j < m; j++) dp[0][j] = costs[0][j];
        int mi1 = INF, mi2 = INF;
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < m; j++)
        {
            if (dp[0][j] < mi1)
            {
                mi2 = mi1;
                idx2 = idx1;
                mi1 = dp[0][j];
                idx1 = j;
            }
            else if (dp[0][j] < mi2)
            {
                mi2 = dp[0][j];
                idx2 = j;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == idx1)
                {
                    dp[i][j] = min(dp[i][j], costs[i][j] + mi2);
                }
                else
                {
                    dp[i][j] = min(dp[i][j], costs[i][j] + mi1);
                }
            }
            mi1 = mi2 = INF;
            idx1 = idx2 = -1;
            for (int j = 0; j < m; j++)
            {
                if (dp[i][j] < mi1)
                {
                    mi2 = mi1;
                    idx2 = idx1;
                    mi1 = dp[i][j];
                    idx1 = j;
                }
                else if (dp[i][j] < mi2)
                {
                    mi2 = dp[i][j];
                    idx2 = j;
                }
            }
        }
        int ans = INF;
        for (int j = 0; j < m; j++)
        {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};