#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n, k;
vector<vector<ll>> t;
ll ans;
vector<bool> vis;

void solve(int cnt, int idx, ll tot)
{
    if (cnt == n)
    {
        if (tot + t[idx][0] == k) ++ans;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (i && !vis[i]) 
        {
            vis[i] = true;
            solve(cnt + 1, i, tot + t[idx][i]);
            vis[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    t = vector<vector<ll>>(n, vector<ll>(n));
    vis = vector<bool>(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> t[i][j];
        }
    }
    ans = 0;
    solve(1, 0, 0);
    cout << ans << endl;
    return 0;
}