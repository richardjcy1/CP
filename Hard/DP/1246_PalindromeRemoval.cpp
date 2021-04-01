class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = 0; i < n - 1; i++)
        {
            dp[i][i + 1] = arr[i] == arr[i + 1] ? 1 : 2;
        }
        for (int l = 3; l <= n; l++)
        {
            for (int i = 0; i + l <= n; i++)
            {
                int j = i + l - 1;
                dp[i][j] = 1 + dp[i + 1][j];
                if (arr[i] == arr[i + 1]) dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
                for (int k = i + 2; k <= j; k++)
                {
                    if (arr[i] == arr[k])
                    {
                        if (k + 1 <= j) dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
                        else dp[i][j] = min(dp[i][j], dp[i + 1][k - 1]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};