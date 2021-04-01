class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        string s = word1 + word2;
        vector<vector<int>> dp2(m + n, vector<int>(m + n));
        for (int i = 0; i < m + n; i++) dp2[i][i] = 1;
        for (int l = 2; l <= m + n; l++) {
            for (int i = 0; i + l <= m + n; i++) {
                int j = i + l - 1;
                if (s[i] == s[j])
                {
                    dp2[i][j] = 2 + dp2[i + 1][j - 1];
                }
                else if (dp2[i + 1][j] > dp2[i][j - 1])
                {
                    dp2[i][j] = dp2[i + 1][j];
                }
                else
                {
                    dp2[i][j] = dp2[i][j - 1];
                }
            }
        }
        vector<vector<int>> dp(m, vector<int>(n));
        dp[m - 1][0] = word1[m - 1] == word2[0] ? 2 : 0;
        for (int j = 1; j < n; j++)
        {
            if (word2[j] == word1[m - 1]) dp[m - 1][j] = 2 + dp2[m][m + j - 1];
            else dp[m - 1][j] = max(dp[m - 1][j], dp[m - 1][j - 1]);
        }
        for (int i = m - 2; ~i; i--)
        {
            if (word1[i] == word2[0]) dp[i][0] = 2 + dp2[i + 1][m - 1];
            else dp[i][0] = max(dp[i][0], dp[i + 1][0]);
        }
        for (int i = m - 2; ~i; i--)
        {
            for (int j = 1; j < n; j++)
            {
                if (word1[i] == word2[j]) dp[i][j] = 2 + dp2[i + 1][m + j - 1];
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};