const int INF = 0x3f3f3f3f;

class Solution {
public:
    int solve(vector<int>& prices, int k)
    {
        int n = prices.size();
        vector<vector<int>> h(n, vector<int>(k + 1, -INF));
        vector<vector<int>> s(n, vector<int>(k + 1, -INF));
        h[0][0] = -prices[0];
        s[0][0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                h[i][j] = max(h[i - 1][j], s[i - 1][j] - prices[i]);
                s[i][j] = s[i - 1][j];
                if (j) s[i][j] = max(s[i][j], h[i - 1][j - 1] + prices[i]);
            }
        }
        int ans = -INF;
        for (int j = 0; j <= k; j++)
        {
            ans = max(ans, s[n - 1][j]);
        }
        return ans;
    }
    
    int maxProfit(vector<int>& prices) {
        return solve(prices, 2);
    }
};