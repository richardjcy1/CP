// Use min heap (priority_queue) to track least sum
// then update by incrementing column by 1 and record visited columns
// Time complexity: O(k*mnlogmn)
// Space complexity: O(mn)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        auto cmp = [&](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b)
        {
            return a.first > b.first;
        };
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(cmp)> pq(cmp);
        int tot = 0;
        for (int i = 0; i < m; i++)
        {
            tot += mat[i][0];
        }
        vector<int> a;
        for (int i = 0; i < m; i++) a.push_back(0);
        pq.push(make_pair(tot, a));
        set<vector<int>> vis;
        vis.insert(a);
        while (--k)
        {
            auto tmp = pq.top(); pq.pop();
            int sum = tmp.first;
            auto arr = tmp.second;
            for (int i = 0; i < m; i++)
            {
                if (arr[i] + 1 < n)
                {
                    arr[i]++;
                    if (vis.find(arr) == vis.end())
                    {
                        vis.insert(arr);
                        pq.push({sum + mat[i][arr[i]] - mat[i][arr[i] - 1], arr});
                    }
                    arr[i]--;
                }
            }
        }
        return pq.top().first;
    }
};