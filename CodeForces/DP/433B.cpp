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
    int m;
    cin >> m;
    vector<ll> b = a;
    sort(b.begin(), b.end());
    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
    vector<ll> sum2(n + 1);
    for (int i = 1; i <= n; i++) sum2[i] = sum2[i - 1] + b[i - 1];
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            cout << sum[z] - sum[y - 1] << endl;
        }
        else
        {
            cout << sum2[z] - sum2[y - 1] << endl;
        }
    }
    return 0;
}