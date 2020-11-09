#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int V;
    list<int>* adj;
    int* in;

    Graph(int V);
    ~Graph() {delete [] adj; delete [] in;}

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool isEulerianCycle();

    bool isSC();

    void DFSUtil(int v, bool visited[]);

    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    in = new int[V];
    for (int i = 0; i < V; i++)
    {
        in[i] = 0;
    }
}

bool Graph::isEulerianCycle()
{
    if (!isSC()) return false;
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() != in[i]) return false;
    }
    return true;
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i]) DFSUtil(*i, visited);
    }
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            g.adj[*i].push_back(v);
            (g.in[v])++;
        }
    }
    return g;
}

bool Graph::isSC()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    int j;
    for (j = 0; j < V; j++)
    {
        if (adj[j].size() > 0) break;
    }
    DFSUtil(j, visited);
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() > 0 && !visited[i]) return false;
    }
    Graph gr = getTranspose();
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    gr.DFSUtil(j, visited);
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() > 0 && !visited[i]) return false;
    }
    return true;
}

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 0); 
  
    if (g.isEulerianCycle()) 
       cout << "Given directed graph is eulerian n"; 
    else
       cout << "Given directed graph is NOT eulerian n"; 
    return 0; 
} 