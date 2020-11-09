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


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        DisjointSets dj(n + 1);
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[i - 1] != a[j - 1] && dj.fi(i) != dj.fi(j))
                {
                    ans.push_back(make_pair(i, j));
                    dj.uni(i, j);
                }
            }
        }
        int m = ans.size();
        if (m != n - 1) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (auto p: ans)
            {
                cout << p.first << " " << p.second << endl;
            }
        }
    }
    return 0;
}