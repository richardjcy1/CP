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
    vector<int> a(n + 1);
    vector<int> b(n);
    for (int i = 0; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int diff = b[i] >= a[i] ? a[i] : b[i];
        ans += diff;
        b[i] -= diff;
        a[i] -= diff;
        int diff2 = b[i] >= a[i + 1] ? a[i + 1] : b[i];
        ans += diff2;
        b[i] -= diff2;
        a[i + 1] -= diff2;
    }
    cout << ans << endl;
    return 0;
}