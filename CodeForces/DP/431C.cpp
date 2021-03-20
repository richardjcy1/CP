#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int maxn = 105;
int n, k, d;
ll dp[maxn][2];

ll solve(int sum, int ok)
{
    if (sum == 0) return 1 - ok;
    if (dp[sum][ok] != -1) return dp[sum][ok];
    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (sum >= i)
        {
            if (ok)
            {
                ans += solve(sum - i, 1);
                ans %= mod;
                if (i >= d) ans += solve(sum - i, 0);
                ans %= mod;
            }
            else
            {
                if (i < d)
                {
                    ans += solve(sum - i, 0);
                    ans %= mod;
                }
            }
        }
    }
    return dp[sum][ok] = ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> d;
    memset(dp, -1, sizeof dp);
    cout << solve(n, 1) << endl;

    return 0;
}