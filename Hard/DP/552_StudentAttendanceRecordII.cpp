typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
ll dp[maxn][5][5];

class Solution {
public:
    int checkRecord(int n) {
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 0; k <= 2; k++)
                {
                    if (j + k > i) continue;
                    dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k]) % mod;
                    if (j < 1) dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % mod;
                    if (k < 2) dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % mod;
                }
            }
        }
        ll ans = 0;
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 0; k <= 2; k++)
            {
                ans = (ans + dp[n][j][k]) % mod;
            }
        }
        return ans;
    }
};