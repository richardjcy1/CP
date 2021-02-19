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
    vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>());
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int x, y;
            cin >> x >> y;
            --x;
            v[i].push_back(make_pair(x, y));
        }
    }
    int ans = 0;
    for (int mask = (1 << n) - 1; ~mask; mask--)
    {
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (mask & 1 << i)
            {
                for (auto& p: v[i])
                {
                    if (p.second && !(mask & 1 << p.first)) ok = false;
                    if (!p.second && (mask & 1 << p.first)) ok = false;
                }
            }
            if (!ok) break;
        }
        if (ok)
        {
            ans = max(ans, __builtin_popcount(mask));
        }
    }
    cout << ans << endl;
    return 0;
}