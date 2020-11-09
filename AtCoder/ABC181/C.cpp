#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((v[j].second - v[i].second) * (v[k].first - v[i].first) == (v[k].second - v[i].second) * (v[j].first - v[i].first)) 
                    ok = true;
            }
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}