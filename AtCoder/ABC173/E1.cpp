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
    sort(a.begin(), a.end());
    ll ans = 1, sign = 1;
    int l = 0, r = n - 1;
    if (k & 1)
    {
        ans = a[r--];
        --k;
        if (ans < 0) sign = -1;
    }
    while (k)
    {
        ll x = a[l] * a[l + 1], y = a[r] * a[r - 1];
        if (x * sign > y * sign)
        {
            ans = x % mod * ans % mod;
            l += 2;
        }
        else
        {
            ans = y % mod * ans % mod;
            r -= 2;
        }
        k -= 2;
    }
    cout << (ans + mod) % mod << endl;
    return 0;
}