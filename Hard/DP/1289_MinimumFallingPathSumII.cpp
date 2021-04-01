const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INF));
        int min1 = INF, min2 = INF;
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < n; j++) 
        {
            dp[m - 1][j] = arr[m - 1][j];
            if (dp[m - 1][j] < min1)
            {
                min2 = min1;
                idx2 = idx1;
                min1 = dp[m - 1][j];
                idx1 = j;
            }
            else if (dp[m - 1][j] < min2)
            {
                min2 = dp[m - 1][j];
                idx2 = j;
            }
        }
        for (int i = m - 2; ~i; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != idx1) dp[i][j] = arr[i][j] + min1;
                else dp[i][j] = arr[i][j] + min2;
            }
            min1 = min2 = INF;
            idx1 = idx2 = -1;
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] < min1)
                {
                    min2 = min1;
                    idx2 = idx1;
                    min1 = dp[i][j];
                    idx1 = j;
                }
                else if (dp[i][j] < min2)
                {
                    min2 = dp[i][j];
                    idx2 = j;
                }
            }
        }
        int ans = INF;
        for (int j = 0; j < n; j++) ans = min(ans, dp[0][j]);
        return ans;
    }
};