#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<int> dp(n + 2);
        int ans = 0;
        for (int i = n - 1; i; i--)
        {
            for (int j = 1; j <= a[i]; j++)
            {
                if (i + j < n) dp[i] += dp[i + j];
                else dp[i]++;
            }
            if (dp[i] > 1)
            {
                int cnt = 0;
                dp[i] = 1;
                for (int j = 1; j <= a[i]; j++)
                {
                    if (dp[i + j] && (dp[i + j + 1] == 0 || j == a[i]))
                    {
                        dp[i + j] = 0;
                        ++cnt;
                    }
                }
                ans += cnt;
            }
        }
        cout << ans << endl;
    }
    return 0;
}