const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minCost(int N, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(N);
        sort(cuts.begin(), cuts.end());
        vector<int> a;
        for (int i = 1; i < cuts.size(); i++)
        {
            a.push_back(cuts[i] - cuts[i - 1]);
        }
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = a[i] + a[i + 1];
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
        for (int l = 3; l <= n; l++)
        {
            for (int i = 0; i + l <= n; i++)
            {
                int j = i + l - 1;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j + 1] - sum[i]);
                }
            }
        }
        return dp[0][n - 1];
    }
};