using ll = long long;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size();
        deque<int> dq;
        int ans = INF;
        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
        for (int i = 0; i < n + 1; i++)
        {
            while (!dq.empty() && sum[i] - sum[dq.front()] >= k)
            {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && sum[dq.back()] >= sum[i]) dq.pop_back();
            dq.push_back(i);
        }
        return ans == INF ? -1 : ans;
    }
};