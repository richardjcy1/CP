#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    pair<int, int> a = {v[0].first, v[0].second};
    bool ok = true;
    for (int i = 1; i < m; i++)
    {
        if (v[i].first > a.second)
        {
            ok = false;
            break;
        }
        else
        {
            a.first = max(a.first, v[i].first);
            a.second = min(a.second, v[i].second);
        }
    }
    if (!ok) cout << 0 << endl;
    else cout << a.second - a.first + 1 << endl;

    return 0;
}