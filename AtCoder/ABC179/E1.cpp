#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
find the recurring loop
[a0,a1,... ai, ... aj,ai...aj...ai,...ak]
first part: no loop
second part: loop
third part: remaining
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> v;
    vector<ll> vis(m);
    x %= m;
    while (!vis[x])
    {
        vis[x] = true;
        v.push_back(x % m);
        x *= x;
        x %= m;
    }
    ll sz = v.size();
    int i;
    for (i = 0; i < sz; i++)
    {
        if (v[i] == x) break;
    }
    ll sum1 = accumulate(v.begin(), v.begin() + i, (ll)0);
    ll sum2 = accumulate(v.begin() + i, v.end(), (ll)0);
    ll ans;
    if (n <= i)
    {
        ans = accumulate(v.begin(), v.begin() + n, (ll)0);
    }
    else
    {
        ans = sum1 + (n - i) / (sz - i) * sum2 + accumulate(v.begin() + i, v.begin() + i + (n - i) % (sz - i), (ll)0);
    }
    cout << ans << endl;
    return 0;
}