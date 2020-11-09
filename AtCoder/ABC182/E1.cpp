#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<vector<int>> light(h, vector<int>(w));
    vector<set<int>> row(h, set<int>());
    vector<set<int>> col(w, set<int>());
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        light[a][b] = 1;
        row[a].insert(b);
        col[b].insert(a);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        row[a].insert(b);
        col[b].insert(a);
    }
    ll ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (light[i][j])
            {
                ++ans;
                continue;
            }
            if (row[i].find(j) != row[i].end()) continue;
            bool ok = false;
            auto it_left = row[i].lower_bound(j);
            auto it_right = row[i].upper_bound(j);
            auto it_up = col[j].lower_bound(i);
            auto it_down = col[j].upper_bound(i);
            if (it_left != row[i].begin())
            {
                --it_left;
                if (light[i][*it_left]) ok = true;
            }
            if (it_up != col[j].begin())
            {
                --it_up;
                if (light[*it_up][j]) ok = true;
            }
            if (it_right != row[i].end() && light[i][*it_right]) ok = true;
            if (it_down != col[j].end() && light[*it_down][j]) ok = true;
            if (ok) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}