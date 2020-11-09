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
    vector<set<int>> row(h);
    vector<set<int>> col(w);
    for (int i = 0; i < h; i++)
    {
        row[i].insert(-1);
        row[i].insert(w);
    }
    for (int i = 0; i < w; i++)
    {
        col[i].insert(-1);
        col[i].insert(h);
    }
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        light[a].insert(b);
        row[a].insert(b);
        col[b].insert(a);
    }
    for (int i = 0; i < m; i++)
    {
        int c, d;
        cin >> c >> d;
        --c; --d;
        row[c].insert(d);
        col[d].insert(c);
    }
    ll ans = 0;
    ll overlap = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j: light[i])
        {
            cout << i << " " << j << " ";
            auto it = row[i].find(j);
            auto it1 = row[i].lower_bound(j);
            --it1;
            auto it2 = row[i].upper_bound(j);
            int left = (*it) - (*it1) - 1;
            int right = (*it2) - (*it) - 1;
            ans += left + right;
            ans++;
            if (light[i].find(*it1) != light[i].end())
            {
                overlap += left;
            }
            if (light[i].find(*it2) != light[i].end())
            {
                overlap += right;
            }
            cout << "left " << left << " right " << right << " overlap " << overlap << " ";
            
            auto iter = col[j].find(i);
            auto it3 = col[j].lower_bound(i);
            --it3;
            auto it4 = col[j].upper_bound(i);
            int up = (*iter) - (*it3) - 1;
            int down = (*it4) - (*iter) - 1;
            ans += up + down;
            if ((*it3) >= 0 && !light[*it3].empty() && light[*it3].find(j) != light[*it3].end())
            {
                overlap += up;
            }
            if ((*it4) >= 0 && (*it4) < h && !light[*it4].empty() && light[*it4].find(j) != light[*it4].end())
            {
                overlap += down;
            }
            cout << "up " << up << " down " << down << " overlap " << overlap << endl;
        }
    }
    ans -= overlap / 2;
    cout << ans << endl;
    return 0;
}