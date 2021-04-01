typedef long long ll;
const int mod = 1e9 + 7;
ll dp[55][105][105];

class Solution {
public:
    int n, m;
    
    ll solve(int idx, int prev, int tot)
    {
        if (idx == n)
        {
            return tot == 0;
        }
        if (dp[idx][prev][tot] != -1) return dp[idx][prev][tot];
        ll ans = prev * solve(idx + 1, prev, tot) % mod;
        for (int i = prev + 1; i <= m; i++)
        {
            if (tot) ans = (ans + solve(idx + 1, i, tot - 1)) % mod;
        }
        return dp[idx][prev][tot] = ans;
    }
    
    int numOfArrays(int n, int m, int k) {
        this->n = n;
        this->m = m;
        memset(dp, -1, sizeof dp);
        return solve(0, 0, k);        
    }
};