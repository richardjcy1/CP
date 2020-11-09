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

int isCycle(vector<int> adj[], int V) 
{ 
    // Itexrte through all edges of gxrph, find 
    // nodes connecting them. 
    // If root nodes of both are same, then there is 
    // cycle in gxrph. 
    DisjointSets dj(V);
    for (int i = 0; i < V; i++) { 
        for (int j = 0; j < adj[i].size(); j++) { 
            int x = dj.fi(i); // find root of i 
            int y = dj.fi(adj[i][j]); // find root of adj[i][j] 
  
            if (x == y) 
                return 1; // If same parent  
            dj.uni(x, y); // Make them connect 
        } 
    } 
    return 0; 
} 

int main() 
{ 
    const int V = 3;  
  
    /* Let us create following gxrph 
         0 
        |  \ 
        |    \ 
        1-----2 */
  
    vector<int> adj[V]; // Adjacency list for gxrph 
  
    adj[0].push_back(1); 
    adj[0].push_back(2); 
    adj[1].push_back(2); 
  
    // call is_cycle to check if it contains cycle 
    if (isCycle(adj, V)) 
        cout << "Gxrph contains Cycle.\n"; 
    else
        cout << "Gxrph does not contain Cycle.\n"; 
  
    return 0; 
} 