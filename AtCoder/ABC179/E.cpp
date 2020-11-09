#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, x, m;
    cin >> n >> x >> m;
    ll cnt = n;
    vector<int> a;
    vector<bool> vis(m);
    while (cnt--)
    {
        x %= m;
        if (vis[x]) break;
        vis[x] = true;
        a.push_back(x);
        x *= x;
        x %= m;
    }
    ll sum = accumulate(a.begin(), a.end(), (ll)0);
    if (n <= a.size())
    {
        cout << sum << endl;
        return 0;
    }
    int idx = 0;
    int sz = a.size();
    for (; idx < sz && a[idx] != x; idx++);
    int l = sz - idx;
    ll r = (n - idx) % l;
    ll sum2 = accumulate(a.begin() + idx, a.begin() + idx + r, (ll)0);
    ll sum3 = accumulate(a.begin() + idx, a.end(), (ll)0);
    ll sum4 = accumulate(a.begin(), a.begin() + idx, (ll)0);
    ll ans = sum3 * ((n - idx) / l) + sum2 + sum4;
    cout << ans << endl;
    return 0;
}