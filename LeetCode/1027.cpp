#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
Longest arithmetic subsequence (DP)

dp[idx][diff]: ending at idx, with diff, longest length of arithmetic subsequence
dp[i][a[i]-a[j]+500]=max(1+dp[j][a[i]-a[j]+500])

diff range:-500 - 500 we add 500 to both so in range [0,1000]

T:O(n*D)
S:O(n*D)
*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n = a.size();
        if (n < 3) return 0;
        vector<vector<int>> dp(n, vector<int>(1005, 1));
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i][a[i] - a[j] + 500] = max(dp[i][a[i] - a[j] + 500], 1 + dp[j][a[i] - a[j] + 500]);
                ans = max(ans, dp[i][a[i] - a[j] + 500]);
            }
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int>> v{{3,6,9,12},{9,4,7,2,10},{20,1,15,3,10,5,8}};
    Solution sol;
    for (auto a: v) cout << sol.longestArithSeqLength(a) << endl;
    return 0;
}