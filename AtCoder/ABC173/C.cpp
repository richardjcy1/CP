#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int check(vector<string>& v, int mask, vector<int>& row, vector<int>& col)
{
    int h = v.size(), w = v[0].size();
    vector<int> r, c;
    for (int i = 0; i < h; i++)
    {
        if (mask & (1 << i)) r.push_back(i);
    }
    for (int i = 0; i < w; i++)
    {
        if (mask & (1 << (i + h))) c.push_back(i);
    }
    int ans = 0;
    for (int i: r) ans += row[i];
    for (int i: c) ans += col[i];
    for (int i: r)
    {
        for (int j: c)
        {
            if (v[i][j] == '#') --ans;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, k;
    cin >> h >> w >> k;
    ll ans = 0;
    vector<string> v(h);
    for (int i = 0; i < h; i++) cin >> v[i];
    vector<int> row(h), col(w);
    int tot = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (v[i][j] == '#') 
            {
                row[i]++;
                col[j]++;
                ++tot;
            }
        }
    }
    for (int mask = 0; mask < (1 << (h + w)); mask++)
    {
        if (check(v, mask, row, col) == tot - k) ++ans;
    }
    cout << ans << endl;

    return 0;
}