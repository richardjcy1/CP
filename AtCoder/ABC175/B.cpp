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
    ll ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i] + a[j] > a[k] && a[j] + a[k] > a[i] && a[k] + a[i] > a[j] && a[i] != a[j] && a[j] != a[k] && a[k] != a[i]) ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}