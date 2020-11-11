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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    unordered_map<ll, ll> mp;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i - a[i]) != mp.end()) ans += mp[i - a[i]];
        mp[i + a[i]]++;
    }
    cout << ans << endl;
    return 0;
}