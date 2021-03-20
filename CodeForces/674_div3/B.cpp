#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            v.push_back({a, b, c, d});
        }
        if (m & 1)
        {
            cout << "NO" << endl;
            continue;
        }

        bool ok = false;
        for (auto x: v)
        {
            if (x[1] == x[2])
            {
                ok = true;
                break;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
