const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = s[i] == s[i + 1] ? 0 : 1;
        for (int l = 3; l <= n; l++)
        {
            for (int i = 0; i + l <= n; i++)
            {
                int j = i + l - 1;
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};