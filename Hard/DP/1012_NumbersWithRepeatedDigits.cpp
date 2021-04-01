typedef long long ll;
ll dp[15][1 << 10][2][2];

class Solution {
public:
    string s;
    int n;
    
    ll dfs(int pos, int state, bool limit, bool lead)
    {
        if (pos == n) return 1;
        if (dp[pos][state][limit ? 1 : 0][lead ? 1 : 0] != -1) return dp[pos][state][limit ? 1 : 0][lead ? 1 : 0];
        ll ans = 0;
        int up = limit ? s[pos] - '0' : 9;
        for (int i = 0; i <= up; i++)
        {
            if (lead)
            {
                if (i)
                {
                    if (!(state & (1 << i)))
                    {
                        ans += dfs(pos + 1, state | 1 << i, limit && i == s[pos] - '0', false);
                    }
                }
                else
                {
                    ans += dfs(pos + 1, state, limit && i == s[pos] - '0', true);
                }
            }
            else
            {
                if (!(state & (1 << i)))
                {
                    ans += dfs(pos + 1, state | 1 << i, limit && i == s[pos] - '0', false);
                }
            }
        }
        return dp[pos][state][limit ? 1 : 0][lead ? 1 : 0] = ans;
    }
    
    ll solve(int N)
    {
        s = to_string(N);
        n = s.size();
        return dfs(0, 0, true, true);
    }
    
    int numDupDigitsAtMostN(int N) {
        memset(dp, -1, sizeof dp);
        ll ans = solve(N);
        return N - ans + 1;
    }
};