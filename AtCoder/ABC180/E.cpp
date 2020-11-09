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
    vector<tuple<ll, ll, ll>> v;
    for (int i = 0; i < n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        v.push_back(make_tuple(x, y, z));
    }
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) g[i][j] = 0;
            else g[i][j] = abs(get<0>(v[i]) - get<0>(v[j])) + abs(get<1>(v[i]) - get<1>(v[j])) + max((ll)0, get<2>(v[i]) - get<2>(v[j]));
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(1 << n, LLONG_MAX));
    dp[0][1] = 0;
    for (int mask = 2; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((mask & (1 << i)) && (mask & (1 << j)))
                {
                    if (dp[j][mask - (1 << i)] != LLONG_MAX)
                    {
                        dp[i][mask] = min(dp[i][mask],  dp[j][mask - (1 << i)] + g[j][i]);
                    }
                }
            }
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[i][(1 << n) - 1] + g[i][0]);
    }
    cout << ans << endl;
    return 0;
}