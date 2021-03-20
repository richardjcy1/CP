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
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int ans = v[0];
        for (int i = 1; i < n; i++)
        {
            if (v[i] > ans) ans = v[i];
        }
        int idx = -1;
        bool ok = false;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == ans && ((i - 1 >= 0 && v[i] != v[i - 1]) || (i + 1 < n && v[i] != v[i + 1]))) 
            {
                idx = i;
                ok = true;
            }
            if (ok) break;
        }
        if (ok) cout << idx + 1 << endl;
        else cout << -1 << endl;
    }

    return 0;
}