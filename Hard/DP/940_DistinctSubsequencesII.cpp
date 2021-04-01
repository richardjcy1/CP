typedef long long ll;
const int mod = 1e9 + 7;

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<ll> dp(n + 1);
        dp[0] = 1;
        vector<ll> v(26, -1);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = (dp[i - 1] * 2) % mod;
            if (v[s[i - 1] - 'a'] != -1)
            {
                dp[i] = (dp[i] - dp[v[s[i - 1] - 'a'] - 1] + mod) % mod;
            }
            v[s[i - 1] - 'a'] = i;
        }
        return (dp[n] - 1 + mod) % mod;
    }
};