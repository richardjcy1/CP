#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
Same logic but use O(1) space
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll ans = 0;
    ll n;
    cin >> n;
    ll sum = 0, mx = 0, p = 0;
    while (n--)
    {
        ll m;
        cin >> m;
        sum += m;
        mx = max(mx, sum);
        ans = max(p + mx, ans);
        p += sum;
    }
    ans = max(ans, p);
    cout << ans << endl;
    return 0;
}