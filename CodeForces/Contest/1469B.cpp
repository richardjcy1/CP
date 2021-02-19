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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];
        vector<int> suma(n + 1);
        for (int i = 1; i <= n; i++) suma[i] = suma[i - 1] + a[i - 1];
        vector<int> sumb(m + 1);
        for (int i = 1; i <= m; i++) sumb[i] = sumb[i - 1] + b[i - 1];
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                ans = max(ans, suma[i] + sumb[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}