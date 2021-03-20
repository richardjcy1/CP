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
    int kase = 0;
    while (t--)
    {
        ll n, k, s;
        cin >> n >> k >> s;
        ll ans1 = k - 1 + 1 + n;
        ll ans2 = k - 1 + k - s + n - s + 1;
        ll ans = min(ans1, ans2);
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}