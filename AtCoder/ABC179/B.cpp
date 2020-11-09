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
    for (int i = 0; i + 2 < n; i++)
    {
        if (v[i].first == v[i].second && v[i + 1].first == v[i + 1].second && v[i + 2].first == v[i + 2].second) ok = true;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}