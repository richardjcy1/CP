typedef long long ll;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        const auto cmp = [&](const pair<ll, ll>& x, const pair<ll, ll>& y)
        {
            return arr[x.first] * arr[y.second] > arr[y.first] * arr[x.second];
        };
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> pq(cmp);
        for (int i = 1; i < n; i++) pq.push({0, i});
        while (--k)
        {
            auto p = pq.top(); pq.pop();
            if (p.first + 1 < p.second) pq.push({p.first + 1, p.second});
        }
        return {arr[pq.top().first], arr[pq.top().second]};
    }
};