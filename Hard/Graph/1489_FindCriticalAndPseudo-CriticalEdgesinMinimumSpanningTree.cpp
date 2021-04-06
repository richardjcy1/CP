// first build MST using kruskal algorithm
// then try removing each edge and building MST
// if cannot or total cost greater, this edge is critical edge
// then check pseudo-critical by first adding this edge and building MST
// check total cost equal
// Time compelxity: O(m^2logm)
// Space complexity: O(m)
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

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            edges[i].push_back(i);
        }
        DisjointSets dj(n);
        int mi = 0;
        sort(edges.begin(), edges.end(), [&](const vector<int>& a, const vector<int>& b)
             {
                 return a[2] < b[2];
             });
        for (int i = 0; i < m; i++)
        {
            if (dj.uni(edges[i][0], edges[i][1]))
            {
                mi += edges[i][2];
            }
        }
        vector<vector<int>> ans(2, vector<int>());
        for (int i = 0; i < m; i++)
        {
            DisjointSets tmp(n);
            int v = 0;
            for (int j = 0; j < m; j++)
            {
                if (i != j && tmp.uni(edges[j][0], edges[j][1]))
                {
                    v += edges[j][2];
                }
            }
            if (tmp.setCount > 1 || v > mi)
            {
                ans[0].push_back(edges[i][3]);
                continue;
            }
            
            DisjointSets tmp2(n);
            tmp2.uni(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for (int j = 0; j < m; j++)
            {
                if (i != j && tmp2.uni(edges[j][0], edges[j][1]))
                {
                    v += edges[j][2];
                }
            }
            if (v == mi)
            {
                ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};