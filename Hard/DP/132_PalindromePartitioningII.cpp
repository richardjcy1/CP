const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, INF);
        dp[0] = 0; dp[1] = 1;
        vector<vector<int>> ok(n, vector<int>(n));
        for (int i = 0; i < n; i++) ok[i][i] = 1;
        for (int i = 0; i < n - 1; i++) ok[i][i + 1] = (s[i] == s[i + 1]);
        for (int l = 3; l <= n; l++)
        {
            for (int i = 0; i + l <= n; i++)
            {
                int j = i + l - 1;
                if (s[i] == s[j]) ok[i][j] = ok[i][j] || ok[i + 1][j - 1];
            }
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (ok[j][i - 1]) dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
        return dp[n] - 1;
    }
};