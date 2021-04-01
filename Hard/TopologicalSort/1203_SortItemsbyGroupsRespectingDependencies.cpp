class Solution {
public:
    vector<vector<int>> g;
    vector<int> inDegreeGroup;
    vector<int> inDegreeItem;
    vector<vector<int>> graph;
    vector<vector<int>> graphgroup;
    
    vector<int> sortItems(int n, int m, vector<int>& a, vector<vector<int>>& b) {
        int cur = m;
        for (int i: a)
        {
            if (i == -1) ++cur;
        }
        inDegreeGroup = vector<int>(cur);
        inDegreeItem = vector<int>(n);
        g = vector<vector<int>>(cur, vector<int>()); // group number -> group elements
        graph = vector<vector<int>>(n, vector<int>()); // inside a group, element -> neighbor elements
        graphgroup = vector<vector<int>>(cur, vector<int>()); // one group -> neighbor groups
        cur = m;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1)
            {
                a[i] = cur;
                g[cur++].push_back(i);
            }
            else g[a[i]].push_back(i);
        }
        int totgroup = 0;
        for (int i = 0; i < g.size(); i++)
        {
            if (g.size() > 0) ++totgroup;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j: b[i])
            {
                if (a[i] == a[j] && a[i] != -1)
                {
                    inDegreeItem[i]++;
                    graph[j].push_back(i);
                }
                else
                {
                    inDegreeGroup[a[i]]++;
                    graphgroup[a[j]].push_back(a[i]);
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < inDegreeGroup.size(); i++)
        {
            if (inDegreeGroup[i] == 0) q.push(i);
        }
        vector<int> ans;
        int cntgroup = 0;
        while (!q.empty())
        {
            auto tmp = q.front(); q.pop();
            ++cntgroup;
            int sz = g[tmp].size();
            queue<int> itemq;
            for (int i: g[tmp])
            {
                if (inDegreeItem[i] == 0) itemq.push(i);
            }
            int cnt = 0;
            while (!itemq.empty())
            {
                auto itemtmp = itemq.front(); itemq.pop();
                ++cnt;
                ans.push_back(itemtmp);
                for (int nei: graph[itemtmp])
                {
                    inDegreeItem[nei]--;
                    if (inDegreeItem[nei] == 0) itemq.push(nei);
                }
            }
            if (cnt != sz) return {};
            for (int nei: graphgroup[tmp])
            {
                inDegreeGroup[nei]--;
                if (inDegreeGroup[nei] == 0) q.push(nei);
            }
        }
        if (cntgroup < totgroup) return {};
        return ans;
    }
};