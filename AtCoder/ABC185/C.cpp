#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    /*dp[i][j]:at pos i, cut into j pieces number of ways
    return dp[0][L-1]
    base:dp[i][0]=1;dp[n][0]=1;dp[n][j]=0;
    dp[i][j]=sum(dp[k][j-1])
    */
    ll L;
    cin >> L;
    vector<vector<ll>> dp(L + 1, vector<ll>(13));
    for (ll i = 0; i < L; i++) dp[i][0] = 1;
    for (ll i = L - 1; ~i; i--)
    {
        for (ll j = 1; j <= 11; j++)
        {
            for (ll k = i + 1; k <= L; k++)
            {
                dp[i][j] += dp[k][j - 1];
            }
        }
    }
    cout << dp[0][11] << endl;
    return 0;
}