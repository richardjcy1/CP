/*
*	author:		richardjcy
*	created:	2020/09/20/22:06.46
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Graph
{
    int V;
    list<pair<int, int>>* adj;
    int DFSUtil(int v, bool visited[]);
    
    Graph(int V);
    ~Graph() {delete [] adj;}
    void addEdge(int u, int v, int w);
    void DFS(int src);
    unordered_map<int, int> mp;
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int>>[V];
    mp = {};
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

int Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    bool ok = false;
    int ans = 0;
    // cout << v << " ";
    list<pair<int, int>>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[(*i).first])
        {
            ok = true;
            int tmp = DFSUtil((*i).first, visited);
            mp[(*i).second] += tmp;
            ans += tmp;
        }
    }
    if (!ok)
    {
        return 1;
    }
    return ans;
}

void Graph::DFS(int src)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    DFSUtil(0, visited);
}

struct CMP
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return (ll)(a.first - a.first / 2) * (ll)a.second < (ll)(b.first - b.first / 2) * (ll)b.second;
    }
};

struct Edge
{
    int u, v, w;
    Edge(int x, int y, int z): u(x), v(y), w(z) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll s;
        cin >> n >> s;
        Graph g(n);
        vector<Edge> edges;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            edges.push_back(Edge(u, v, w));
            g.addEdge(u, v, i);
        }
        g.DFS(0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, CMP> pq;
        ll total = 0;
        for (auto p: g.mp)
        {
            total += (ll)edges[p.first].w * p.second;
            pq.push(make_pair(edges[p.first].w, p.second));
            // cout << edges[p.first].w << " " << p.second << endl;
        }
        // cout << total << endl;
        int ans = 0;
        while (total > s)
        {
            ++ans;
            auto x = pq.top(); pq.pop();
            // cout << x.first << " " << x.second;
            total -= (ll)(x.first - x.first / 2) * x.second;
            // cout << " " << total << endl;
            pq.push(make_pair(x.first / 2, x.second));
        }
        cout << ans << endl;
    }
    return 0;
}