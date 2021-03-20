#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = a * (a + 1) / 2 % mod;
    ans = ans * b % mod * (b + 1) / 2 % mod;
    ans = ans * c % mod * (c + 1) / 2 % mod;
    cout << ans <<endl;
    return 0;
}