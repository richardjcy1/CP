#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;
    if (a == b) cout << 0 << endl;
    else
    {
        if ((a + b) & 1) cout << "IMPOSSIBLE" << endl;
        else cout << (a + b) / 2 << endl;
    }
    return 0;
}