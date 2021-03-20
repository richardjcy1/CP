#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, t;
    cin >> n >> x >> t;
    if (n % x == 0) cout << n / x * t << endl;
    else cout << (n / x + 1) * t << endl;

    return 0;
}