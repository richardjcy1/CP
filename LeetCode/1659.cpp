#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int dp[30][1000][7][7];

/*

0: empty 1:introvert 2:extrovert
dp[cur][mask]: previous mask, at cur position, max score

dp[cur + 1][new_mask] = score() + dp[cur][mask]
new_mask = mask % pow(3, n - 1) * 3 + 0/1/2
score(cur, mask): left, up cases

return max(dp[m * n][mask])


*/

class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        int p[n + 1];
        p[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            p[i] = 3 * p[i - 1];
        }
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < m * n; i++)
        {
            for (int mask = 0; mask < p[n]; mask++)
            {
                for (int j = 0; j <= introvertsCount; j++)
                {
                    for (int k = 0; k <= extrovertsCount; k++)
                    {
                        int cnti = 0, cnto = 0, x = mask;
                        for (int u = 0; u < n; u++)
                        {
                            if (x % 3 == 1)
                            {
                                ++cnti;
                            }
                            else if (x % 3 == 2)
                            {
                                ++cnto;
                            }
                            x /= 3;
                        }
                        if (cnti > j || cnto > k) continue;
                        int row = i / n, col = i % n;
                        dp[i + 1][(mask % p[n - 1]) * 3][j][k] = max(dp[i + 1][(mask % p[n - 1]) * 3][j][k], dp[i][mask][j][k]);
                        int in = 120, out = 40;
                        if (col)
                        {
                            if (mask % 3 == 1)
                            {
                                in = in - 2 * 30;
                                out = out + 20 - 30;
                            }
                            else if (mask % 3 == 2)
                            {
                                in = in - 30 + 20;
                                out = out + 20 * 2;
                            }
                        }
                        if (row)
                        {
                            if ((mask / p[n - 1]) % 3 == 1)
                            {
                                in = in - 2 * 30;
                                out = out + 20 - 30;
                            }
                            else if ((mask / p[n - 1]) % 3 == 2)
                            {
                                in = in - 30 + 20;
                                out = out + 20 * 2;
                            }
                        }
                        if (j + 1 <= introvertsCount)
                        {
                            dp[i + 1][(mask % p[n - 1]) * 3 + 1][j + 1][k] = max(dp[i + 1][(mask % p[n - 1]) * 3 + 1][j + 1][k], in + dp[i][mask][j][k]);
                        }
                        if (k + 1 <= extrovertsCount)
                        {
                            dp[i + 1][(mask % p[n - 1]) * 3 + 2][j][k + 1] = max(dp[i + 1][(mask % p[n - 1]) * 3 + 2][j][k + 1], out + dp[i][mask][j][k]);
                        }
                        // cout << i << " " << mask << " " << j << " " << k << " " << dp[i][mask][j][k] << endl;
                    }
                }
            }
        }
        int ans = 0;
        for (int mask = 0; mask < p[n]; mask++)
        {
            for (int i = 0; i <= introvertsCount; i++)
            {
                for (int j = 0; j <= extrovertsCount; j++)
                {
                    ans = max(ans, dp[m * n][mask][i][j]);
                }
            }
        }
        return ans;
    }
                                                                      
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}