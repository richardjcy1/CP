const int INF = 0x3f3f3f3f;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
        for (auto& e: edges)
        {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        map<int, int> dist;
        dist[0] = 0;
        for (int i = 1; i < n; i++) dist[i] = maxMoves + 1;
        map<pair<int, int>, int> used;
        int ans = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto tmp = pq.top(); pq.pop();
            int d = tmp.first, node = tmp.second;
            if (d > dist[node]) continue;
            ++ans;
            for (auto& p: g[node])
            {
                int nei = p.first, w = p.second;
                used[{node, nei}] = min(maxMoves - d, w);
                int d2 = d + w + 1;
                if (d2 < min(dist[nei], maxMoves + 1))
                {
                    pq.push({d2, nei});
                    dist[nei] = d2;
                }
            }
        }
        for (auto& e: edges)
        {
            int x = e[0], y = e[1];
            ans += min(e[2], used[{x, y}] + used[{y, x}]);
        }
        return ans;
    }
};