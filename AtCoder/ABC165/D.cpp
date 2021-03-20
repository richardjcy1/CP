#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, n;
    cin >> a >> b >> n;
    if (n < b - 1) cout << (ll)(a * n / b) << endl;
    else cout << (ll)(a * (b - 1) / b) << endl;
    return 0;
}