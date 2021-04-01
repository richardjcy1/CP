```
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e4 + 5;
ll dp[maxn][5];

class Solution {
public:
    int countVowelPermutation(int n) {
        memset(dp, 0, sizeof dp);
        for (int j = 0; j < 5; j++) dp[0][j] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (j == 0)
                {
                    dp[i + 1][1] = (dp[i + 1][1] + dp[i][j]) % mod;
                }
                else if (j == 1)
                {
                    dp[i + 1][0] = (dp[i + 1][0] + dp[i][j]) % mod;
                    dp[i + 1][2] = (dp[i + 1][2] + dp[i][j]) % mod;
                }
                else if (j == 2)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        if (j != k) dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % mod;
                    }
                }
                else if (j == 3)
                {
                    dp[i + 1][2] = (dp[i + 1][2] + dp[i][j]) % mod;
                    dp[i + 1][4] = (dp[i + 1][4] + dp[i][j]) % mod;
                }
                else
                {
                    dp[i + 1][0] = (dp[i + 1][0] + dp[i][j]) % mod;
                }
            }
        }
        ll ans = 0;
        for (int j = 0; j < 5; j++)
        {
            ans = (ans + dp[n - 1][j]) % mod;
        }
        return ans;
    }
};
```

Solution 2: DFS+Memoization
最简单好想的思路一定是记忆化搜索 (标准操作)
```
typedef long long ll;
const int maxn = 2e4 + 5;
const int mod = 1e9 + 7;
ll dp[maxn][5];

class Solution {
public:
    int n;
    
    ll solve(int idx, int pos)
    {
        if (idx == n - 1) return 1;
        if (dp[idx][pos] != -1) return dp[idx][pos];
        ll ans = 0;
        if (pos == 0)
        {
            ans = (ans + solve(idx + 1, 1)) % mod;
        }
        else if (pos == 1)
        {
            ans = (ans + solve(idx + 1, 0)) % mod;
            ans = (ans + solve(idx + 1, 2)) % mod;
        }
        else if (pos == 2)
        {
            for (int i = 0; i < 5; i++)
            {
                if (i != 2)
                {
                    ans = (ans + solve(idx + 1, i)) % mod;
                }
            }
        }
        else if (pos == 3)
        {
            ans = (ans + solve(idx + 1, 2)) % mod;
            ans = (ans + solve(idx + 1, 4)) % mod;
        }
        else
        {
            ans = (ans + solve(idx + 1, 0)) % mod;
        }
        return dp[idx][pos] = ans;
    }
    
    int countVowelPermutation(int n) {
        memset(dp, -1, sizeof dp);
        this->n = n;
        ll ans = 0;
        for (int i = 0; i < 5; i++)
        {
            ans = (ans + solve(0, i)) % mod;
        }
        return ans;
    }
};