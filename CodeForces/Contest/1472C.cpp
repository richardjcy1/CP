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
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<ll> dp(n);
        dp[n - 1] = a[n - 1];
        for (int i = n - 2; ~i; i--)
        {
            if (i + a[i] < n) dp[i] = max(dp[i], a[i] + dp[i + a[i]]);
            else dp[i] = max(dp[i], a[i]);
        }
        ll ans = *max_element(dp.begin(), dp.end());
        cout << ans << endl;
    }
    return 0;
}