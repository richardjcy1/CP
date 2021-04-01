class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i + 2 < n; i++)
        {
            dp[i][i + 2] = nums[i] * nums[i + 1] * nums[i + 2];
        }
        for (int l = 4; l <= n; l++)
        {
            for (int i = 0; i + l <= n; i++)
            {
                int j = i + l - 1;
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};