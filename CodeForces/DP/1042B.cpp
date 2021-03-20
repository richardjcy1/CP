#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> c(n);
    vector<string> s(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i] >> s[i];
        sort(s[i].begin(), s[i].end());
        for (char c: s[i])
        {
            b[i] |= (1 << (c - 'A'));
        }
    }
    /*dp[i][j]:upto ith index, with j vitamin min cost
    return dp[n][0b111];
    base:dp[0][0]=0
    dp[i+1][j]=min(dp[i+1][j],dp[i][j])
    dp[i+1][j|s[i]]=min(dp[i+1][j|s[i]],c[i]+dp[i][j])
    */
    vector<vector<int>> dp(n + 1, vector<int>(1 << 3, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (dp[i][j] != INF)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j | b[i]] = min(dp[i + 1][j | b[i]], dp[i][j] + c[i]);
            }
        }
    }
    ll ans = dp[n][7] == INF ? -1 : dp[n][7];
    cout << ans << endl;
    return 0;
}