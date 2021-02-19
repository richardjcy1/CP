#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

vector<int> ball;
vector<pair<int, int>> v;
vector<pair<int, int>> u;
int n, m, k;
int ans = 0;

void solve(int pos)
{
    if (pos == k)
    {
        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            if (ball[v[i].first] && ball[v[i].second]) ++ret;
        }
        ans = max(ans, ret);
        return;
    }
    ball[u[pos].first]++;
    solve(pos + 1);
    ball[u[pos].first]--;
    ball[u[pos].second]++;
    solve(pos + 1);
    ball[u[pos].second]--;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    v = {};
    u = {};
    ball = vector<int>(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        --x; --y;
        v.push_back(make_pair(x, y));
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        --x; --y;
        u.push_back(make_pair(x, y));
    }
    solve(0);
    cout << ans << endl;
    return 0;
}