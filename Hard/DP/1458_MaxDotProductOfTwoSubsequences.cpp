typedef long long ll;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<ll>> dp(m, vector<ll>(n, -INF));
        dp[0][0] = nums1[0] * nums2[0];
        for (int i = 1; i < m; i++) dp[i][0] = max(dp[i - 1][0], (ll)nums1[i] * nums2[0]);
        for (int i = 1; i < n; i++) dp[0][i] = max(dp[0][i - 1], (ll)nums1[0] * nums2[i]);
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = max(dp[i - 1][j - 1], (ll)nums1[i] * nums2[j]);
                dp[i][j] = max(dp[i][j], (ll)nums1[i] * nums2[j] + dp[i - 1][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};