#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
unordered_map<int, unordered_map<int, ll>> dp;
int n;
ll a[maxn];

ll solve(int idx, int sign)
{
    if (idx == n - 2)
    {
        if (sign)
        {
            return max(a[n - 2] + a[n - 1], -a[n - 2] - a[n - 1]);
        }
        else
        {
            return max(-a[n - 2] + a[n - 1], a[n - 2] - a[n - 1]);
        }
    }
    if (dp.find(idx) != dp.end() && dp[idx].find(sign) != dp[idx].end()) return dp[idx][sign];
    ll ans = 0;
    if (sign)
    {
        ans = max(a[idx] + solve(idx + 1, 1), -a[idx] + solve(idx + 1, 0));
    }
    else
    {
        ans = max(-a[idx] + solve(idx + 1, 1), a[idx] + solve(idx + 1, 0));
    }
    dp[idx][sign] = ans;

    //cout << "idx " << idx << " " << sign << " " << dp[idx][sign] << endl;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 2)
    {
        cout << max(a[0] + a[1], -a[0] - a[1]) << endl;
        return 0;
    }
    dp = {};
    ll ans = max(-a[0] + solve(1, 0), a[0] + solve(1, 1));
    cout << ans << endl;
    return 0;
}