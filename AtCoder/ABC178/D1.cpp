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
    vector<int> dp(n + 1);
    dp[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 3; j < i; j++)
        {
            if (i - j >= 3) 
            {
                dp[i] += dp[j];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}