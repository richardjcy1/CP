class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int ans = 0;
        for (int mask = 0; mask < 1 << m; mask++)
        {
            vector<int> dp(n);
            for (int i = 0; i < m; i++)
            {
                if (mask & (1 << i))
                {
                    dp[requests[i][0]]--;
                    dp[requests[i][1]]++;
                }
            }
            bool ok = true;
            for (int j = 0; j < n; j++)
            {
                if (dp[j])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                ans = max(ans, __builtin_popcount(mask));
            }
        }
        return ans;
    }
};