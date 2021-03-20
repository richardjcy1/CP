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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        ll sum = accumulate(a.begin(), a.end(), (ll)0);
        if (sum & 1)
        {
            cout << "NO" << endl;
            continue;
        }
        ll target = sum / 2;
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < target; j++)
            {
                if (j + a[i] <= target)
                {
                    dp[j + a[i]] = dp[j + a[i]] || dp[j];
                }
            }
        }
        if (dp[target]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}