#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> left(n), right(n);
    ll sum = a[0];
    for (ll i = 1; i < n; i++)
    {
        left[i] = sum;
        sum += a[i];
    }
    sum = a[n - 1];
    for (ll i = n - 2; ~i; i--)
    {
        right[i] = sum;
        sum += a[i];
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans = (ans + i * a[i] - left[i] + right[i] - (n - i - 1) * a[i]);
    }
    cout << ans / 2 << endl;
    return 0;
}