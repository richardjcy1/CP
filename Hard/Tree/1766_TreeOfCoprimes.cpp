class Solution {
public:
    vector<vector<int>> g;
    vector<int> ans;
    vector<int> a;
    vector<int> vis;
    int n;
    
    void dfs(int node, vector<int>& prev)
    {
        vis[node] = 1;
        int m = prev.size();
        for (int i = m - 1; ~i; i--)
        {
            if (__gcd(a[prev[i]], a[node]) == 1)
            {
                ans[node] = prev[i];
                break;
            }
        }
        if (g[node].size() == 1 && vis[g[node][0]]) return;
        int idx = -1;
        int val;
        for (int i = 0; i < m; i++)
        {
            if (a[prev[i]] == a[node])
            {
                idx = i;
                val = prev[i];
                break;
            }
        }
        if (idx != -1)
        {
            prev.erase(prev.begin() + idx);
            prev.push_back(node);
        }
        else prev.push_back(node);
        for (int nei: g[node])
        {
            if (!vis[nei])
            {
                vis[nei] = 1;
                dfs(nei, prev);
            }
        }
        if (idx != -1)
        {
            prev.insert(prev.begin() + idx, val);
        }
        prev.pop_back();
    }
    
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        a = nums;
        n = nums.size();
        g = vector<vector<int>>(n, vector<int>());
        for (auto& e: edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        ans = vector<int>(n, -1);
        vis = vector<int>(n);
        vector<int> prev;
        dfs(0, prev);
        return ans;
    }
};