#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) cin >> b[i][j];
    }
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(12805)));
    dp[0][0][abs(a[0][0] - b[0][0])] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 12805; k++)
            {
                if (dp[i][j][k])
                {
                    if (i + 1 < m)
                    {
                        dp[i + 1][j][k + abs(a[i + 1][j] - b[i + 1][j])] = 1;
                        dp[i + 1][j][abs(k - abs(a[i + 1][j] - b[i + 1][j]))] = 1;
                    }
                    if (j + 1 < n)
                    {
                        dp[i][j + 1][k + abs(a[i][j + 1] - b[i][j + 1])] = 1;
                        dp[i][j + 1][abs(k - abs(a[i][j + 1] - b[i][j + 1]))] = 1;
                    }
                }
            }
        }
    }
    int k = 0;
    for (; k < 12805; k++)
    {
        if (dp[m - 1][n - 1][k]) break;
    }
    cout << k << endl;
    return 0;
}