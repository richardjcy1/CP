```
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        int p[n + 2];
        p[0] = 1;
        for (int i = 1; i < n + 2; i++)
        {
            p[i] = 2 * p[i - 1];
        }
        vector<vector<int>> dp(m * n + 1, vector<int>(1 << (n + 1)));
        for (int i = 0; i < m * n; i++)
        {
            for (int mask = 0; mask < p[n + 1]; mask++)
            {
                int row = i / n, col = i % n;
                if (seats[row][col] == '#')
                {
                    dp[i + 1][(mask % (p[n])) * 2] = max(dp[i + 1][(mask % p[n]) * 2], dp[i][mask]);           
                }
                else
                {
                    dp[i + 1][(mask % p[n]) * 2] = max(dp[i + 1][(mask % p[n]) * 2], dp[i][mask]);
                    if ((col == 0 || (mask % 2) != 1) && (col == n - 1 || (mask / p[n - 2]) % 2 != 1) && (col == 0 || (mask / (int)(p[n])) % 2 != 1))
                    {
                        dp[i + 1][(mask % p[n]) * 2 + 1] = max(dp[i + 1][(mask % p[n]) * 2 + 1], 1 + dp[i][mask]);
                    }
                }
            }
        }
        int ans = 0;
        for (int mask = 0; mask < p[n + 1]; mask++)
        {
            ans = max(ans, dp[m * n][mask]);
        }
        return ans;
    }
};
```

Space complexity optimized to O(n*2^(n+1))
```
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        vector<vector<int>> dp(n, vector<int>(1 << (n + 1)));
        for (int i = 0; i < m * n; i++)
        {
            for (int mask = 0; mask < 1 << (n + 1); mask++)
            {
                int row = i / n, col = i % n;
                if (seats[row][col] == '#')
                {
                    dp[(col + 1) % n][(mask % (1 << n)) * 2] = max(dp[(col + 1) % n][(mask % (1 << n)) * 2], dp[col][mask]);           
                }
                else
                {
                    dp[(col + 1) % n][(mask % (1 << n)) * 2] = max(dp[(col + 1) % n][(mask % (1 << n)) * 2], dp[col][mask]);
                    if ((col == 0 || (mask % 2) != 1) && (col == n - 1 || (mask / (1 << (n - 2))) % 2 != 1) && (col == 0 || (mask / (int)(1 << n)) % 2 != 1))
                    {
                        dp[(col + 1) % n][(mask % (1 << n)) * 2 + 1] = max(dp[(col + 1) % n][(mask % (1 << n)) * 2 + 1], 1 + dp[col][mask]);
                    }
                }
            }
        }
        int ans = 0;
        for (int mask = 0; mask < 1 << (n + 1); mask++)
        {
            ans = max(ans, dp[0][mask]);
        }
        return ans;
    }
};
```