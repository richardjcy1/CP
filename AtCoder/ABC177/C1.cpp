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
    ll ans = 0;
    vector<ll> suf(n);
    suf[n - 1] = 0;
    for (int i = n - 2; ~i; i--) 
    {
        suf[i] = suf[i + 1] + a[i + 1];
        suf[i] %= mod;
    }
    for (int i = 0; i < n - 1; i++)
    {
        ans += suf[i] % mod * a[i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}