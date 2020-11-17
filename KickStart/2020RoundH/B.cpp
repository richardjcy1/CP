#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll dp[20][2];

ll solve(string s)
{
    int n = s.size();
    memset(dp, 0, sizeof dp);
    if ((n - 1) & 1)
    {
        dp[n - 1][0] = 5;
        dp[n - 1][1] = (s[n - 1] - '0') / 2;
    }
    else
    {
        dp[n - 1][0] = 5;
        dp[n - 1][1] = (s[n - 1] - '0' + 1) / 2;
    }
    for (int i = n - 2; ~i; i--)
    {
        int digit = s[i] - '0';
        for (int j = 0; j <= digit; j++)
        {
            if (j == digit)
            {
                dp[i][1] += dp[i + 1][1];
            }
            else
            {
                dp[i][0] += dp[i + 1][0];
            }
        }
    }
    return dp[0][0] + dp[0][1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int kase = 0;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        --l;
        string sl = to_string(l);
        string sr = to_string(r);
        int m = sl.size(), n = sr.size();
        ll ans = solve(sr) - solve(sl);
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}