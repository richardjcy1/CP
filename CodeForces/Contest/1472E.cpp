#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> h(n), w(n);
        for (int i = 0; i < n; i++) cin >> h[i] >> w[i];
        vector<tuple<ll, ll, ll>> a, b;
        for (int i = 0; i < n; i++)
        {
            a.push_back(make_tuple(min(h[i], w[i]), max(h[i], w[i]), i));
            b.push_back(make_tuple(max(h[i], w[i]), min(h[i], w[i]), i));
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<ll> ans(n, -1);
        for (int i = 1; i < n; i++)
        {
            int idx = get<2>(a[i]);
            if (ans[idx] == -1)
            {
                if (get<0>(a[i]) > get<0>(a[0]) && get<1>(a[i]) > get<1>(a[0]))
                {
                    ans[idx] = get<2>(a[0]);
                }
            }
            
        }
        for (int i = 1; i < n; i++)
        {
            int idx = get<2>(b[i]);
            if (ans[idx] == -1)
            {
                if (get<0>(b[i]) > get<0>(b[0]) && get<1>(b[i]) > get<1>(b[0]))
                {
                    ans[idx] = get<2>(b[0]);
                }
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (ans[i] == -1) cout << -1 << " ";
            else cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}