#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int V;
    list<int>* adj;

    void BFSUtil(int v, bool visited[]);

    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    ~Graph() {delete [] adj;}

    void addEdge(int v, int w);

    bool isSC();

    Graph getTranspose();
};

void Graph::BFSUtil(int v, bool visited[])
{
    list<int> queue;
    visited[v] = true;
    queue.push_back(v);

    list<int>::iterator i;
    while (!queue.empty())
    {
        v = queue.front();
        queue.pop_front();
        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
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
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::isSC()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    BFSUtil(0, visited);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) return false;
    }
    Graph gr = getTranspose();
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    gr.BFSUtil(0, visited);
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
    g1.isSC()? cout << "Yes\n" : cout << "No\n";

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.isSC()? cout << "Yes\n" : cout << "No\n";

    return 0;
}










