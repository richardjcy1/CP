#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll first = i;
        ll last = n / i * i;
        ans += (first + last) * ((last - first) / i + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}