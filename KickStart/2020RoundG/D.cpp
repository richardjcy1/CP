#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 0x3f3f3f3f;
    

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    int kase = 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[i] = x;
        }
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
        dp[2][1] = dp[2][2] = 1.0;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i][j] = (j - 1) * dp[i - 1][j - 1] + (i - j) * dp[i - 1][j];
                if (j == 1 || j == i) dp[i][j] += 1.0;
                else dp[i][j] += 2.0;
                dp[i][j] /= (i - 1 + 0.0);
            }
        }
        double ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += dp[n][i] * a[i - 1];
        }
        cout << setprecision(20) << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}