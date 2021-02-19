#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    vector<vector<ll>> dp(n, vector<ll>(3));
    for (int i = 0 ; i < k; i++)
    {
        if (t[i] == 'r') dp[i][2] = p;
        else if (t[i] == 's') dp[i][0] = r;
        else dp[i][1] = s;
    }
    for (int i = k; i < n; i++)
    {
        if (t[i] == 'r')
        {
            dp[i][0] += max(dp[i - k][1], dp[i - k][2]);
            dp[i][1] += max(dp[i - k][0], dp[i - k][2]);
            dp[i][2] += p + max(dp[i - k][0], dp[i - k][1]);
        }
        else if (t[i] == 's')
        {
            dp[i][0] += r + max(dp[i - k][1], dp[i - k][2]);
            dp[i][1] += max(dp[i - k][0], dp[i - k][2]);
            dp[i][2] += max(dp[i - k][0], dp[i - k][1]);
        }
        else
        {
            dp[i][0] += max(dp[i - k][1], dp[i - k][2]);
            dp[i][1] += s + max(dp[i - k][0], dp[i - k][2]);
            dp[i][2] += max(dp[i - k][0], dp[i - k][1]);
        }
    }
    ll ans = 0;
    for (int i = n - k; i < n; i++)
    {
        ans += max({dp[i][0], dp[i][1], dp[i][2]});
    }
    cout << ans << endl;
    return 0;
}