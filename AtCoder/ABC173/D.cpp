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
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0;
    int cnt = 0, i = 0, tot = 0;
    while (tot < n - 1)
    {
        ans += a[i];
        ++cnt;
        if (i == 0)
        {
            ++i;
            cnt = 0;
        }
        else if (cnt == 2)
        {
            ++i;
            cnt = 0;
        }
        ++tot;
    }
    cout << ans << endl;
    return 0;
}