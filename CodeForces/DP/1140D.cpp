#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    /*
    dp[i][j]:[i...j] min sum
    return dp[1][n]
    base:dp[i][i+2]=i*(i+1)*(i+2)
    dp[i][j]=min(dp[i][k]+dp[k][j]+i*k*j)
    */
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for (int i = 1; i + 2 <= n; i++)
    {
        dp[i][i + 2] = i * (i + 1) * (i + 2);
    }
    for (ll l = 4; l <= n; l++)
    {
        for (ll i = 1; i + l - 1 <= n; i++)
        {
            ll j = i + l - 1;
            dp[i][j] = INF;
            for (int k = i + 2; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + i * j * k);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}