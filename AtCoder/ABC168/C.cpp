#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double PI = 3.14159265358979323846;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double minute = 6 * m;
    double hour = 30.0 * h + 0.5 * m;
    double angle = abs(minute - hour) / 180.0 * PI;
    double ans = sqrt(a * a + b * b - 2 * a * b * cos(angle));
    cout << setprecision(18) << ans << endl;
    return 0;
}