#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, x;
    cin >> n >> m >> x;
    vector<ll> c(n);
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    ll ans = LLONG_MAX;
    for (int mask = 1; mask < 1 << n; mask++)
    {
        vector<ll> skill(m);
        ll tot = 0;
        for (int j = 0; j < n; j++)
        {
            if (mask >> j & 1)
            {
                tot += c[j];
                for (int k = 0; k < m; k++) skill[k] += a[j][k];
            }
        }
        bool ok = true;
        for (int i = 0; i < m; i++)
        {
            if (skill[i] < x)
            {
                ok = false;
                break;
            }
        }
        if (ok) ans = min(ans, tot);
    }
    if (ans == LLONG_MAX) ans = -1;
    cout << ans << endl;
    return 0;
}