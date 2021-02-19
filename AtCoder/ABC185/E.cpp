#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    /*dp[i][j]:up to ith in a and jth in b, min x + y
    return dp[n][m]
    base:dp[0][i]=i;dp[i][0]=i;
    dp[i][j]=a[i-1]==b[j-1]?dp[i-1][j-1]:min(1+dp[i-1][j],1+dp[i][j-1],1+dp[i-1][j-1])
    */
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) dp[i][0] = i;
    for (int i = 1; i <= m; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + dp[i - 1][j];
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}