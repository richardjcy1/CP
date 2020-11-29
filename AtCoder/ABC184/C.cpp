#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1 == r2 && c1 == c2) cout << 0 << endl;
    else if (r1 - c1 == r2 - c2) cout << 1 << endl;
    else if (r1 + c1 == r2 + c2) cout << 1 << endl;
    else if (((r1 - c1) - (r2 - c2)) % 2 == 0) cout << 2 << endl;
    else if (((r2 + c2) - (r1 + c1)) % 2 == 0) cout << 2 << endl;
    else cout << 3 << endl;
    return 0;
}