#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int V;
    list<int>* adj;
    void DFSUtil(int v, bool visited[]);

    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    void connectedComponents();
};

void Graph::connectedComponents()
{
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
    {
        visited[v] = false;
    }
    for (int v = 0; v < V; v++)
    {
        if (!visited[v])
        {
            DFSUtil(v, visited);
            cout << endl;
        }
    }
    delete[] visited;
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
        {
            DFSUtil(*i, visited);
        }
    }
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph()
{
    delete [] adj;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(5); // 5 vertices numbered from 0 to 4
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Following are connected components \n";
    g.connectedComponents();

    return 0;
}

