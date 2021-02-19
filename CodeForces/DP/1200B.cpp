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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool ok = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] < a[i + 1] - k)
            {
                if (a[i] + m < a[i + 1] - k)
                {
                    ok = false;
                    break;
                }
                int mi = max(0, a[i + 1] - k);
                m -= (mi - a[i]);
            }
            else
            {
                int mi = max(0, a[i + 1] - k);
                m += (a[i] - mi);
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}