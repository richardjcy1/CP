#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef long long ll;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j]: up to i in nums1 and j in nums2 max dot product
        // dp[i][j]=max(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+nums1[i]*nums2[j])
        int m = nums1.size(), n = nums2.size();
        vector<vector<ll>> dp(m, vector<ll>(n));
        dp[0][0] = nums1[0] * nums2[0];
        for (int j = 1; j < n; j++) 
        {
            dp[0][j] = max(dp[0][j - 1], (ll)nums1[0] * (ll)nums2[j]);
        }
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = max(dp[i - 1][0], (ll)nums1[i] * (ll)nums2[0]);
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (ll)nums1[i] * nums2[j]);
                dp[i][j] = max(dp[i][j], (ll)nums1[i] * (ll)nums2[j]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}