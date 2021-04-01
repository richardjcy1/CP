int dp[30][1000][7][7];

class Solution {
public:
    int getMaxGridHappiness(int m, int n, int in, int ex) {
        // dp[cur][mask][in][ex]
        // dp[cur + 1][new_mask][new_in][new_ex]
        memset(dp, 0, sizeof dp);
        int p[n + 1];
        p[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            p[i] = 3 * p[i - 1];
        }
        for (int cur = 0; cur < m * n; cur++)
        {
            for(int mask = 0; mask < p[n]; mask++)
            {
                for (int i = 0; i <= in; i++)
                {
                    for (int j = 0; j <= ex; j++)
                    {
                        int tot_in = 0, tot_ex = 0, x = mask;
                        while (x)
                        {
                            if (x % 3 == 1)
                            {
                                tot_in++;
                            }
                            else if (x % 3 == 2)
                            {
                                tot_ex++;
                            }
                            x /= 3;
                        }
                        if (tot_in > i || tot_ex > j) continue;
                        int in_score = 120, ex_score = 40;
                        dp[cur + 1][(mask % p[n - 1]) * 3][i][j] = max(dp[cur + 1][(mask % p[n - 1]) * 3][i][j], dp[cur][mask][i][j]);
                        if (mask % 3 == 1)
                        {
                            if (cur % n != 0)
                            {
                                in_score -= 60;
                                ex_score = ex_score + 20 - 30;
                            }
                        }
                        else if (mask % 3 == 2)
                        {
                            if (cur % n != 0)
                            {
                                in_score = in_score - 30 + 20;
                                ex_score = ex_score + 40;
                            }
                        }
                        if ((mask / p[n - 1]) % 3 == 1)
                        {
                            if (cur / n > 0)
                            {
                                in_score -= 60;
                                ex_score = ex_score + 20 - 30;
                            }
                        }
                        else if ((mask / p[n - 1]) % 3 == 2)
                        {
                            if (cur / n > 0)
                            {
                                in_score = in_score - 30 + 20;
                                ex_score = ex_score + 40;
                            }
                        }
                        if (i + 1 <= in)
                        {
                            dp[cur + 1][(mask % p[n - 1]) * 3 + 1][i + 1][j] = max(dp[cur + 1][(mask % p[n - 1]) * 3 + 1][i + 1][j], in_score + dp[cur][mask][i][j]);
                        }
                        if (j + 1 <= ex)
                        {
                            dp[cur + 1][(mask % p[n - 1]) * 3 + 2][i][j + 1] = max(dp[cur + 1][(mask % p[n - 1]) * 3 + 2][i][j + 1], ex_score + dp[cur][mask][i][j]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int mask = 0; mask < p[n]; mask++)
        {
            for (int i = 0; i <= in; i++)
            {
                for (int j = 0; j <= ex; j++)
                {
                    ans = max(ans, dp[m * n][mask][i][j]);
                }
            }
        }
        return ans;
    }
};