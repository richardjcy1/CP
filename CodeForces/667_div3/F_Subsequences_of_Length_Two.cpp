#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, K;
    cin >> n >> K;
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(3, vector<int>(K + 1, 0)));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            dp[i][0][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            for (int k = 0; k <= K; k++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k];
                }
                else
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                    if (k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + dp[i - 1][j][k - 1]);
                }
                cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }
    cout << dp[n][2][K] << endl;
    return 0;
}