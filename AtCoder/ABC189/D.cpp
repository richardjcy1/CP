#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

vector<int> s;
int n;
ll dp[65][2];

ll solve(int pos, int prev)
{
    if (pos == n + 1) return prev == 1;
    if (dp[pos][prev] != -1) return dp[pos][prev];
    ll ans = 0;
    if (s[pos])
    {
        ans += solve(pos + 1, prev || false);
        ans += solve(pos + 1, prev || true);
    }
    else
    {
        ans += solve(pos + 1, prev && false);
        ans += solve(pos + 1, prev && true);
    }
    return dp[pos][prev] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    s = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        if (str[0] == 'A') s[i] = 0;
        else s[i] = 1;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(1, 0) + solve(1, 1) << endl;
    return 0;
}