const int INF = 0x3f3f3f3f;
// Use priority queue to track [yi-xi,xi]
// and traversre the array
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>> pq;
        int ans = -INF;
        for (int i = 0; i < n; i++)
        {
            while (!pq.empty() && points[i][0] - pq.top().second > k) pq.pop();
            if (!pq.empty())
            {
                ans = max(ans, points[i][0] + points[i][1] + pq.top().first);
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        return ans;
    }
};