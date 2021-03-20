#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

struct DisjointSets
{
    vector<int> parent;
    vector<int> rank;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        rank.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int fi(int u)
    {
        if (u != parent[u])
        {
            parent[u] = fi(parent[u]);
        }
        return parent[u];
    }

    void uni(int x, int y)
    {
        x = fi(x), y =fi(y);
        if (rank[x] > rank[y])
        {
            parent[y] = x;
        }
        else parent[x] = y;

        if (rank[x] == rank[y]) ++rank[y];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    DisjointSets dj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dj.uni(a, b);
    }
    int ans = 0;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[dj.fi(i)]++;
    }
    for (auto p: mp)
    {
        ans = max(ans, p.second);
    }
    cout << ans << endl;
    return 0;
}