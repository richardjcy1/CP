typedef long long ll;
constexpr int mod = 1e9 + 7;

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= min(k, i * (i - 1) / 2); j++)
            {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                dp[i][j] = (dp[i][j] - (j - i >= 0 ? dp[i - 1][j - i] : 0) + mod) % mod;
            }
        }
        return dp[n][k];
    }
};