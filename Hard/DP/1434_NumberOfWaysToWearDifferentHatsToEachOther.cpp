const int mod = 1e9 + 7;

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<int>> a(41, vector<int>());
        for (int i = 0; i < n; i++)
        {
            for (int j: hats[i])
            {
                a[j].push_back(i);
            }
        }
        vector<vector<int>> dp(42, vector<int>(1 << n));
        dp[0][0] = 1;
        for (int i = 0; i <= 40; i++)
        {
            for (int mask = 0; mask < 1 << n; mask++)
            {
                dp[i + 1][mask] += dp[i][mask];
                dp[i + 1][mask] %= mod;
                for (int j: a[i])
                {
                    if (!(mask & (1 << j)))
                    {
                        dp[i + 1][mask | (1 << j)] += dp[i][mask];
                        dp[i + 1][mask | (1 << j)] %= mod;
                    }
                }
            }
        }
        return dp[41][(1 << n) - 1];
    }
};