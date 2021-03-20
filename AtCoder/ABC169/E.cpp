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
    vector<ll> a, b;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans;
    if (n & 1)
    {
        ans = b[n / 2] - a[n / 2] + 1;
    }
    else
    {
        ans = (b[n / 2] + b[n / 2 - 1]) - (a[n / 2] + a[n / 2 - 1])+ 1;
    }
    cout << ans << endl;
    return 0;
}