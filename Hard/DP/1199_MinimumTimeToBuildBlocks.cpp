typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
ll dp[maxn][maxn];

class Solution {
public:
    int split;
    vector<int> b;
    int n;
    
    ll solve(int idx, int rem)
    {
        if (idx == n) return 0;
        if (rem <= 0) return INF;
        if (n - idx <= rem) return b[idx];
        if (dp[idx][rem] != -1) return dp[idx][rem];
        ll ans = split + solve(idx, rem * 2);
        ans = min(ans, max((ll)b[idx], solve(idx + 1, rem - 1)));
        return dp[idx][rem] = ans;
    }
    
    int minBuildTime(vector<int>& blocks, int split) {
        memset(dp, -1, sizeof dp);
        b = blocks;
        sort(b.begin(), b.end(), greater<int>());
        this->split = split;
        n = b.size();
        return solve(0, 1);
    }
};