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
    vector<vector<ll>> g(n, vector<ll>(n));
    vector<tuple<ll, ll, ll>> a;
    for (int i = 0; i < n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        a.push_back(make_tuple(x, y, z));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll d = abs(get<0>(a[i]) - get<0>(a[j])) + abs(get<1>(a[i]) - get<1>(a[j])) + max((ll)0, get<2>(a[j]) - get<2>(a[i]));
            g[i][j] = d;
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(1 << n, LLONG_MAX));
    dp[0][1] = 0;
    for (int mask = 2; mask < 1 << n; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && (mask & 1 << i) && (mask & 1 << j) && dp[j][mask - (1 << i)] != LLONG_MAX)
                {
                    dp[i][mask] = min(dp[i][mask], dp[j][mask - (1 << i)] + g[j][i]);
                }
            }
            //cout << i << " " << mask << " " << dp[i][mask] << endl;
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) ans = min(ans, dp[i][(1 << n) - 1] + g[i][0]);
    cout << ans << endl;
    return 0;
}
