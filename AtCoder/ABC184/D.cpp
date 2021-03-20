#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

double dp[105][105][105];

double solve(int x, int y, int z)
{
    if (x >= 100 || y >= 100 || z >= 100) 
        return 0.0;
    if (dp[x][y][z] > 0.0) return dp[x][y][z];
    double ans = 0.0;
    ans += (1 + solve(x + 1, y, z)) * x / (x + y + z + 0.0);
    ans += (1 + solve(x, y + 1, z)) * y / (x + y + z + 0.0);
    ans += (1 + solve(x, y, z + 1)) * z / (x + y + z + 0.0);
    //cout << x << " " << y << " " << z << " " << ans << endl;
    return dp[x][y][z] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    memset(dp, -1.0, sizeof dp);
    double ans = solve(a, b, c);
    cout << setprecision(18) << ans << endl;
    return 0;
}