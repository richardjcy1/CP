#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = abs(x2 - x1) + abs(y2 - y1);
        if (x1 != x2 && y1 != y2) ans += 2;
        cout << ans << endl;
    }
    return 0;
}