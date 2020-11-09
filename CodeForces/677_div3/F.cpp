#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 75;

int dp[maxn][maxn][maxn][maxn];
int row[maxn][maxn];
int f[maxn][maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, K;
    cin >> n >> m >> K;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    memset(dp, -INF, sizeof dp);
    for (int r = 0; r < n; r++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int k = 0; k < K; k++)
            {
                dp[i][0][k][r] = 0;
            }
        }
    }
    for (int r = 0; r < n; r++)
    {
        for (int j = 0; j <= m / 2; j++)
        {
           for (int k = 0; k < K; k++)
           {
               if (j && k == (a[r][m - 1] % K))
               {
                   dp[m - 1][j][k][r] = a[r][m - 1];
               }
               else if (!j) dp[m - 1][j][k][r] = 0;
           }
        }
    } 
    

    for (int r = 0; r < n; r++)
    {
        for (int i = m - 2; ~i; i--)
        {
            for (int j = 1; j <= m / 2; j++)
            {
                for (int k = 0; k < K; k++)
                {
                    if (j > 1 || (j == 1 && k == a[r][i] % K))
                        dp[i][j][k][r] = max(dp[i + 1][j][k][r], a[r][i] + dp[i + 1][j - 1][(k + K - a[r][i] % K) % K][r]);
                    cout << "dp[" << i << "][" << j << "][" << k << "][" << r << "]: " << dp[i][k][k][r] << endl;

                }
            }
        }
    }
    memset(f, 0, sizeof f);
    memset(row, 0, sizeof row);
    for (int r = 0; r < n; r++)
    {
        for (int k = 0; k < K; k++)
        {
            int tmp = 0;
            for (int j = 1; j <= m / 2; j++) 
            {
                tmp = max(tmp, dp[0][j][k][r]);
            }
            row[r][k] = tmp;
        }
    }
    for (int k = 0; k < K; k++)
    {
        f[0][k] = row[0][k];
    }
    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k < K; k++)
        {
            for (int j = 0; j < K; j++)
            {
                f[i][k] = max(f[i][k], row[i][j] + f[i - 1][(k + K - j) % K]);
            }
        }
    }
    cout << f[n - 1][0] << endl;
    return 0;
}