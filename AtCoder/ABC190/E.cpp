#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

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

typedef pair<int, int> iPair;

struct Graph
{
    int V;

    list<pair<int, int>>* adj;

    Graph(int V);

    void addEdge(int u, int v, int w);

    vector<int> shortestPath(int s);
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

vector<int> Graph::shortestPath(int src)
{
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // printf("Vertex Distance from source\n");
    // for (int i = 0; i < V; i++)
    // {
    //     printf("%d \t\t %d\n", i, dist[i]);
    // }
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    //vector<vector<ll>> g(n + 1, vector<ll>());
    Graph g(n);
    DisjointSets dj(n);
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        --x; --y;
        //g[x].push_back(y);
        //g[y].push_back(x);
        g.addEdge(x, y, 1);
        dj.uni(x, y);
    }
    ll k;
    cin >> k;
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < k; i++) 
    {
        ll x;
        cin >> x;
        --x;
        mp[x] = i;
    }
    unordered_set<ll> st;
    for (auto& p: mp)
    {
        st.insert(dj.fi(p.first));
    }
    if ((int)st.size() > 1) cout << -1 << endl;
    else
    {
        vector<vector<ll>> cost(k, vector<ll>(k));
        for (auto& p: mp)
        {
            int src = p.first;
            auto v = g.shortestPath(src);
            for (auto& q: mp)
            {
                cost[p.second][q.second] = v[q.first];
            }
        }
        vector<vector<ll>> dp(k, vector<ll>(1 << k, INF));
        for (ll i = 0; i < k; i++) dp[i][1 << i] = 1;
        for (ll mask = 0; mask < 1 << k; mask++)
        {
            for (ll i = 0; i < k; i++)
            {
                if (!(mask & 1 << i)) continue;
                for (ll j = 0; j < k; j++)
                {
                    if (i != j && (mask & 1 << j))
                    {
                        dp[i][mask] = min(dp[i][mask], dp[j][mask - (1 << i)] + cost[j][i]);
                    }
                }
            }
        }
        ll ans = INF;
        for (ll i = 0; i < k; i++) ans = min(ans, dp[i][(1 << k) - 1]);
        cout << ans << endl;
    }
    return 0;
}