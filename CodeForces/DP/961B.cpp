#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    vector<ll> left(n), right(n);
    left[0] = 0; right[n - 1] = 0;
    ll cur = a[0] * t[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = cur;
        cur += a[i] * t[i];
    }
    cur = a[n - 1] * t[n - 1];
    for (int i = n - 2; ~i; i--)
    {
        right[i] = cur;
        cur += a[i] * t[i];
    }
    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i + k <= n; i++)
    {
        ll tmp = 0;
        if (i) tmp += left[i];
        if (i + k - 1 < n) tmp += right[i + k - 1];
        tmp += (sum[i + k] - sum[i]);
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}