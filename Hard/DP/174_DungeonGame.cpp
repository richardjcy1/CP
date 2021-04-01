const int INF = 0x3f3f3f3f;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
        if (a.size() == 0 || a[0].size() == 0) return 0;
        int m = a.size(), n = a[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INF));
        dp[m - 1][n - 1] = a[m - 1][n - 1] < 0 ? -a[m - 1][n - 1] + 1 : 1;
        for (int i = m - 2; ~i; i--)
        {
            if (a[i][n - 1] > 0)
            {
                dp[i][n - 1] = max(1, dp[i + 1][n - 1] - a[i][n - 1]);
            }
            else
            {
                dp[i][n - 1] = -a[i][n - 1] + dp[i + 1][n - 1];
            }
        }
        for (int j = n - 2; ~j; j--)
        {
            if (a[m - 1][j] > 0)
            {
                dp[m - 1][j] = max(1, dp[m - 1][j + 1] - a[m - 1][j]);
            }
            else
            {
                dp[m - 1][j] = -a[m - 1][j] + dp[m - 1][j + 1];
            }
        }
        for (int i = m - 2; ~i; i--)
        {
            for (int j = n - 2; ~j; j--)
            {
                if (a[i][j] > 0)
                {
                    dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - a[i][j], 1);
                }
                else
                {
                    dp[i][j] = -a[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};