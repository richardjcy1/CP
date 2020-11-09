#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, m;
    cin >> h >> w >> m;
    vector<int> row(h);
    vector<int> col(w);
    map<int, unordered_set<int>> mp;
    for (int i = 0; i < m; i++)
    {
        int r, c;
        cin >> r >> c;
        --r; --c;
        mp[r].insert(c);
        row[r]++;
        col[c]++;
    }
    int maxrow = row[0], maxcol = col[0];
    for (int i = 1; i < h; i++) maxrow = max(maxrow, row[i]);
    for (int i = 1; i < w; i++) maxcol = max(maxcol, col[i]);
    vector<int> a, b;
    for (int i = 0; i < h; i++)
    {
        if (row[i] == maxrow) a.push_back(i);
    }
    for (int i = 0; i < w; i++)
    {
        if (col[i] == maxcol) b.push_back(i);
    }
    for (int i: a)
    {
        for (int j: b)
        {
            if (mp[i].find(j) == mp[i].end()) 
            {
                cout << maxrow + maxcol << endl;
                return 0;
            }
        }
    }
    cout << maxrow + maxcol - 1 << endl;
    return 0;
}