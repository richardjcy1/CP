#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int V, E;
    vector< pair<int, pair<int, int> > > edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST();
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

int Graph::kruskalMST()
{
    int mst_wt = 0, need = V - 1;
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

int main() 
{ 
    /* Let us create above shown weighted 
       and unidrected graph */
    int V = 9, E = 14; 
    Graph g(V, E); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    cout << "Edges of MST are \n"; 
    int mst_wt = g.kruskalMST(); 
  
    cout << "\nWeight of MST is " << mst_wt; 
  
    return 0; 
}