#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    double ans = (abs(sy) * gx + abs(gy) * sx) / (abs(sy) + abs(gy) + 0.0);
    cout << setprecision(18) << ans << endl; 
    return 0;
}