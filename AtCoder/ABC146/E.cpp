#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        --a[i];
        a[i] %= k;
    }
    ll sum = 0;
    unordered_map<ll, vector<ll>> mp;
    mp[0].push_back(-1);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += a[i];
        sum %= k;
        if (mp.find(sum) != mp.end())
        {
            auto it = upper_bound(mp[sum].begin(), mp[sum].end(), i - k);
            ll d = distance(it, mp[sum].end());
            ans += d;
        }
        mp[sum].push_back(i);
    }
    cout << ans << endl;
    return 0;
}