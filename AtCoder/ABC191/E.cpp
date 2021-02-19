#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n, m;
ll ans;

int solve(vector<vector<pair<int, int>>>& a, int s)
{
    int n = a.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> d(n, INF);
    d[s] = 0;
    pq.push({d[s], s});
    bool first = true;
    while (!pq.empty())
    {
        auto tmp = pq.top(); pq.pop();
        int dd = tmp.first;
        int u = tmp.second;
        if (dd != d[u]) continue;
        if (u == s)
        {
            if (first)
            {
                first = false;
                d[u] = INF;
            }
            else return dd;
        }
        for (auto& p: a[u])
        {
            auto v = p.first;
            auto w = p.second;
            if (d[v] > dd + w)
            {
                d[v] = dd + w;
                pq.push({d[v], v});
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    vector<vector<pair<int, int>>> a(n);
    for (int i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        --x; --y;
        a[x].push_back({y, z});
        
    }
    for (int i = 0; i < n; i++)
    {
        ans = solve(a, i);
        cout << ans << endl;
    }
    return 0;
}