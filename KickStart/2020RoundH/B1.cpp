#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
Boring numbers (Digit DP)

key observation: 
within a range find counts of satisfied numbers

dfs(pos, lead, even, limit): start at pos, whether it is first digit, current should be even/odd, at limit

we can have several leading zeroes before actual non-zero digit occurs. so we need to use lead to mark.

*/

string s;
int n;
ll dp[20][2][2][2];

ll dfs(int pos, bool lead, bool even, bool limit)
{
    if (pos == n) return 1;
    if (dp[pos][lead ? 1 : 0][even ? 1 : 0][limit ? 1 : 0] != -1) return dp[pos][lead ? 1 : 0][even ? 1 : 0][limit ? 1 : 0];
    ll ans = 0;
    int up = limit ? s[pos] - '0' : 9;
    for (int i = 0; i <= up; i++)
    {
        if (lead)
        {
            if (!i) ans += dfs(pos + 1, true, true, limit && i == (s[pos] - '0'));
            else if (i & 1)
            {
                ans += dfs(pos + 1, false, !even, limit && i == (s[pos] - '0'));
            }
        }
        else
        {
            if (even && i & 1)
            {
                ans += dfs(pos + 1, false, !even, limit && i == (s[pos] - '0'));
            }
            else if (!even && i % 2 == 0)
            {
                ans += dfs(pos + 1, false, !even, limit && i == (s[pos] - '0'));
            }
        }
    }
    return dp[pos][lead ? 1 : 0][even ? 1 : 0][limit ? 1 : 0] = ans;
}

ll solve(ll N)
{
    s = to_string(N);
    n = s.size();
    memset(dp, -1, sizeof dp);
    return dfs(0, true, true, true);
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
        ll L, R;
        cin >> L >> R;
        ll ans1 = solve(R);
        ll ans2 = solve(L - 1);
        cout << "Case #" << ++kase << ": " << ans1 - ans2 << endl;
    }
    return 0;
}