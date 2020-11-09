/*
*	author:		richardjcy
*	created:	2020/09/26/08:40.30
*/

#include <bits/stdc++.h>
using namespace std;

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
    DisjointSets dj(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        int u = dj.fi(x);
        int v = dj.fi(y);
        if (u != v)
        {
            dj.uni(u, v);
        }
    }
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(dj.fi(i));
    }
    cout << (int)st.size() << endl;
    return 0;
}