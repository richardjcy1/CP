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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> pre(n), suf(n);
    pre[0] = a[0]; suf[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        pre[i] = __gcd(pre[i - 1], a[i]);
    }
    for (int i = n - 2; ~i; i--)
    {
        suf[i] = __gcd(suf[i + 1], a[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0) ans = max(ans, suf[1]);
        else if (i == n - 1) ans = max(ans, pre[n - 2]);
        else
        {
            ans = max(ans, __gcd(pre[i - 1], suf[i + 1]));
        }
    }
    cout << ans << endl;
    return 0;
}