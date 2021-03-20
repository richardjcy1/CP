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
    unordered_map<string, unordered_set<string>> g;
    for (int i = 0; i < n; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        for (char& ch: a) ch = tolower(ch);
        for (char& ch: c) ch = tolower(ch);
        g[c].insert(a);
    }
    int ans = 0;
    queue<pair<string, int>> q;
    q.push(make_pair("polycarp", 1));
    while (!q.empty())
    {
        auto tmp = q.front(); q.pop();
        ans = max(ans, tmp.second);
        for (auto nei: g[tmp.first])
        {
            q.push(make_pair(nei, tmp.second + 1));
        }
    }
    cout << ans << endl;
    return 0;
}