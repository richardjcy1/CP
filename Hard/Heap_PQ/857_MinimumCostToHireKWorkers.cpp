// sort by w[i]/q[i] in ascending order
// use a max heap to track max quality of traversed workers
// update the total sum
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int K) {
        int n = q.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) v.push_back({q[i], w[i]});
        sort(v.begin(), v.end(), [&](const pair<int, int>& x, const pair<int, int>& y)
             {
                 return x.second / (x.first + 0.0) < y.second / (y.first + 0.0);
             });
        int sum = 0;
        double unit = 0.0;
        const auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y)
             {
                 return x.first < y.first;
             };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        double ans = DBL_MAX;
        for (int i = 0; i < n; i++)
        {
            pq.push(v[i]);
            sum += v[i].first;
            if (pq.size() > K)
            {
                sum -= pq.top().first;
                pq.pop();
            }
            if (pq.size() == K)
            {
                ans = min(ans, v[i].second / (v[i].first + 0.0) * sum);
            }
        }
        return ans;
    }
};