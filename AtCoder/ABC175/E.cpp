#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int maxn = 3005;
int m, n, k;
ll a[maxn][maxn];
ll dp[maxn][maxn][4];

ll solve(int x, int y, int cnt)
{
    if (x == m - 1 && y == n - 1)
    {
        if (a[x][y] && cnt < 3) return a[x][y];
        return 0;
    }
    if (dp[x][y][cnt] != -1) return dp[x][y][cnt];
    ll ans = 0;
    if (a[x][y])
    {
        if (cnt < 3)
        {
            if (y + 1 < n) ans = max(ans, a[x][y] + solve(x, y + 1, cnt + 1));
            if (x + 1 < m) ans = max(ans, a[x][y] + solve(x + 1, y, 0));
        }
        if (y + 1 < n) ans = max(ans, solve(x, y + 1, cnt));
        if (x + 1 < m) ans = max(ans, solve(x + 1, y, 0));
    }
    else
    {
        if (y + 1 < n) ans = max(ans, solve(x, y + 1, cnt));
        if (x + 1 < m) ans = max(ans, solve(x + 1, y, 0));
    }
    return dp[x][y][cnt] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> k;
    memset(dp, -1, sizeof dp);
    memset(a, 0, sizeof a);
    for (int i = 0; i < k; i++)
    {
        int r, c;
        ll v;
        cin >> r >> c >> v;
        --r; --c;
        a[r][c] = v;
    }
    cout << solve(0, 0, 0) << endl;

    return 0;
}