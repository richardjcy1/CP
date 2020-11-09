#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    vector<ll> w(m);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < m; i++) cin >> w[i];
    if (n == 1)
    {
        ll ans = LLONG_MAX;
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, abs(w[i] - h[0]));
        }
        cout << ans << endl;
        return 0;
    }
    sort(h.begin(), h.end());
    vector<ll> pre(n);
    vector<ll> suf(n);
    pre[1] = h[1] - h[0];
    for (int i = 3; i < n; i += 2) pre[i] = pre[i - 2] + h[i] - h[i - 1];
    suf[n - 2] = h[n - 1] - h[n - 2];
    for (int i = n - 4; ~i; i -= 2) suf[i] = suf[i + 2] + h[i + 1] - h[i];
    ll ans = LLONG_MAX;
    for (int i = 0; i < m; i++)
    {
        auto it = lower_bound(h.begin(), h.end(), w[i]);
        int idx = distance(h.begin(), it);
        if (idx & 1)
        {
            ll tmp = w[i] - h[idx - 1];
            if (idx - 2 >= 1) tmp += pre[idx - 2];
            if (idx < n - 1) tmp += suf[idx];
            ans = min(ans, tmp);
        }
        else
        {
            ll tmp = h[idx] - w[i];
            if (idx - 1 >= 1) tmp += pre[idx - 1];
            if (idx + 1 < n - 1) tmp += suf[idx + 1];
            ans = min(ans, tmp);
        }

        //cout << w[i] << " " << idx << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}