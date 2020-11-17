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
    string s;
    cin >> s;
    vector<int> r, g;
    unordered_set<int> b;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R') r.push_back(i);
        else if (s[i] == 'G') g.push_back(i);
        else b.insert(i);
    }
    int u = r.size(), v = g.size();
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < v; j++)
        {
            ans += b.size();
            if (r[i] < g[j])
            {
                if (b.find(2 * r[i] - g[j]) != b.end()) --ans;
                if (b.find(2 * g[j] - r[i]) != b.end()) --ans;
                if ((r[i] + g[j]) % 2 == 0 && b.find((r[i] + g[j]) / 2) != b.end()) --ans;
            }
            else
            {
                if (b.find(2 * g[j] - r[i]) != b.end()) --ans;
                if (b.find(2 * r[i] - g[j]) != b.end()) --ans;
                if ((r[i] + g[j]) % 2 == 0 && b.find((r[i] + g[j]) / 2) != b.end()) --ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}