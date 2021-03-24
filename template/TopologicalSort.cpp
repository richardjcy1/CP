#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    vector<vector<int>> g;
    int V;
    
    Graph(int V);
    void addEdge(int u, int v);
    vector<int> TopologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    g.resize(V, vector<int>());
}

void Graph::addEdge(int u, int v)
{
    g[u].push_back(v);
}

vector<int> Graph::TopologicalSort()
{
    vector<int> inDegree(V);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        for (int nei: g[i]) inDegree[nei]++; 
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (!inDegree[i]) q.push(i);
    }
    int cnt = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        ++cnt;
        ans.push_back(cur);
        for (int nei: g[cur])
        {
            if (!--inDegree[nei]) q.push(nei);
        }
    }
    return cnt == V ? ans : vector<int>();
}


