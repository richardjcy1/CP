#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int V;
    list<int>* adj;
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v);
    void DFSUtil(int u, bool visited[]);
    bool SCC();
    Graph getTranspose();
};

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::DFSUtil(int u, bool visited[])
{
    visited[u] = true;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        if (!visited[*i])
        {
            DFSUtil(*i, visited);
        }
    }
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int i = 0; i < V; i++)
    {
        list<int>::iterator j;
        for (j = adj[i].begin(); j != adj[i].end(); j++)
        {
            g.adj[*j].push_back(i);
        }
    }
    return g;
}

bool Graph::SCC()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    DFSUtil(0, visited);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) return false;
    }
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    Graph g = getTranspose();
    g.DFSUtil(0, visited);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) return false;
    }
    return true;
}

int main() 
{ 
    // Create graphs given in the above diagrams 
    Graph g1(5); 
    g1.addEdge(0, 1); 
    g1.addEdge(1, 2); 
    g1.addEdge(2, 3); 
    g1.addEdge(3, 0); 
    g1.addEdge(2, 4); 
    g1.addEdge(4, 2); 
    g1.SCC()? cout << "Yes\n" : cout << "No\n"; 
  
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.SCC()? cout << "Yes\n" : cout << "No\n"; 
  
    return 0; 
} 