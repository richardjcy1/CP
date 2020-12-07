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
    ll x = 2;
    for (ll i = 3; i <= n; i++)
    {
        ll y = __gcd(x, i);
        x = x * i / y;
    }
    cout << x + 1 << endl;
    return 0;
}