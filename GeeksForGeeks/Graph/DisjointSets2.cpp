#include <bits/stdc++.h>
using namespace std;

struct DisjointSets
{
    vector<int> parent;
    vector<int> size;
    int n;
    int setCount;

    DisjointSets(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int fi(int u)
    {
        if (u != parent[u])
        {
            parent[u] = fi(parent[u]);
        }
        return parent[u];
    }

    bool uni(int x, int y)
    {
        x = fi(x), y =fi(y);
        if (x == y) return false;
        if (size[x] < size[y])
        {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }
    
    bool connected(int x, int y)
    {
        x = fi(x);
        y = fi(y);
        return x == y;
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