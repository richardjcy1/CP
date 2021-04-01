const int INF = 0x3f3f3f3f;

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) cost[i][i] = 0;
        for (int i = 0; i < n - 1; i++) cost[i][i + 1] = s[i] == s[i + 1] ? 0 : 1;
        for (int l = 3; l <= n; l++)
        {
            for (int i = 0; i + l <= n; i++)
            {
                int j = i + l - 1;
                if (s[i] == s[j]) cost[i][j] = cost[i + 1][j - 1];
                else cost[i][j] = 1 + cost[i + 1][j - 1];
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (j == i)
                {
                    dp[i][j] = 0;
                    continue;
                }
                else if (j > i) continue;
                for (int u = 1; u <= i; u++)
                {
                    dp[i][j] = min(dp[i][j], dp[u - 1][j - 1] + cost[u - 1][i - 1]);
                }
            }
        }
        return dp[n][k];
    }
};