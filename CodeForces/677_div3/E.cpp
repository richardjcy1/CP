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
    vector<ll> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = i * fac[i - 1];
    int h = n / 2;
    ll ans = fac[n - 1] / (fac[h - 1] * fac[h]) * fac[h - 1] * fac[h - 1];
    cout << ans << endl;
    
    return 0;
}