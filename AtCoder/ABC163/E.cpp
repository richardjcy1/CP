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
    int left = 0, right = n - 1;
    ll ans = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
    {
        ll idx = -1, ma = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j])
            {
                ll tmp = max((j - left) * a[j], (right - j) * a[j]);
                if (tmp > ma)
                {
                    idx = j;
                    ma = tmp;
                }
            }
        }
        vis[idx] = true;
        ans += ma;
        if (ma == (idx - left) * a[idx]) ++left;
        else --right;
    }
    cout << ans << endl;
    return 0;
}

