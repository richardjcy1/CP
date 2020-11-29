#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
Minimum score triangulation of polygon (Interval DP)

dp[i][j]: a[i...j] min score
dp[i][j]=min(dp[i][k]+dp[k][j]+a[i]*a[k]*a[j])

NOTE:
dp initialization
result is dp[0][n - 1]

T:O(n^3)
S:O(n^2)
*/

class Solution {
public:
    int minScoreTriangulation(vector<int>& a) {
        int n = a.size();
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        for (int l = 3; l <= n; l++)
        {
            for (int i = 0; i + l <= n; i++)
            {
                int j = i + l - 1;
                dp[i][j] = INF;
                for (int k = i + 1; k < j; k++) 
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (ll)a[i] * a[j] * a[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> v{{1,2,3},{3,7,4,5},{1,3,1,4,1,5}};
    Solution sol;
    for (auto a: v) cout << sol.minScoreTriangulation(a) << endl;
    return 0;
}