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
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<string> rv(n);
    for (int i = 0; i < n; i++)
    {
        string tmp = v[i];
        reverse(tmp.begin(), tmp.end());
        rv[i] = tmp;
    }
    bool ok = true;
    vector<vector<ll>> dp(n, vector<ll>(2, LLONG_MAX));
    dp[0][0] = 0; dp[0][1] = c[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i].compare(v[i - 1]) >= 0 && dp[i - 1][0] != LLONG_MAX) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (v[i].compare(rv[i - 1]) >= 0 && dp[i - 1][1] != LLONG_MAX) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (rv[i].compare(v[i - 1]) >= 0 && dp[i - 1][0] != LLONG_MAX) dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        if (rv[i].compare(rv[i - 1]) >= 0 && dp[i - 1][1] != LLONG_MAX) dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
        if (dp[i][0] == LLONG_MAX && dp[i][1] == LLONG_MAX)
        {
            ok = false;
            break;
        }
    }
    ll ans = min(dp[n - 1][0], dp[n - 1][1]);
    if (!ok) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}   