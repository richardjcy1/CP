#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int i = 0; i < n - 1; i++) dp[i][i + 1] = 1 - (s[i] == s[i + 1]);
    for (int l = 3; l <= n; l++)
    {
        for (int i = 0; i + l <= n; i++)
        {
            int j = i + l - 1;
            if (s[i] == s[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            else dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}