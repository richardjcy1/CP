#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef pair<int, int> iPair;

struct Graph
{
    int V;
    vector<vector<iPair>> adj;
    
    Graph(int V);
    void addEdge(int u, int v, int w);
    int primMST();
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

int Graph::primMST()
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    int src = 0, ans = 0;
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!inMST[i])
        {
            pq.push(make_pair(0, i));
            key[i] = 0;
            while (!pq.empty())
            {
                int u = pq.top().second;
                int w = pq.top().first;
                pq.pop();
                
                if (!inMST[u]) ans += w;
                inMST[u] = true;
                for (auto i = adj[u].begin(); i != adj[u].end(); i++)
                {
                    int v = (*i).first;
                    int weight = (*i).second;
                    if (!inMST[v] && key[v] > weight)
                    {
                        key[v] = weight;
                        pq.push(make_pair(key[v], v));
                        parent[v] = u;
                    }
                }
            }
        }
    }
    
    // for (int i = 1; i < V; i++)
    // {
    //     printf("%d - %d\n", parent[i], i);
    // }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int kase = 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> b(n, vector<int>(n));
        Graph graph(2 * n);
        ll tot = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) 
            {
                cin >> b[i][j];
                if (a[i][j] == -1)
                {
                    graph.addEdge(i, j + n, -b[i][j]);
                    tot += b[i][j];
                }
            }
        }
        vector<int> r(n);
        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> r[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        cout << "Case #" << ++kase << ": " << tot + graph.primMST() << '\n';
    }
    return 0;
}