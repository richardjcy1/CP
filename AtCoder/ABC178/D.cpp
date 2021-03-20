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
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 3; j <= i; j++)
        {
            if (i == j || i - j >= 3)
            {
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n] << endl;

    return 0;
}