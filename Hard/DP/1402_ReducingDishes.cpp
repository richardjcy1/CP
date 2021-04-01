typedef long long ll;
const int maxn = 505;
ll dp[maxn][maxn];

class Solution {
public:
    vector<int> s;
    int n;
    
    ll solve(int idx, int prev)
    {
        if (idx == n) return 0;
        if (dp[idx][prev] != -1) return dp[idx][prev];
        ll ans = solve(idx + 1, prev);
        ans = max(ans, (ll)s[idx] * (prev + 1) + solve(idx + 1, prev + 1));
        return dp[idx][prev] = ans;
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        memset(dp, -1, sizeof dp);
        s = satisfaction;
        n = s.size();
        sort(s.begin(), s.end());
        return solve(0, 0);
    }
};