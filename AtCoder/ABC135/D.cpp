#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

string s;
int n;
ll dp[100005][14];

ll solve(int idx, ll x)
{
    if (idx == n) 
    {
        return x == 5;
    }
    if (dp[idx][x] != -1) return dp[idx][x];
    ll ans = 0;
    if (s[idx] >= '0' && s[idx] <= '9')
    {
        ans += solve(idx + 1, (x * 10 + (s[idx] - '0')) % 13);
        ans %= mod;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            ans += solve(idx + 1, (x * 10 + i) % 13);
            ans %= mod;
        }
    }
    return dp[idx][x] = ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof dp);
    ll ans = solve(0, 0);
    cout << ans << endl;
    return 0;
}