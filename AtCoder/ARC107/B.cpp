#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for (ll i = 2; i <= n * 2; i++)
    {
        if (i - k >= 2 && i - k <= 2 * n)
        {
            ll left = i <= n + 1 ? i - 1 : 2 * n - i + 1;
            ll right = i - k <= n + 1 ? i - k - 1 : 2 * n - (i - k) + 1;
            ans += left * right;
        }
    }
    cout << ans << endl;
    return 0;
}