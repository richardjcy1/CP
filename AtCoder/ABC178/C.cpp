#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll solve(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans *= a;
            ans %= mod;
        }
        n /= 2;
        a *= a;
        a %= mod;
    }
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll ans1 = solve(10, n);
    ll ans2 = solve(9, n);
    ll ans3 = solve(8, n);
    ll ans = (ans1 + mod + mod - ans2 * 2 + mod + ans3) % mod;
    cout << ans << endl;

    return 0;
}