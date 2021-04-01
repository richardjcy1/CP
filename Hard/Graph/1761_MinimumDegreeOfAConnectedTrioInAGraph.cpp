const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>(n));
        vector<int> degree(n);
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            --u; --v;
            g[u][v] = g[v][u] = 1;
            degree[u]++;
            degree[v]++;
        }
        int ans = INF;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (g[i][j] && g[j][k] && g[k][i])
                    {
                        ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                    }
                }
            }
        }
        return ans == INF ? -1 : ans;
    }
};