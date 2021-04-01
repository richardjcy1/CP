typedef long long ll;
ll dp[64][2][2][2];

class Solution {
public:
    string s;
    int n;
    
    ll dfs(int pos, bool prev, bool lead, bool limit)
    {
        if (pos == n) return 1;
        if (dp[pos][prev ? 1 : 0][lead ? 1 : 0][limit ? 1 : 0] != -1) return dp[pos][prev ? 1 : 0][lead ? 1 : 0][limit ? 1 : 0];
        ll ans = 0;
        int up = limit ? s[pos] - '0' : 1;
        for (int i = 0; i <= up; i++)
        {
            if (prev && i) continue;
            ans += dfs(pos + 1, i == 1, lead && i == 0, limit && i == (s[pos] - '0'));
        }
        return dp[pos][prev ? 1 : 0][lead ? 1 : 0][limit ? 1 : 0] = ans;
    }
    
    ll solve(int N)
    {
        while (N)
        {
            s += (char)(N % 2 + '0');
            N >>= 1;
        }
        reverse(s.begin(), s.end());
        n = s.size();
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, true, true);
    }
    
    int findIntegers(int num) {
        return solve(num);
    }
};