typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 505;
ll dp[maxn][maxn];

class Solution {
public:
    ll solve(vector<int>& a, int pos, int k)
    {
        if (pos >= a.size())
        {
            return k == 0 ? 0 : -INF;
        }
        if (dp[pos][k] != -1) return dp[pos][k];
        ll ans = solve(a, pos + 1, k);
        if (k) ans = max(ans, a[pos] + solve(a, pos + 2, k - 1));
        return dp[pos][k] = ans;
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<int> a(slices.begin(), slices.end() - 1);
        vector<int> b(slices.begin() + 1, slices.end());
        memset(dp, -1, sizeof dp);
        ll ans1 = solve(a, 0, n / 3);
        memset(dp, -1, sizeof dp);
        ll ans2 = solve(b, 0, n / 3);
        return max(ans1, ans2);
    }
};