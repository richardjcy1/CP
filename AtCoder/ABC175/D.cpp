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
    vector<ll> p(n), c(n);
    for (ll i = 0; i < n; i++) 
    {
        cin >> p[i];
        p[i]--;
    }
    for (ll i = 0; i < n; i++) cin >> c[i];
    vector<vector<ll>> v(n, vector<ll>());
    for (ll i = 0; i < n; i++)
    {
        vector<bool> vis(n);
        ll j = p[i];
        while (!vis[j])
        {
            v[i].push_back(j);
            vis[j] = true;
            j = p[j];
        }
    }
    ll ans = LLONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        ll sz = v[i].size();
        ll tot = 0;
        if (k > sz)
        {
            ll sum = 0;
            for (ll j = 0; j < sz; j++) sum += c[v[i][j]];
            ll ma = c[v[i][0]];
            ll idx = 0;
            ll idx2 = 0;
            ll presum = c[v[i][0]];
            ll ma2 = c[v[i][0]];
            for (ll j = 1; j < sz; j++)
            {
                presum += c[v[i][j]];
                if (presum > ma)
                {
                    idx = j;
                    ma = presum;
                }
                if (presum > ma2 && j < k % sz)
                {
                    idx2 = j;
                    ma2 = presum;
                }
            }
            if (sum >= 0)
            {
                if (idx >= k % sz) tot = sum * ((k - 1) / sz) + max((ll)0, ma2);
                else tot = sum * (k / sz) + max((ll)0, ma);
            }
            else
            {
                if (idx >= k % sz) tot = ma2;
                else tot = ma;
            }
            //if (tot > ans) cout << i << " " << tot << " " << "idx " << idx << " idx2 " << idx2 << " " << " sum " << sum << endl;
            ans = max(ans, tot);
        }
        else
        {
            ll sum = c[v[i][0]];
            ll ma = c[v[i][0]];
            for (ll j = 1; j < k; j++)
            {
                sum += c[v[i][j]];
                if (sum > ma) ma = sum;
            }
            ans = max(ans, ma);
        }
    }
    cout << ans << endl;
    return 0;
}