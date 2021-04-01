const int INF = 0x3f3f3f3f;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(m + 1, INF));
        dp[0][1] = nums[0];
        for (int i = 1; i < n; i++) dp[i][1] = dp[i - 1][1] + nums[i];
        for (int i = 1; i < n; i++)
        {
            for (int j = 2; j <= m; j++)
            {
                int mi = 0;
                for (int k = i; k >= j - 1; k--)
                {
                    mi += nums[k];
                    dp[i][j] = min(dp[i][j], max(dp[k - 1][j - 1], mi));
                }
            }
        }
        return dp[n - 1][m];
    }
};