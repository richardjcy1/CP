#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
observation 1:
for each bulb, check nearest other bulb or block -> problem: bulbs on different row and col will have overlapping squares

observation 2:
check for each square, if on the same row/col there is a bulb at the nearest position. if so, this square is lit up; otherwise not
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<vector<int>> light(h, vector<int>(w));
    vector<vector<int>> row(h, vector<int>());
    vector<vector<int>> col(w, vector<int>());
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        light[a][b] = 1;
        row[a].push_back(b);
        col[b].push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        row[a].push_back(b);
        col[b].push_back(a);
    }
    ll ans = 0;
    for (int i = 0; i < h; i++) sort(row[i].begin(), row[i].end());
    for (int i = 0; i < w; i++) sort(col[i].begin(), col[i].end());
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (light[i][j])
            {
                ++ans;
                continue;
            }
            //if (row[i].find(j) != row[i].end()) continue;
            auto it = find(row[i].begin(), row[i].end(), j);
            if (it != row[i].end()) continue;
            bool ok = false;
            auto it_left = lower_bound(row[i].begin(), row[i].end(), j);
            auto it_right = upper_bound(row[i].begin(), row[i].end(), j);
            auto it_up = lower_bound(col[j].begin(), col[j].end(), i);
            auto it_down = upper_bound(col[j].begin(), col[j].end(), i);
            if (it_left != row[i].begin())
            {
                //--it_left;
                if (light[i][*prev(it_left)]) ok = true;
            }
            if (it_up != col[j].begin())
            {
                //--it_up;
                if (light[*prev(it_up)][j]) ok = true;
            }
            if (it_right != row[i].end() && light[i][*it_right]) ok = true;
            if (it_down != col[j].end() && light[*it_down][j]) ok = true;
            if (ok) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}