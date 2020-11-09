#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// #define INF 0x3f3f3f3f

const int maxn = 1e3 + 5;
typedef pair<int, int> iPair;
vector<vector<int>> g;
int tot = 0;

struct Graph
{
    int V;

    list<pair<int, int>>* adj;

    Graph(int V);

    void addEdge(int u, int v, int w);

    void shortestPath(int s, int t);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src, int target)
{
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    vector<int> dist(V + 1, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    vector<int> p(V + 1);
    p[src] = -1;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // list<pair<int, int>>::iterator i;
        for (int i = 1; i != V; i++)
        {
            if (i != u && g[u][i] != INF)
            {
                int v = i;
                int weight = g[u][v];
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    p[v] = u;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }

    // printf("Vertex Distance from source\n");
    // for (int i = 0; i < V; i++)
    // {
    //     printf("%d \t\t %d\n", i, dist[i]);
    // }
    while (target != src)
    {
        int x = min(p[target], target), y = max(p[target], target);
        tot += g[x][y];
        target = p[target];
    } 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    Graph graph(n + 1);
    g = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        // graph.addEdge(x, y, w);
        g[x][y] = w;
        g[y][x] = w;
    }
    int ans = INF;
    vector<pair<int, int>> route;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        route.push_back(make_pair(a, b));
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (g[i][j] != INF)
            {
                int tmp = g[i][j];
                g[i][j] = 0;
                g[j][i] = 0;
                tot = 0;
                for (auto p: route)
                {
                    // cout << p.first << " " << p.second << endl;
                    graph.shortestPath(p.first, p.second);
                    // cout << tot << endl;
                }
                ans = min(ans, tot);
                g[i][j] = tmp;
                g[j][i] = tmp;
            }
        }
    }
                
    cout << ans << endl;
    return 0;
}