const int INF = 0x3f3f3f3f;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i + l <= n; i++)
            {
                int j = i + l - 1;
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i][j - 1];
                    continue;
                }
                dp[i][j] = dp[i][j - 1] + 1;
                for (int k = i; k < j; k++)
                {
                    if (s[k] == s[j])
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j - 1]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};