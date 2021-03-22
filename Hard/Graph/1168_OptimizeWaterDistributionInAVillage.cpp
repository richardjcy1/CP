#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Graph
{
    int V;
    vector< pair<int, pair<int, int> > > edges;

    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    ll kruskalMST();
};

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

ll Graph::kruskalMST()
{
    ll mst_wt = 0, need = V - 1;
    sort(edges.begin(), edges.end());
    DisjointSets ds(V);

    vector< pair<int, pair<int, int> > >::iterator it;
    for (it = edges.begin(); it != edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.fi(u);
        int set_v = ds.fi(v);

        if (set_u != set_v)
        {
            // cout << u << " - " << v << endl;
            mst_wt += it->first;
            ds.uni(set_u, set_v);
            --need;
        }
        if (!need) break;
    }

    return mst_wt;
}

class Solution {
public:
    int minCostToSupplyWater(int N, vector<int>& wells, vector<vector<int>>& pipes) {
        int n = wells.size(), m = pipes.size();
        Graph g(n + 1);
        for (int i = 0; i < n; i++)
        {
            g.addEdge(0, i + 1, wells[i]);
        }
        for (int i = 0; i < m; i++)
        {
            g.addEdge(pipes[i][0], pipes[i][1], pipes[i][2]);
        }
        return g.kruskalMST();
    }
};