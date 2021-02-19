#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e3 + 5;

ll c[maxn][maxn];
int k;

void Comb()
{
    memset(c, 0, sizeof c);
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= mod;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> k;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i++) cin >> a[i];
    vector<ll> dp(k + 1);
    dp[1] = 1;
    ll sum = a[1];
    Comb();
    for (int i = 2; i <= k; i++)
    {
        sum += a[i];
        dp[i] = dp[i - 1] * c[sum - 1][a[i] - 1];
        dp[i] %= mod;
    }
    cout << dp[k] << endl;
    return 0;
}