#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    int tot = accumulate(a.begin(), a.end(), 0);
    if (tot < n) { cout << -1 << endl; return 0; }
    vector<vector<ll>> dp(tot + 1, vector<ll>(n + 1));
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= tot; i++)
    {
        for (int j = 0; j < min(i / 2 + 1, n); j++)
        {
            if (!j) 
            {
                dp[i][0] = 1;
                if (i <= n) dp[i][i] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                if (i - j <= n) dp[i][i - j] = dp[i][j];
            }
            // cout << i << " " << j << " " << dp[i][j]  << " " << dp[i][i - j] << endl; 
        }
    }
    double ans = 1.0 - (dp[tot - a[h - 1]][n - 1] / (dp[tot - 1][n - 1] + 0.0));
    cout << ans << endl;

    return 0;
}