const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minimumTimeRequired(vector<int>& a, int k) {
        int n = a.size();
        vector<vector<int>> dp(k, vector<int>(1 << n, INF));
        vector<int> cost(1 << n);
        for (int mask = 0; mask < 1 << n; mask++)
        {
            int v = 0;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i)) v += a[i];
            }
            cost[mask] = v;
        }
        for (int j = 0; j < 1 << n; j++) dp[0][j] = cost[j];
        for (int i = 1; i < k; i++)
        {
            for (int mask = 0; mask < 1 << n; mask++)
            {
                int v = INF;
                for (int j = mask; j; j = (j - 1) & mask)
                {
                    v = min(v, max(cost[j], dp[i - 1][mask - j]));
                }
                dp[i][mask] = min(dp[i][mask], v);
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};