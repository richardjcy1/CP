typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
ll dp[maxn];

class Solution {
public:
    string s;
    int n, k;
    
    ll solve(int pos)
    {
        if (pos == n) return 1;
        if (dp[pos] != -1) return dp[pos];
        if (s[pos] == '0') return 0;
        ll ans = 0;
        for (int i = pos; i < n; i++)
        {
            if (stoll(s.substr(pos, i - pos + 1)) > k) break;
            ans = (ans + solve(i + 1)) % mod;
        }
        return dp[pos] = ans;
    }
    
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof dp);
        this->s = s;
        this->k = k;
        n = s.size();
        return solve(0);
    }
};